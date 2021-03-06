/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:59:42 by lmells            #+#    #+#             */
/*   Updated: 2021/09/20 13:11:42 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_get_next_line.h"

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
/*	TODO	add handles for updating the new line
**			& if saved is empty!!
*/
char	*ft_update_newline(char **saved, int pos)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*saved) - pos;
	tmp = ft_strndup(*saved + pos, len);
	ft_free(saved);
	*saved = tmp;
	return (*saved);
}

char	*ft_output_newline(char **saved, int pos, int rd_bytes)
{
	char	*output;

	if (((rd_bytes == 0 || rd_bytes == -1) && !*saved) || pos == -5)
	{
		if (*saved)
			return (*saved);
		return (NULL);
	}
	output = NULL;
	if (pos == -1)
		pos = ft_strlen(*saved);
	else
		pos++;
	output = ft_strndup(*saved, pos);
	if (ft_strlen(*saved) == pos)
		ft_free(saved);
	else
		*saved = ft_update_newline(saved, pos);
	return (output);
}

char	*get_next_line(int fd)
{
	int			pos;
	int			rd_bytes;
	char		*buf;
	static char	*saved;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 10240)
	{	
		printf("ERROR! Failed Initial Check.\n");
		return (NULL);
	}
	buf = NULL;
	pos = ft_strchr(saved, '\n', 0);
/*	Loops Through the Entire File unless you flag *
 *	ft_strchr to find the new line char */
	while (pos == -1 && pos != -5)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, 1);
		if (buf == NULL)
		{	
			printf("ERROR! Failed Memory Allocation.\n");
			return (NULL);
		}
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1 || rd_bytes == 0)
			break ;
		saved = ft_strnjoin(saved, buf, rd_bytes);
		debug_info(fd, buf, BUFFER_SIZE, rd_bytes, saved);
		pos = ft_strchr(saved, '\n', 1);
		ft_free(&buf);
	}
	ft_free(&buf);
	return (ft_output_newline(&saved, pos, rd_bytes));
}
