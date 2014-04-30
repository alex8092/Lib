#include "ft_common.h"
#include <stdlib.h>
#include <stdint.h>

static const char	*ft_strchr_bis(const char *cp)
{
	if (!cp[0])
		return (cp);
	else if (!cp[1])
		return (cp + 1);
	else if (!cp[2])
		return (cp + 2);
	else if (!cp[3])
		return (cp + 3);
	else if (!cp[4])
		return (cp + 4);
	else if (!cp[5])
		return (cp + 5);
	else if (!cp[6])
		return (cp + 6);
	else
		return (cp + 7);
}

static char			*align(const char *str, const char c)
{
	const char	*tmp;

	tmp = str;
	while (((uint64_t)tmp & (sizeof(uint64_t) - 1)) != 0)
	{
		if (*tmp == c)
			return ((char *)tmp);
		else if (!*tmp)
			return ((char *)str);
		++tmp;
	}
	return ((char *)tmp);
}

char				*ft_strchr(const char *str, int c)
{
	uint64_t	*s;
	const char	ch = (const char)c;
	uint64_t	magic;
	char		*test;
	const uint64_t	himagic = ((0x80808080L << 16) << 16) | 0x80808080L;
	const uint64_t	lomagic = ((0x01010101L << 16) << 16) | 0x01010101L;

	if ((test = align(str, ch)) != str && *test == ch)
		return (test);
	else if (test == str && !test)
		return (NULL);
	magic = ch | (ch << 8) | (ch << 16) | (ch << 24);
	magic = ~(((magic << 16) << 16) | magic);
	s = (uint64_t *)test;
	while (42)
	{
		if (((~(*s++ ^ magic)) - lomagic) & himagic)
			return ((char *)ft_strchr_bis((const char *)(s - 1)));
		else if ((*(s - 1) - lomagic) & himagic)
			return (NULL);
	}
	return NULL;
}
