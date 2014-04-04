#include "common.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = (char)c;
	i = 0;
	while (s[i] && s[i] != cc)
		++i;
	if (s[i] == cc)
		return ((char *)(s + i));
	return (NULL);
}
