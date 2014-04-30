#include "ft_common.h"
#include <stdlib.h>

char		*ft_itoa(long int nbr)
{
	char		neg;
	char		*str;
	long int	n;
	int			i;

	if (nbr == 0)
		return ("0");
	n = 1;
	i = 0;
	neg = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? nbr * -1 : nbr;
	while (n <= nbr && ++i)
		n *= 10;
	if ((str = malloc(sizeof(char) * i + 1)) != NULL)
	{
		str[0] = '-';
		i = neg;
		while (n > 1)
		{
			str[i++] = (nbr % n / (n / 10)) + 48;
			n /= 10;
		}
		str[i] = 0;
	}
	return (str);
}