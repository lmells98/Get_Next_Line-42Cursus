#include "get_next_line.h"

void	*ft_calloc(size_t n_memb, size_t size)
{
	char			*ch_p;
	unsigned int	i;
	size_t			bytes;

	i = 0;
	bytes = n_memb * size;
	ch_p = (char *)malloc(bytes);
	if (ch_p == NULL)
		return (0);
	while (i < bytes)
	{
		ch_p[i] = 0;
		i++;
	}
	return (ch_p);
}

char	*get_next_line(int fd)
{
	int			pos;
	int			rd_bytes;
	char		*buf;
	static char *saved;

	if (BUFFER_SIZE == 0 || fd < 0 || fd > 10240)
	{	
		printf("ERROR! Failed Initial Check.\n");
		return (NULL);
	}
	buf = NULL;
	pos = ft_strchr(saved, '\n', 0);
	printf("pos = %i\n", pos);
/*	Loops Through the Entire File unless you flag *
 *	ft_strchr to find the new line char */
	while (pos == -1 && pos != -5)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buf)
		{	
			printf("ERROR! Failed Memory Allocation.\n");
			return (NULL);
		}
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1 || rd_bytes == 0)
		{
			printf("ERROR! No Bytes were read by Read.\n");
			return (NULL);
		}
		debug_info(fd, buf, BUFFER_SIZE, rd_bytes);
		utils_debug(fd, buf, rd_bytes);
		break ;
	}
	return (ft_strndup(buf, ft_strchr(buf, '\n', 0)));
}
