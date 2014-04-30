#include "ft_common.h"

long int	ft_atoi(char *number)
{
	unsigned long int	res;
	char				neg;

	neg = (number[0] == '-') ? -1 : 1;
	if (number[0] == '-')
		++number;
	res = 0;
	while (*number)
	{
		res *= 10;
		res += *number - '0';
		++number;
	}
	return (res * neg);
}
