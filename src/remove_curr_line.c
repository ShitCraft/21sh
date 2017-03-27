#include "21sh.h"

void	remove_curr_line(void)
{
	tputs(tgetstr("dl", NULL), 0, myputchar);
	tputs(tgetstr("cr", NULL), 0, myputchar);
	print_curr_dir(environ);
}
