#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd;

	fd = open("./bonus/get_next_line_bonus.c", O_RDONLY);
	if (fd > 0)
	{
		int	i;
		printf("!!!BONUS TEST!!!\n");
		printf("---------\nTEST FILE 1...\n");
		printf("fd = %i\nPrint 3 Lines\n---------\n", fd);
		for (i = 1; i <= 3; i++)
		{
			printf("%i:\t%s", i, get_next_line(fd));
		}
		printf("---------\nTEST FILE 2...\n");
		fd = open("./text.txt", O_RDONLY);
		printf("fd = %i\nPrint 5 Lines\n---------\n", fd);
		for (i = 1; i <= 5; i++)
		{
			printf("%i:\t%s", i, get_next_line(fd));
		}
		printf("---------\nTEST FILE 1 AGAIN...\n");
		fd = 3;
		printf("fd = %i\nPrint Next 4 Lines\n---------\n", fd);
		for (i = 4; i <= 7; i++)
		{
			printf("%i:\t%s", i, get_next_line(fd));
		}
		printf("---------\nTEST FILE 3...\n");
		fd = open("./bonus/get_next_line_utils_bonus.c", O_RDONLY);
		printf("fd = %i\nPrint 2 Lines\n---------\n", fd);
		for (i = 1; i <= 2; i++)
		{
			printf("%i:\t%s", i, get_next_line(fd));
		}
		printf("---------\nTEST FILE 2 AGAIN...\n");
		fd = 4;
		printf("fd = %i\nPrint Next 7 Lines\n---------\n", fd);
		for (i = 6; i <= 12; i++)
		{
			printf("%i:\t%s", i, get_next_line(fd));
		}
		printf("---------\nTEST FILE 1 AGAIN...\n");
		fd = 3;
		printf("fd = %i\nPrint Next 6 Lines\n---------\n", fd);
		for (i = 8; i <= 13; i++)
		{
			printf("%i:\t%s", i, get_next_line(fd));
		}
	}
	else
		printf("Error! Something went wrong...\n");
	return (0);
}
