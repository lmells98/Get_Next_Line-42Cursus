#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

int		ft_strlen(const char *str);
int		ft_strchr(char *str, int c, int flag);
char	*ft_strndup(const char *s1, unsigned int size);
char	*ft_strnjoin(char *s1, char *s2, unsigned int size);
void	ft_free(char **pointer);

#endif
