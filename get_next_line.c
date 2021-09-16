#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			pos;
	int			rd_bytes;
	char		*buf;
	static char	*saved;

	if (BUFFER_SIZE == 0 || fd < 0 || fd > 10240)
		return (NULL);
	buf = NULL;
	pos = ft_strchr(saved, '\n', 0);
	while (pos == -1 && pos != -5)
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (NULL);
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1 || rd_bytes == 0)
			return ;
		utils_debug(fd, line, rd_bytes);
	}
	return (NULL);
}
