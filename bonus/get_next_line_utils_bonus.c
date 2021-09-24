#include "get_next_line_bonus.h"

void	ft_free(char **pointer)
{
	free(*pointer);
	*pointer = NULL;
}

int	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str && str[len])
		len++;
	return (len);
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

char	*ft_strndup(const char *s1, unsigned int size)
{
	char			*dup;
	unsigned int	i;

	if (!s1)
		return (NULL);
	dup = (char *)malloc(size + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i] && i < size)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strnjoin(char *s1, char *s2, unsigned int size)
{
	char			*output;
	unsigned int	i;
	unsigned int	j;

	if (s2 == NULL)
		return (NULL);
	output = (char *)malloc(ft_strlen(s1) + size + 1);
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			output[i] = s1[i];
			i++;
		}
	}
	while ((s2 && s2[j] != '\0') && j < size)
		output[i++] = s2[j++];
	output[i] = '\0';
	if (s1)
		ft_free(&s1);
	return (output);
}
