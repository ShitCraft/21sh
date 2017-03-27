/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:42:47 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/27 15:29:45 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _21SH_H
# define _21SH_H

# include "minishell.h"
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <term.h>
# include <fcntl.h>
# include <termcap.h>

# define ESC "\033"
# define K_UP "\033[A"
# define K_D "\033[B"
# define K_R "\033[C"
# define K_L "\033[D"
# define CL "\033[2K"
# define DEL "\033[3~"
# define K_CR "\033[1;5C"
# define K_CL "\033[1;5D"
# define K_CU "\033[1;5A"
# define K_CD "\033[1;5B"
# define K_EN "\033[1;2C"
# define K_HO "\033[1;2D"

# define READ 0
# define WRITE 1
# define OUT 0
# define IN 1

typedef	struct			s_lavrovii
{
	char				*command;
	struct s_lavrovii 	*next;
	struct s_lavrovii 	*pre;
}						t_lavrovii;

typedef struct			s_input
{
	char				*line;
	int					len;
	int					pos;
	int					tab_count;
	int					row;
}						t_input;

extern char 			**environ;
struct termios			g_orig;
int						g_ttyfd;
t_lavrovii				*g_list;
t_input					*g_input;
pid_t					g_pid;

void					print_list(t_lavrovii **list);

void					init(void);
void					sigint_handler(int sig);

int						get_entry(void);
int						myputchar(int ch);
int						get_termsize(void);
int						getcwd_len(void);
void					change_tty_params(void);
void					tty_reset(void);
void					input_handler(void);
void					tty_raw(void);
char					get_chr(void);
void					handle_input(void);
char					handle_buf(char *buf);
char					*handle_command(char *command);

void			create_input(void);
void			refresh_input(void);
void			switch_input(char **line);

void			delete_char_in_line(void);
void			insert_char_in_line(char *offset, char ch);
void			add_char_to_line(char ch);
char 			*get_offset(void);
void			insert_char(char ch);
void			remove_one_char(void);
int				check_pos(int direction);

void			kup_event(void);
void			kd_event(void);
void			kr_event(void);
void			kl_event(void);
void			bell_event(void);
void			bs_event(void);
void			cl_event(void);
void			sp_event(void);
void			output_event(char ch);
void			kcr_event(void);
void			kcl_event(void);
void			kcd_event(void);
void			kcu_event(void);
void			khome_event(void);
void			kend_event(void);
int				kctrd_event(void);

void			move_to_pre_line(void);
void			move_to_next_line(void);
int				check_endoffline(void);
void			make_newline(void);
void			remove_curr_line();
void			move_through_list_up(t_lavrovii **list);
void			move_through_list_down(t_lavrovii **list);
void			add_command_to_list(t_lavrovii **list, char *command);
void			add_elem_to_list(t_lavrovii **list, t_lavrovii *elem);
t_lavrovii		*create_new_elem(char *command, int flag);
t_lavrovii		*create_next_elem(t_lavrovii *elem);

void			print_args(char **args);
void			print_3d_args(char ***args);

void			input_file_expected_error(char *arg);
void			input_args_error(void);
void			output_file_expected_error(void);
void			parse_error(void);

int				check_in_or_out_redir(char **args);
int				check_redir_params_in(char **args, int flag);
int				check_redir_params_out(char **args);
int				check_args_for_redirs(char **args);
char			***split_args(char **line);
char			**copy_args(char **args);
char			**get_memory_for_args(char **pipe_args, int i);
int				get_cmds_num(char **pipe_args);
int				get_size_before_redir(char **args);

void			dispatcher(char **args, char ***env);
void			sh_launch(char **args, char ***env);

void			sh_launch_builtin(char **args, int builtin, char ***env);
int				check_args_for_builtings(char **args);

void			sh_pipes_handler(char **pipe_args, char ***env);
void			sh_launch_pipes(char ***args, char ***env);
char			***get_comands(char **pipe_args, int cmds_num);
char			**get_one_pipe_args(char **pipe_args, int i);
int				check_args_for_pipes(char **args);
void			handle_one_pipe(int fd_in, int **pipe, char ***args, int i);
void			sh_exec_cmd(char **args, char ***env);
void			handle_args(char **args, char ***env);

void			handle_redirs_proc(char **args, char ***env);
void			sh_launch_redir(char **args, char ***env);
void			do_redir_shit(char **args, int flag, char ***env);
char			*get_redir_file(char **args);
char			**get_args_before_redir(char **args);

void			parse_redir_params(char ***args, char ***files);
int				define_option(char **args);

void			free_3d_array_args(char ***args);

#endif
