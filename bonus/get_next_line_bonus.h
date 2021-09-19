#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

//	REMOVE
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_append_line(char **saved, int pos);
char	*ft_output_line(char **saved, int pos, int red_bytes);

int		ft_strchr(char *str, int c, int flag);

#endif
