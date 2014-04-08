#include "common.h"

int	ft_findinarray(char *array, char c)
{
	int	index;

	index = 0;
	while (array[index])
	{
		if (array[index] == c)
			return (index);
	}
	return (-1);
}
