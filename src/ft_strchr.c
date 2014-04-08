#include "common.h"
#include <stdlib.h>

#define MAGIC ((0x7efefefeL << 16) << 16) | 0xfefefeffL

char *ft_strchr (const char *s, int cc)
{
	unsigned char	c;

	c = (unsigned char)cc;
	while (*s && *s != c)
		++s;
	if (*s == c)
		return ((char *)s);
	return NULL;
}
