#include "ft_common.h"
#include <stdlib.h>

static ssize_t	last_ret(int set, ssize_t ret)
{
	static ssize_t	sret = 0;

	if (set)
		sret = ret;
	return (sret);
}

static int	get_line(char **buffer, char *find, char **line, size_t *bufsize)
{
	const size_t	len = find - *buffer;

	if (*buffer && find)
	{
		*line = ft_strndup(*buffer, len);
		if (*bufsize - len != 0)
		{
			ft_memcpy(*buffer, find + 1, *bufsize - len - 1);
			*bufsize -= len + 1;
			(*buffer)[*bufsize] = 0;
		}
		else
			*bufsize = 0;
		if (!*bufsize)
		{
			free(*buffer);
			*buffer = NULL;
		}
	}
	return ((len || *bufsize || last_ret(0, 0)) ? 1 : 0);
}

static void	merge(char **buffer, char *buf, ssize_t ret, size_t *bufsize)
{
	char	*ptr;

	ptr = *buffer;
	if (ptr)
	{
		*buffer = ft_strnjoin(ptr, *bufsize, buf, ret);
		*bufsize += ret;
	}
	else
	{
		*buffer = ft_strndup(buf, ret);
		*bufsize = ret;
	}
	free(ptr);
}

static char	*ft_find(char *buffer, size_t bufsize)
{
	static size_t	offset = 0;
	char			*find;

	if (buffer && (find = ft_strchr(buffer + offset, '\n')))
	{
		offset = 0;
		return (find);
	}
	offset += bufsize - offset;
	return (NULL);
}

int			ft_getnextline(int fd, char **line)
{
	static char		*buffer = NULL;
	static size_t	bsize = 0;
	char			buf[GNL_BUFSIZE + 1];
	char			*find;
	ssize_t			ret;

	while (1)
	{
		if ((find = ft_find(buffer, bsize)))
			return (get_line(&buffer, find, line, &bsize));
		if ((ret = read(fd, buf, GNL_BUFSIZE)) == 0 && buffer)
		{
			last_ret(1, 0);
			return (get_line(&buffer, buffer + ft_strlen(buffer), line, &bsize));
		}
		else if (!ret)
			return (0);
		else if (ret > 0)
		{
			last_ret(1, ret);
			buf[ret] = 0;
			merge(&buffer, buf, ret, &bsize);
		}
		else
			return (-1);
	}
}
