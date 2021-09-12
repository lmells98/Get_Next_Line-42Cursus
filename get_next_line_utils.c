#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int		ft_strchr(const char *s, const char c)
{
	int	count;

	count = 0;
	while (*s != '\0' && *s != c)
	{
		if (*s == c)
			return (count);
		count++;
		s++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		join[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		join[j] = s2[i];
		i++;
		j++;
	}
	join[j] = '\0';
	return (join);
}

char	*ft_substr(const char *s, unsigned int start, size_t size)
{
	char	*sub;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (size > len)
		sub = (char *)malloc((len + 1) * sizeof(char));
	else
		sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	if (start < (unsigned int)len)
	{
		while (s[start + i] && i < size)
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
