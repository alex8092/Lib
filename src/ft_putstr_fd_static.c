#include "ft_common.h"

void	ft_putstr_fd_static(char *str, int fd, size_t n)
{
	write(fd, str, n);
}
