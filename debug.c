#include "get_next_line.h"

int		ft_ternary(int condition, long val1, long val2)
{
	if (condition)
		return (val1);
	else
		return (val2);
}

void	debug_len(char *str)
{
	if (ft_ternary(ft_strlen(""), 1, 0) == 0)
	{
		printf("Testing ft_strlen\n");	
		printf("----------------------------\n");
		if (ft_strlen(str) > 0)
			printf("len = %i\nSUCCESS!!!\n", (int)ft_strlen(str));
		else
			printf("ERROR! SOMETHING WENT WRONG...\n");
		printf("----------------------------\n");
	}
	else
	{
		printf("ERROR! Check Failed...\n");
		printf("----------------------------\n");
	}
}

int		debug_strchr(char *str, char c, int flag)
{
	int	pos;
	char	init[5] = "init\n";
	if (ft_ternary((ft_strchr(init, c, 0) > 0), 1, 0) == 1)
	{
		printf("Testing ft_strchr\n");
		printf("----------------------------\n");
		if ((pos = ft_strchr(str, c, flag)))
			printf("new line position = %i\nSUCCESS!!!\n", pos);
		else
			printf("ERROR! SOMETHING WENT WRONG...\n");
		printf("----------------------------\n");
	}
	else
	{
		printf("ERROR! Check Failed...\n");
		printf("----------------------------\n");
	}
	return (pos);
}

void	debug_strndup(char *src, unsigned int size)
{
	char	*dup;

	if ((ft_strndup(src, 0)) != NULL)
	{
		printf("Testing ft_strndup\n");
		printf("----------------------------\n");
		if ((dup = ft_strndup(src, size)) != NULL)
		{
			printf("Duplicate =\n%s\n", dup);
			printf("Length	  = %i\n", (int)ft_strlen(dup));
			if (((int)ft_strlen(dup)) == (int)size)
				printf("SUCCESS!!!\n");
			else
				printf("ERROR! SOMETHING WENT WRONG...\n");
			printf("----------------------------\n");
		}
		else
		{
			printf("ERROR! Check Failed...\n");
			printf("----------------------------\n");
		}
	}
}

void	debug_strnjoin(char *s1, char *s2, int n)
{
	char	*join;
	
	join = NULL;
	printf("Testing ft_strnjoin\n");
	printf("----------------------------\n");
	if ((join = ft_strnjoin(s1, s2, n)) != NULL)
	{	
		printf("Output String:\n%s\n", join);
		printf("----------------------------\n");
	}
	else
	{
		printf("ERROR! Failed Check...\n");
		printf("----------------------------\n");
	}
}

void	utils_debug(int fd, char *buf, int rd_bytes, char *saved)
{
	printf("UTILIITY DEBUG\n");
	printf("----------------------------\n");

	int			pos;
	static char	*join_test;
	  
	if ((fd > 0 && fd < 10240) && buf != NULL && rd_bytes >= 0)
	{
		debug_len(buf);
		pos = debug_strchr(buf, '\n', 1);
		debug_strndup(buf, pos);
		join_test = NULL;
		if (*join_test)
		{
			join_test = ft_strndup(saved, ft_strlen(saved));
			debug_strnjoin(join_test, buf, rd_bytes);
		}
	}
	else
		printf("ERROR! Failed Check...\n");
}
 
void    debug_info(int fd, char *buf, int buf_size, int rd_bytes, char *saved)
{
	if (!(BUFFER_SIZE > 0 || rd_bytes > 0 || fd >= 0 || fd <= 10240))
	{
		printf("ERROR 1. Falied to Read File\n");
		return ;
	}
	else if (!buf)
	{
		printf("ERROR 2. NOTHING IN BUFFER.\n");
		return ;
	}
	printf("----------------------------\n");
	printf("SUCCESSFULLY READ FILE INFO\n");
	printf("----------------------------\n");
	printf("FD\t\t= %i\nBUFFER_SIZE\t= %i\nBytes Read\t= %i\n", fd, buf_size, rd_bytes);
	printf("Buffer\t\t= \n%s\n", buf);
	printf("Saved\t\t=\n%s\n", saved);
	printf("----------------------------\n");
}
