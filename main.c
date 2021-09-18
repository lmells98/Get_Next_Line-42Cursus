#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;

	fd = open("./text.txt", O_RDONLY);
	if (fd < 0 || fd > 10240)
	{
		printf("ERROR! Failed to open file.");
		return (0);
	}
	for (i = 1; i <= 12; i++)
	{
		printf("%i:	%s", i, get_next_line(fd));
	}
	return (0);
}
