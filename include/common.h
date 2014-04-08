#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memalloc(size_t n);

int		ft_findinarray(char *array, char c);
#endif
