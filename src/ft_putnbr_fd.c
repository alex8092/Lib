#include "ft_common.h"

static void	ft_putnbr_rec(unsigned long int n, int fd)
{
	char	c;

	if (n)
	{
		c = (n % 10) + '0';
		ft_putnbr_rec(n / 10, fd);
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(long int number, int fd)
{
	if (number == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (number < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_rec(-number, fd);
	}
	else
		ft_putnbr_rec(number, fd);
}
