#include "get_next_line_bonus.h"

void	ft_free(char **pointer)
{
	free(&pointer);
	*pointer = NULL;
}

int	ft_strchr(char *str, int c, int flag)
{
	int	i;

	if (flag == 1 && !str)
		return (-5);
	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
