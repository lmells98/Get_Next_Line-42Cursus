#include "get_next_line.h"

//TODO	ADD FT_STRNDUP FUNCTION - DUPLICATE N_BYTES OF A STRING PASSED THROUGH
char	*ft_strndup(const char *s, unsigned int size)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && i <= size)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strchr(char *str, int c, int flag)
{
	int	i;

	if (flag == 1 && !str)
		return (-5);
	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
