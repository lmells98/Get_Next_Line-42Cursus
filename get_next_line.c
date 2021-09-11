#include "get_next_line.h"

char	*find_new_line(char **save_line)
{
	char	*temp;
	char	*start_save_line;
	int		nb_lines;

	nb_lines = ft_strchr(*save_line, '\n');
	temp = ft_substr(*save_line, 0, nb_lines + 1);
	while (nb_lines-- > 0)
		*(save_line)++;
	if (*save_line[0] != '\0')
		return (ft_strdup(*save_line));
	else
		*save_line = NULL;
	free(start_save_line);
	start_save_line = NULL;
	return (temp);
}

char	*previously_saved(char **save_line)
{
	char	*temp;
	if (ft_strchr(*save_line, '\n') >= 0)
		return (find_new_line(&(*save_line)));
	temp = *save_line;
	*save_line = NULL;
	free(*save_line);
	return (temp);
}

char	*ft_get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	static char	*save;
	size_t		rd_bytes;

	rd_bytes = read(fd, buffer, BUFFER_SIZE);
	if (BUFFER_SIZE < 1 || fd < 0 || rd_bytes == -1)
		return (NULL);
	buffer[rd_bytes] = '\0';
	if (rd_bytes < 1)
	{
		if (save)
			return (previously_saved(&(save)));
		return (NULL);
	}
	if (!save)
		save = ft_strdup(buffer);
	else
	{
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (check_new_line(&(save), fd));
}
