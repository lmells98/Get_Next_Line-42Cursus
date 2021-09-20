#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_strchr(char *str, int c, int flag);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_strndup(const char *s, unsigned int size);
char	*ft_strnjoin(char *s1, char *s2, int n);
void	ft_free(char **pointer);
void    *ft_calloc(size_t n_memb, size_t size);

#endif
