#include "21sh.h"

void	kr_event(void)
{	
	int pos_in_row;

	if (check_pos(1))
	{
		if (check_endoffline())
			move_to_next_line();
		else
		{
			tputs(tgetstr("nd", NULL), 0, myputchar);
			g_input->pos += 1;
		}
	}
}

void	kl_event(void)
{
	int pos_in_row;
	int i;

	i = 0;
	if (check_pos(0))
	{	
		if (g_input->row)
		{
			pos_in_row = g_input->pos + getcwd_len() - (get_termsize() *g_input->row);
			if (pos_in_row == (2 * g_input->row))
				move_to_pre_line();
			else
			{
				tputs(tgetstr("le", NULL), 0, myputchar);
				g_input->pos -= 1;
			}
		}
		else
		{
			tputs(tgetstr("le", NULL), 0, myputchar);
			g_input->pos -= 1;
		}
	}
}

void	bell_event(void)
{
	tputs(tgetstr("bl", NULL), 0, myputchar);
}

void	output_event(char ch)
{
	if (g_input->pos == g_input->len)
	{
		write(1, &ch, 1);
		add_char_to_line(ch);
		make_newline();
	}
	else
		insert_char(ch);
}

void	sp_event(void)
{
	if (g_input->pos == g_input->len)
	{
		write(1, " ", 1);
		add_char_to_line(' ');
		make_newline();
	}
	else
		insert_char(' ');
}
