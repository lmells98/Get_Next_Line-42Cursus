#include "get_next_line.h"

//TODO	ADD FT_STRNDUP FUNCTION - DUPLICATE N_BYTES OF A STRING PASSED THROUGH
char	*ft_strndup(const char *s, unsigned int size);

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strchr(const char *str, const char c)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}
