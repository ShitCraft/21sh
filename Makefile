# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 13:12:30 by oskrypka          #+#    #+#              #
#    Updated: 2017/03/27 14:58:25 by oskrypka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	21sh

SRC	=	main.c args_param.c builtings.c \
		cwd.c builtings_1.c read_line.c builtings_2.c \
		env.c env_1.c dir.c cd.c echo.c line.c \
		error.c lavrovii.c getpath.c sh_pipes_handler.c \
		addit.c split_args.c dispatcher.c sh_built_redir.c \
		getchr.c k_event.c k_event_1.c input_oper.c \
		input_oper_1.c k_event_2.c remove_curr_line.c \
		input.c k_event_3.c k_event_4.c args_checkers.c \
		sh_launch.c move_index.c sh_launch_redir.c \
		check_redir_params.c sh_launch_pipes.c \
		sigint_handler.c

SRCLIB	=	libft/ft_isascii.c libft/ft_issign.c \
		libft/ft_strchr.c libft/ft_strlen.c \
		libft/ft_strrchr.c libft/ft_atoi.c \
		libft/ft_isdigit.c libft/ft_memcpy.c \
		libft/ft_strcmp.c libft/ft_strncat.c \
		libft/ft_strstr.c libft/ft_bzero.c \
		libft/ft_isprint.c libft/ft_memmove.c \
		libft/ft_strcpy.c libft/ft_strncmp.c \
		libft/ft_tolower.c libft/ft_isalnum.c \
		libft/ft_memchr.c libft/ft_memset.c \
		libft/ft_strdup.c libft/ft_strncpy.c \
		libft/ft_toupper.c libft/ft_isalpha.c \
		libft/ft_memcmp.c libft/ft_strcat.c \
		libft/ft_strlcat.c libft/ft_strnstr.c \
		libft/ft_memalloc.c libft/ft_memdel.c \
		libft/ft_strnew.c libft/ft_strdel.c \
		libft/ft_strclr.c libft/ft_striter.c \
		libft/ft_striteri.c libft/ft_strmap.c \
		libft/ft_strmapi.c libft/ft_strequ.c \
		libft/ft_strnequ.c libft/ft_strsub.c \
		libft/ft_strjoin.c libft/ft_strtrim.c \
		libft/ft_strsplit.c libft/ft_putnbr_fd.c \
		libft/ft_itoa.c libft/ft_putchar.c \
		libft/ft_putstr.c libft/ft_putendl.c \
		libft/ft_putchar_fd.c libft/ft_putnbr.c \
		libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
		libft/ft_lstnew.c libft/ft_lstdelone.c \
		libft/ft_lstdel.c libft/ft_lstadd.c \
		libft/ft_lstiter.c libft/ft_lstmap.c

OBJECTS	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJECTS +=	$(addprefix $(OBJDIR), $(SRCLIB:.c=.o))

CC	=	gcc 
CFLAGS	=	-Wall -Wextra -Werror

SRCDIR	= ./src/
OBJDIR	= ./obj/
LOBJDIR = ./obj/libft/
INCDIR	= ./includes/

all: obj $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(LOBJDIR)
	@printf "\x1b[33mAssembling:\x1b[0m"

$(NAME): $(OBJECTS)
	@$(CC) -o $(NAME) $(OBJECTS) -ltermcap
	@echo "\n\x1b[32mAssembled!\x1b[0m"

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFALGS) -I $(INCDIR) -o $@ -c $<
	@printf "."

$(OBJDIR)%.o:$(LIBDIR)%.c
	@$(CC) $(CFALGS) -I $(INCDIR) -o $@ -c $<
	@printf "."

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
