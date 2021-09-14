#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			pos;
	int			rd_bytes;
	int			len;
	char		*buffer;
	static char	*saved;

	if (BUFFER_SIZE == 0 || fd < 0 || fd > 10240)
		return (NULL);
	buffer = NULL;
	rd_bytes = read(fd, buffer, BUFFER_SIZE);
	pos = ft_strchr(buffer, '\n');
	len = ft_strlen(buffer);
	printf("---------------------------\n");
	printf("|	   Read Bytes = %i	  |\n", rd_bytes);
	printf("---------------------------\n");
	printf("|  len = %i  |  pos = %i  |\n", len, pos);
	printf("---------------------------\n");
	printf("|  Buffer = %s\n", buffer);
	printf("						  |\n");
	saved = ft_strndup(buffer, pos);
	printf("---------------------------\n");
	return (saved);
}
