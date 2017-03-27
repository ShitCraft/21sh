#include "libft.h"

int	ft_issign(int c)
{
	if (c >= 32 && c <= 47)
		return (1);
	else if (c >= 58 && c <= 64)
		return (1);
	else if (c >= 91 && c <= 96)
		return (1);
	else if (c >= 124 && c <= 126)
		return (1);
	return (0);
}
