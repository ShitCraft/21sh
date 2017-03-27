#include "21sh.h"

int	get_termsize(void)
{
	int size;

	size = tgetnum("co");
	return (size);
}

void	create_input(void)
{
	g_input = (t_input *)malloc(sizeof(t_input));
	g_input->len = 0;
	g_input->pos = 0;
	g_input->row = 0;
	g_input->line = ft_strnew(0);
}

void	refresh_input(void)
{
	free(g_input->line);
	g_input->len = 0;
	g_input->pos = 0;
	g_input->row = 0;
	g_input->line = ft_strnew(0);
}

void	switch_input(char **line)
{
	free(g_input->line);
	g_input->line = *line;
	g_input->len = ft_strlen(*line);
	g_input->pos = g_input->len;
	g_input->row = (g_input->len + getcwd_len()) / get_termsize();
}
