#include "21sh.h"

void	print_args(char **args)
{
	int i;

	i = -1;
	while (args[++i])
		ft_putendl(args[i]);
}

void	print_3d_args(char ***args)
{
	int i;

	i = -1;
	while (args[++i])
		print_args(args[i]);
}
