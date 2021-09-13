#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer[BUFFER_SIZE + 1];
	static char	*save;
	size_t		len;
	int			rd_bytes;

	rd_bytes = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE < 0 || rd_bytes == -1)
		return (NULL);
}
