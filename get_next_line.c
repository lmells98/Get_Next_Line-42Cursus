#include "get_next_line.h"

char	*ft_find_new_line(char **save)
{
	char	*temp;
	char	*start_save;
	int		nb_lines;

	start_save = *save;
	nb_lines = ft_strchr(*save, '\n');
	temp = ft_substr(*save, 0, nb_lines + 1);
	while (nb_lines-- >= 0)
		*save++;
	if (*save[0] != '\0')
		*save = ft_strdup(*save);
	else
		*save = NULL;
	free(start_save);
	start_save = NULL;
	return (temp);
}

char	*ft_previously_saved(char **save)
{
	char	*temp;

	if (ft_strchr(*save, '\n') >= 0)
		return (ft_find_new_line(&(*save)));
	temp = *save;
	*save = NULL;
	free(*save);
	return (temp);
}

char	*ft_check_new_line(char **save, int fd)
{
	if (ft_strchr(*save, '\n') >= 0)
		return (ft_find_new_line(&(*save)));
	return (ft_get_next_line(fd));
}

char	*ft_get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	static char	*save;
	int			rd_bytes;

	rd_bytes = read(fd, buffer, BUFFER_SIZE);
	if (BUFFER_SIZE < 1 || fd < 0 || rd_bytes == -1)
		return (NULL);
	buffer[rd_bytes] = '\0';
	if (rd_bytes < 1)
	{
		if (save)
			return (ft_previously_saved(&(save)));
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
	return (ft_check_new_line(&(save), fd));
}
