#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			pos;
	int			rd_bytes;
	int			len;
	char		*buffer;

	if (BUFFER_SIZE == 0 || fd < 0 || fd > 10240)
		return (NULL);
	buffer = NULL;
	rd_bytes = read(fd, buffer, BUFFER_SIZE);
	pos = ft_strchr(buffer, '\n');
	len = ft_strlen(buffer);
	return (buffer);
}
