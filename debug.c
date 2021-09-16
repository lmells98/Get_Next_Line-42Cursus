#include "get_next_line.h"

void	utils_debug(int fd, char *buf, int bytes)
{
	char    *dup;
	ssize_t len;
	int     pos;
	  
	if ((fd > 0 || fd < 10240) && buf != NULL && bytes >= 0)
	{
		printf("Testing ft_strlen\n");
		if ((len = ft_strlen(buf)) > 0)
			printf("len = %i\nSUCCESS!!!\n", (int)len);
		else
			printf("ERROR! SOMETHING WENT WRONG...\n");
		printf("----------------------------\n");
		printf("Testing ft_strchr\n");
		if ((pos = ft_strchr(buf, '\n', 0)))
			printf("new line position = %i\nSUCCESS!!!\n", pos);
		else
			printf("ERROR! SOMETHING WENT WRONG...\n");
		printf("----------------------------\n");
		printf("Testing ft_strndup\n");
		if ((dup = ft_strndup(buf, pos)) != NULL)
		{
			printf("Duplicate = \"\"\n\"%s\"\n", dup);
			printf("Duplicate len = %i\n", (int)ft_strlen(dup));
			printf("Should be pos + 1 for Null Byte.\n");
			if (((int)ft_strlen(dup)) == pos + 1)
				printf("SUCCESS!!!\n");
			else
				printf("ERROR! SOMETHING WENT WRONG...\n");
		}
		else
			printf("ERROR! SOMETHING WENT WRONG...\n");
		printf("----------------------------\n");
	}
	else
		printf("ERROR! Failed Initial Check For Debug.\n");
}
 
void    debug_info(int fd, char *buf, int buf_size, int bytes)
{
	if (!(BUFFER_SIZE > 0 || bytes > 0 || fd >= 0 || fd <= 10240))
	{
		printf("ERROR 1.\n");
		return ;
	}
	else if (!buf)
	{
		printf("ERROR 2. NOTHING IN BUFFER.\n");
		return ;
	}
	printf("----------------------------\n");
	printf("FD\t\t= %i\nBUFFER_SIZE\t= %i\nBytes Read\t= %i\n", fd, buf_size, bytes);
	printf("Buffer\t\t= \"\"\n\"%s\"\n", buf);
	printf("\nSUCCESSFULLY READ FILE INFO\n");
	printf("----------------------------\n");
}
