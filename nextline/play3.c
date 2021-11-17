#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void ifree(char **str)
{
    if (*str)
        free(*str);
    *str =NULL;
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)b;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i ++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*pr;

	pr = (unsigned char *)malloc(count * size);
	if (pr == NULL)
		return (NULL);
	ft_bzero(pr, (count * size));
	return ((void *)pr);
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*csrc;

	csrc = (char *)src;
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && csrc[i])
		{
			dst[i] = csrc[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(csrc));
}

char	*strjoin(char *pre_line, char *buffer, int i) //why to use const char and not only char?
{
	char	*join;
	int		j;

	if (pre_line == NULL || buffer == NULL)
		return (NULL); //tengo que free de todas formas?
	else
	{
		join = malloc(ft_strlen(pre_line) + i + 1);
		if (join == NULL)
			return (NULL);
		ft_strlcpy(join, pre_line, ft_strlen(pre_line) + 1);
		ft_strlcpy(&join[ft_strlen(pre_line)], buffer, i + 1);
		ifree(&pre_line);
	}	
	return (join);
}

char	*get_next_line(int fd)
{
	int			index;
	static char	rest[BUFFER_SIZE];
	char		*line;
	char		*buffer;
	int			flag;
	int			i;
	int			j;

	flag = 1;
	line = (char *)calloc(BUFFER_SIZE + 1, 1);
	buffer = (char *)calloc(BUFFER_SIZE + 1, 1);
	j = 0;
	while(j < ft_strlen(rest))
	{
		line[j] = rest[j];
		j++;
	}
	while ((flag == 1) && (index = read(fd, buffer, BUFFER_SIZE)))
	{
		i = 0;
		buffer[index] = '\0';
		while(buffer[i] && (buffer[i] != '\n'))
			i++;
		line = strjoin(line, buffer, i);
		if (i < (BUFFER_SIZE))
			flag = -1;
	}
	
	if (ft_strlen(line) == 0)
	{
		ifree(&line);
		ifree(&buffer);
		return(NULL);
	}
	j = 0;
	while(j < (BUFFER_SIZE - i))
	{
		rest[j] = buffer[i + j];
		j++;
	}
	while(j <= BUFFER_SIZE)
	{
		rest[j] = '\0';
		j++;
	}
	ifree(&buffer);
	return (line);
}

int	main(void)
{
	int	fd = open("text2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (1);
	}
	int i = 1;
	char *line = get_next_line(fd);
	/*printf("cancion:%s.\n", line);
	ifree(&line);
	printf("--------\n");
	line = get_next_line(fd);
	printf("%s.\n", line);
	ifree(&line);*/
	while (line)
	{
		if (line)
		{
			printf("%s | fd(%d) #%d", line, fd, i);
			ifree(&line);
			line = get_next_line(fd);
			if (!line)
				printf("\n");
		}
		i++;
	}
	return (0);
}