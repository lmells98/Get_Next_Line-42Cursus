#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_update_new_line(char **saved, int pos);
char	*ft_out(char **save, int pos, int rd_bytes);
char	*get_next_line(int fd);
