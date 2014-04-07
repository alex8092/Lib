#include "common.h"
#include <stdlib.h>
#include <time.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

clock_t	begin;

void	begin_test()
{
	begin = clock();
}

clock_t	end_test()
{
	return clock() - begin;
}

void	performing_strchr(void)
{
	char	*str;
	int		i;

	str = malloc(100000);
	for (i = 0; i < 100000;++i)
		str[i] = (i == 60000) ? 'B':'A';
	str[i] = 0;
	begin_test();
	for (i = 0; i < 100000; ++i)
		strchr(str, 'B');
	printf("strchr : %ld\n", end_test());
	begin_test();
	for (i = 0; i < 100000; ++i)
		ft_strchr(str, 'B');
	printf("ft_strchr : %ld\n", end_test());
	free(str);
}

int	main(void)
{
	performing_strchr();
	return (0);
}
