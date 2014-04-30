#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>

# define GNL_BUFSIZE 1024

size_t		ft_strlen(const char *s);
size_t		ft_strcmp(const char *s1, const char *s2);

char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, char *src, size_t n);
char		*ft_strstr(char *str, const char *find);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strnjoin(const char *s1, size_t len1, const char *s2,
				size_t len2);

char		**ft_strsplit(char *str, char c);

void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memalloc(size_t n);
void		*ft_memset(void *ptr, int c, size_t n);
void		*ft_memdup(const void *src, size_t n);

void		ft_bzero(void *ptr, size_t n);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putstr_fd_static(char *str, int fd, size_t n);
void		ft_putstr(char *str);
void		ft_putstr_static(char *str, size_t n);
void		ft_putendl(char *str);
void		ft_putendl_static(char *str, size_t n);
void		ft_putendl_fd(char *str, int fd);
void		ft_putendl_fd_static(char *str, int fd, size_t n);
void		ft_putnbr(long int number);
void		ft_putnbr_fd(long int number, int fd);

int			ft_findinarray(char *array, char c);
int			ft_getnextline(int fd, char **line);

long int	ft_atoi(char *number);

#endif