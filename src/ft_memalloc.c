#include "ft_common.h"
#include <stdlib.h>

void	*ft_memalloc(size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(n);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		++i;
	}
	return ((void *)ptr);
}
