#include "get_next_line.h"

int	main(void)
{
	int		fd;

	fd = open("./text.txt", O_RDONLY);
	if (fd < 0 || fd > 10240)
	{
		printf("ERROR! Failed to open file.");
		return (0);
	}
	printf("\"%s\"\n", get_next_line(fd));
	return (0);
}
