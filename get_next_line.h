#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_strchr(const char *s, const char c);
char	*ft_update_new_line(char **saved, int pos);
char	*ft_out(char **save, int pos, int rd_bytes);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif
