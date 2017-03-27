/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:01:00 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/26 12:07:15 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <pwd.h>

# define Q(x) (x == '"')
# define MAXLINE 1024

enum	e_builtings
{
	CD,
	HELP,
	EXIT,
	ENV,
	ECHO,
	SETENV,
	UNSETENV,
	BUILT_NUM
};

typedef int	(*t_builtin)(char **args, char ***env);

void		read_line(int fd, char **line);
int			get_2d_array_len(char **arr);
int			check_line(char *line);
char		**create_empty_line(void);

char		*get_value(char *var);
char		**get_env(char *envp[]);
char		*get_path(char *name, char **env);
char		*getvar(char **env, char *name);
char		*get_abs_path(char *fold, char *name);
char		*get_prev_dir(char **env);
char		*add_cwd(char *dir);

char		*get_dir(char *path, char **env);
void		cd_error(char *dir);
void		cd_prev_dir(char ***env);
void		cd_home_dir(char ***env);

void		change_old_dir(char ***env, char *dir);
void		add_envvar(char ***env, char *key, char *value);
void		rewr_envvar(char ***env, int i, char *value);
void		unset_envvar(char ***env, int i, char *value);

void		sh_loop(char *envp[]);
int			sh_exec(char **args, char ***env, char **arg);

void		launch_error(char *prog);

void		ft_putstr_wq(char *str);
void		handle_line(char **line);
char		**parse_var(char *var);
void		check_env(char *arg, char ***env);
void		echo(char **args, char ***env);
void		wfl_echo(char **args, char ***env);

void		add_null(char **args);
void		free_args(char **args);

int			sh_cd(char **args, char ***env);
int			sh_help(char **args, char ***env);
int			sh_exit(char **args, char ***env);
int			sh_env(char **args, char ***env);
int			sh_echo(char **args, char ***env);
int			sh_setenv(char **args, char ***env);
int			sh_unsetenv(char **args, char ***env);

void		launch_builtin_func(char **args, int i, char ***env);
char		**get_func_names(void);

void		print_curr_dir(char **env);
char		*handle_cwd(char *cwd, char **env);
char		*get_user_dir(char **env);
char		*after_user_dir(char *cwd, char *user_dir);

int		redir_func(char *func_name);
int		sh_built_redir(char **args, char *stream);

#endif
