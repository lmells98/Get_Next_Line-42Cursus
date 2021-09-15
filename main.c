#include "get_next_line.h"

int main(void)
{
	int	fd;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	printf("fd = %i\n", fd);
	if (fd >= 0)
	{
		printf("SUCCESSFULL READ\n");
		res = get_next_line(fd);
		if (res)
		{
			printf("SUCCESSFUL PASS THROUGH FUNCTION\n");
			printf("buffer = %s\n", res);
		}
		else
		{
			printf("FILE WAS NOT READ BY GET NEXT LINE\n");
			return (0);
		}
	}
	return (0);
}
