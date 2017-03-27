#include "21sh.h"

int		check_in_or_out_redir(char **args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], ">"))
			return (1);
	}
	return (0);
}

int		check_redir_params_in(char **args, int flag)
{
	int aux;

	aux = 1;
	if (!flag)
	{
		if (!args[aux] || !args[aux + 1] || !args[aux + 2])
		{
			launch_args_error();
			return (0);
		}
	}
	if (flag)
	{
		if (ft_strcmp(args[aux + 1], ">"))
		{
			launch_input_file_exp(args[aux + 1]);
			return (0);
		}
	}
	return (1);
}

int		check_redir_params_out(char **args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], ">"))
			break;
	}
	if (!args[i + 1])
	{
		output_file_expected_error();
		return (0);
	}
	return (1);
}

void	fileIO(char **args, char **files, int option, char **env)
{
	int	fd;
	pid_t	pid;
	char	*path;

	if ((pid = fork()) == -1)
		ft_putendl_fd("redir fork error", 2);
	else if (!pid)
	{
		if (!option)
		{
			fd = open(files[1], O_CREAT | O_TRUNC | O_WRONLY, 0600);
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		else if (option == 1)
		{
			fd = open(files[0], O_RDONLY, 0600);
			dup2(fd, STDIN_FILENO);
			close(fd);
			fd = open(files[1], O_CREAT | O_TRUNC | O_WRONLY, 0600);
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		path = get_path(args[0], env);
		if (!path)
			path = args[0];
		if (execve(path, args, env) == -1)
		{
			launch_error(args[0]);
			exit(0);
		}
	}
	waitpid(pid, NULL, 0);
}
