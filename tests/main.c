#include "ft_common.h"
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

char	*ft_strchr2(char *str, int c)
{
	const char ch = c;

	while (*str && *str != ch)
		++str;
	if (*str == ch)
		return (str);
	return (NULL);
}

void	performing_strchr(void)
{
	char	*str;
	char	*str2;
	int		i;

	str = malloc(10000000);
	str2 = malloc(10000000);
	for (i = 0; i < 100000;++i)
	{
		str[i] = (i == 60000) ? 'B':'A';
		str2[i] = (i == 60000) ? 'D':'E';
	}
	str[i] = 0;
	str2[i] = 0;
	ft_memcpy(str2, str, 10000);
	if (!strcmp(str, str2))
		printf("%s\n\n%s\n", str, str2);
	begin_test();
	for (i = 0; i < 100000; ++i)
		strchr(str, 'B');
	printf("strchr : %ld\n", end_test());
	begin_test();
	for (i = 0; i < 100000; ++i)
		ft_strchr(str, 'B');
	printf("ft_strchr : %ld\n", end_test());
	begin_test();
	for (i = 0; i < 100000; ++i)
		ft_strchr2(str, 'B');
	printf("ft_strchr2 : %ld\n", end_test());
	free(str);
}

int	main(void)
{
	performing_strchr();
	return (0);
}
