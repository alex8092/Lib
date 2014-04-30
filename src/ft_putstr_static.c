#include "ft_common.h"

void	ft_putstr_static(char *str, size_t n)
{
	write(1, str, n);
}
