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
char	*ft_strndup(const char *s, unsigned int size);
char	*ft_strnjoin(char *s1, char *s2, int n);
void	ft_free(char **pointer);
void    *ft_calloc(size_t n_memb, size_t size);
size_t	ft_strlen(const char *s);

void	debug_info(int fd, char *buf, int buf_size, int bytes);
void	utils_debug(int fd, char *buf, int bytes, char *saved);

int		debug_strchr(char *str, char c, int flag);
void	debug_len(char *str);
void	debug_strndup(char *src, unsigned int size);
void	debug_strnjoin(char *s1, char *s2, int pos);

#endif
