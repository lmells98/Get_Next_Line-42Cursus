#include "get_next_line.h"

int	main(void)
{
	int 	fd;
	int		bytes;
	char	*buf;

	fd = open("./text.txt", O_RDONLY);
	if (BUFFER_SIZE < 0)
	{
		printf("INVALID BUFFER SIZE\n");
		return (0);
	}
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		printf("ERROR. FAILED MALLOC");
		return (0);
	}
	bytes = read(fd, buf, BUFFER_SIZE);
	if (!bytes || !buf)
	{
		printf("ERROR READING FILE FROM FD.\nfd=%i\tbuf=%s\n", fd, buf);
	}
	debug_info(fd, buf, BUFFER_SIZE, bytes);
	utils_debug(fd, buf, bytes);
}
