#include "21sh.h"

void	move_to_pre_line(void)
{
	int i;

	tputs(tgetstr("up", NULL), 0, myputchar);
	i = 0;
	while (++i != (get_termsize() * g_input->row))
		tputs(tgetstr("nd", NULL), 0, myputchar);
	g_input->row--;
	g_input->pos -= 2;
}

int		kctrd_event(void)
{
	write(1, "\n", 1);
	if (!g_input->len)
		exit(0);
	return (10);
}
