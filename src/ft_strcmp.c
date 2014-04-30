#include "ft_common.h"
#include <stdint.h>

static size_t	ft_cmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return (s2[i] - s1[i]);
}

size_t			ft_strcmp(const char *s1, const char *s2)
{
	const uint64_t	himagic = ((0x80808080L << 16) << 16) | 0x80808080L;
	const uint64_t	lomagic = ((0x01010101L << 16) << 16) | 0x01010101L;
	const uint64_t	*i1;
	const uint64_t	*i2;
	
	i1 = (const uint64_t *)s1;
	i2 = (const uint64_t *)s2;
	while (42)
	{
		if (((*i1++ - lomagic) & himagic))
			return (ft_cmp((const char *)(i1 - 1), (const char *)(i2)));
		else if (((*i2++ - lomagic) & himagic) || *(i1 - 1) != *(i2 - 1))
			return (ft_cmp((const char *)(i1 - 1), (const char *)(i2 - 1)));
	}
}
