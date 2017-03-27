#include "21sh.h"

void	khome_event(void)
{

	if (!g_input->row)
	{
		while (g_input->pos)
			kl_event();
	}
}

void	kend_event(void)
{
	if (!g_input->row)
	{
		while (g_input->pos != g_input->len)
			kr_event();
	}
}

void	make_newline(void)
{
	if ((g_input->pos + getcwd_len()) == get_termsize())
	{
		g_input->row++;
		add_char_to_line('\n');
		add_char_to_line('\r');
		write(1, "\n\r", 2);
	}
}

int	check_endoffline(void)
{
	if (!g_input->row)
	{
		if ((g_input->pos + getcwd_len()) == get_termsize())
			return (1);
	}
	if ((g_input->pos + getcwd_len())== ((g_input->row * 2) + get_termsize()))
			return (1);
	return (0);
}

void	move_to_next_line(void)
{
	tputs(tgetstr("do", NULL), 0, myputchar);
	g_input->pos += 3;
	g_input->row += 1;
}
