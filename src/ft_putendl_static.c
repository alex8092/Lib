#include "ft_common.h"

void	ft_putendl_static(char *str, size_t n)
{
	write(1, str, n);
	write(1, "\n", 1);
}
