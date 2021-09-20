#include "get_next_line_bonus.h"

void	*ft_calloc(size_t n_memb, size_t size)
{
	char			*ch_p;
	size_t			bytes;
	unsigned int	i;

	bytes = n_memb * size;
	ch_p = (char *)malloc(bytes);
	i = 0;
	if (ch_p == NULL)
		return (0);
	while (i < bytes)
	{
		ch_p[i] = 0;
		i++;
	}
	printf("Pointer=%s\n", ch_p);
	return (ch_p);
}

char	*get_next_line(int fd)
{
	static char	*saved[10240];
	char		*buf;
	int			pos;
	int			rd_bytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 10240)
		return (NULL);
	buf = NULL;
	pos = ft_strchr(saved[fd], '\n', 0);
	while (pos == -1 && pos != -5)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, 1);
		if (buf == NULL)
			return (NULL);
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == 0 || rd_bytes == -1)
			return (NULL);
		saved[fd] = ft_strnjoin(saved[fd], buf, rd_bytes);
		pos = ft_strchr(saved[fd], '\n', 1);
	}
	printf("--------\nbuf=%s\n--------\n", buf);
	printf("--------\nsaved=%s\n--------\n", saved[fd]);
	printf("pos=%i\n-------\nbytes=%i\n---------\n", pos, rd_bytes);
	ft_free(&buf);
	return (buf);
}
