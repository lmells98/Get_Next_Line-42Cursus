/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:59:42 by lmells            #+#    #+#             */
/*   Updated: 2021/09/20 10:59:42 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **pointer)
{
	free(*pointer);
	*pointer = NULL;
}

/*	TODO	ADD FT_STRNDUP FUNCTION 
**	DUPLICATE N_BYTES OF A STRING PASSED THROUGH */
char	*ft_strndup(const char *s, unsigned int size)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strlen(char *s)
{
	int		len;

	len = 0;
	if (!s)
		return (0);
	while (s && s[len])
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

/*	TODO	Add ft_strnjoin FUNCTION TO JOIN THE EXISTING
**	STRING TO THE NEW LINE IN BUFFER */
char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s2[j] == '\0')
		return (NULL);
	join = (char *)malloc(ft_strlen(s1) + n + 1);
	if (!join)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			join[i] = s1[i];
			i++;
		}
	}
	while (s2 && s2[j] != '\0' && j < n)
		join[i++] = s2[j++];
	join[i] = '\0';
	if (s1)
		ft_free(&s1);
	return (join);
}
