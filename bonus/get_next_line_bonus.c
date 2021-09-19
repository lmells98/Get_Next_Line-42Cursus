#include "get_next_line_bonus.h"

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
	rd_bytes = read(fd, buf, BUFFER_SIZE);
	printf("--------\nbuf=%s\n--------\n", buf);
	printf("pos=%i\n-------\nbytes=%i\n---------\n", pos, rd_bytes);
	return (0);
}
