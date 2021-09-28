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
	return (ch_p);
}

char	*ft_update_newline(char **saved, int pos)
{
	char	*new_line;
	size_t	len;

	len = (size_t)ft_strlen(*saved) - (size_t)pos;
	new_line = ft_strndup(*saved + pos, len);
	ft_free(&*saved);
	*saved = new_line;
	return (*saved);
}

char	*ft_output_line(char **saved, int pos, int rd_bytes)
{
	char	*output;

	if (((rd_bytes == 0 || rd_bytes == -1) && !*saved) || pos == -5)
	{
		if (*saved)
			return (*saved);
		return (NULL);
	}
	output = NULL;
	if (pos == -1)
		pos = ft_strlen(*saved);
	else
		pos++;
	output = ft_strndup(*saved, pos);
	if (pos == ft_strlen(*saved))
		ft_free(&*saved);
	else
		*saved = ft_update_newline(&*saved, pos);
	return (output);
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
			break ;
		saved[fd] = ft_strnjoin(saved[fd], buf, rd_bytes);
		pos = ft_strchr(saved[fd], '\n', 1);
		ft_free(&buf);
	}
	ft_free(&buf);
	return (ft_output_line(&saved[fd], pos, rd_bytes));
}
