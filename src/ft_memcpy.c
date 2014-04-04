#include "common.h"
#include <stdint.h>

static void	cpy(char *dest, const char *src, size_t n)
{
	const uint64_t	*s;
	uint64_t		*d;
	size_t			i;

	s = (const uint64_t *)src;
	d = (uint64_t *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	int			i;

	s = (const char *)src;
	d = (char *)dest;
	cpy(d, s, n / sizeof(uint64_t));
	i = n - (n % sizeof(uint64_t));
	while (s[i])
	{
		d[i] = s[i];
		++i;
	}
	return (dest);
}
