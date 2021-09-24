#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd;

	fd = open("./bonus/get_next_line_bonus.c", O_RDONLY);
	if (fd > 0)
	{
		int	i;
		printf("---------\nBONUS TEST...\n");
		for (i = 1; i <= 2; i++)
		{
			printf("%i:\t%s", i, get_next_line(fd));
		}
	}
	else
		printf("Error! Something went wrong...\n");
	return (0);
}
