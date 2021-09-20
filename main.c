/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:59:42 by lmells            #+#    #+#             */
/*   Updated: 2021/09/20 10:59:42 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;

	fd = open("./text.txt", O_RDONLY);
	if (fd < 0 || fd > 10240)
	{
		printf("ERROR! Failed to open file.");
		return (0);
	}
	for (i = 1; i <= 12; i++)
	{
		printf("%i:	%s", i, get_next_line(fd));
	}
	return (0);
}
