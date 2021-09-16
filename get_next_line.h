#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_strchr(char *str, int c, int flag);
char	*get_next_line(int fd);
char	*ft_strndup(const char *c, unsigned int size);
void	ft_free(char **pointer);
void    *ft_calloc(size_t n_memb, size_t size);
size_t	ft_strlen(const char *s);

void	debug_info(int fd, char *buf, int buf_size, int bytes);
void	utils_debug(int fd, char *buf, int bytes);

#endif
