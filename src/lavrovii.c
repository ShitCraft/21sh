#include "21sh.h"

void		move_through_list_up(t_lavrovii **list)
{
	char *tmp;

	if (!*list)
		return ;
	if ((*list)->pre)
	{
		remove_curr_line();
		*list = (*list)->pre;
		ft_putstr((*list)->command);
		tmp = ft_strdup((*list)->command);
		switch_input(&tmp);
	}
	else
		bell_event();
}

void		move_through_list_down(t_lavrovii **list)
{
	char *tmp;
	
	if (!*list)
		return ;
	if ((*list)->next)
	{
		remove_curr_line();
		*list = (*list)->next;
		ft_putstr((*list)->command);
		tmp = ft_strdup((*list)->command);
		switch_input(&tmp);
	}
	else
		remove_curr_line();
}

void		print_list(t_lavrovii **list)
{
	t_lavrovii *curr;
	t_lavrovii *start;

	start = *list;
	curr = *list;
	while (curr)
	{
		ft_putendl(curr->command);
		curr = curr->pre;
	}
}

void		add_command_to_list(t_lavrovii **list, char *command)
{
	t_lavrovii *elem;

	if (!ft_strlen(command))
		return ;	
	if (!*list)
		elem = create_new_elem(command, 0);
	else
		elem = create_new_elem(command, 1);
	add_elem_to_list(list, elem);
}

void		add_elem_to_list(t_lavrovii **list, t_lavrovii *elem)
{
	t_lavrovii *curr;
	char	*tmp;

	if (!*list)
	{
		*list = elem;
		*list = (*list)->next;
	}
	else
	{
		curr = *list;
		while (curr->next)
			curr = curr->next;
		curr->next = elem;
		elem->pre = curr;
		tmp = curr->command;
		curr->command = elem->command;
		elem->command = tmp;
		curr = elem;
		*list = curr;
	}
}

t_lavrovii	*create_next_elem(t_lavrovii *elem)
{
	t_lavrovii *next;

	next = (t_lavrovii *)malloc(sizeof(t_lavrovii));
	next->command = ft_strnew(0);
	next->next = NULL;
	next->pre = elem;
	return (next);
}

t_lavrovii	*create_new_elem(char *command, int flag)
{
	t_lavrovii *elem;

	elem = (t_lavrovii *)malloc(sizeof(t_lavrovii));
	elem->command = ft_strdup(command);
	if (!flag)
		elem->next = create_next_elem(elem);
	else
		elem->next = NULL;
	elem->pre = NULL;
	return (elem);
}
