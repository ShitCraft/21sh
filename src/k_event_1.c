#include "21sh.h"

void	kr_event(void)
{	
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

	if (check_pos(0))
	{	
		if (g_input->row)
		{
			pos_in_row = (getcwd_len() + g_input->pos) % get_termsize();
			if (!pos_in_row)
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
		if (check_endoffline())
			move_to_next_line();
			
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
		if (check_endoffline())
			move_to_next_line();
	}
	else
		insert_char(' ');
}
