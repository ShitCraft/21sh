#include "21sh.h"

int	redir_func(char *func_name)
{
	if (!ft_strcmp(func_name, "pwd") || !ft_strcmp(func_name, "env")
		|| !ft_strcmp(func_name, "setenv"))
		return (1);
	return (0);
}

int	sh_built_redir(char **args, char *stream)
{
	int fd;
	int std_out;

	fd = open(stream, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	std_out = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (std_out);
}
