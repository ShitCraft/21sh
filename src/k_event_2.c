#include "21sh.h"

void	kcu_event(void)
{
	int size;
	int cwd_len;

	size = get_termsize();
	cwd_len = getcwd_len();
	if ((g_input->pos) >= size)
	{
		tputs(tgetstr("up", NULL), 0, myputchar);
		g_input->pos = g_input->pos - size;
	}
}

void	kcd_event(void)
{
	int size;
	int cwd_len;

	size = tgetnum("co");
	cwd_len = getcwd_len();
	if (g_input->len < size)
		tputs(tgetstr("do", NULL), 0, myputchar);
	ft_putnbr(size);
}

void	kcr_event(void)
{
	int i;
	int j;

	i = g_input->pos + 1;
	j = g_input->pos - 1;
	while (ft_issign(g_input->line[i]) && g_input->line[i])
		i++;
	while (!ft_issign(g_input->line[i]) && g_input->line[i])
		i++;
	while (++j < i)
		tputs(tgetstr("nd", NULL), 0, myputchar);
	g_input->pos = j;
}

void	kcl_event(void)
{
	int i;
	int j;

	i = g_input->pos - 1;
	j = g_input->pos + 1;
	while (ft_issign(g_input->line[i]) && i > 0)
		i--;
	while (!ft_issign(g_input->line[i]) && i > 0)
		i--;
	while (--j > i)
		tputs(tgetstr("le", NULL), 0, myputchar);
	g_input->pos = j;
}
