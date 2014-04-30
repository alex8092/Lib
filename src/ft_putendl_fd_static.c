#include "ft_common.h"

void	ft_putendl_fd_static(char *str, int fd, size_t n)
{
	write(fd, str, n);
	write(fd, "\n", 1);
}
