#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
//# if (BUFFER_SIZE > 0)
void ifree(char **str);
char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*strjoin(char *pre_line, char *buffer, int i);
char	*clean_string(char *string, size_t start);
//# endif
#endif