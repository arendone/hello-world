#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 #include <fcntl.h>

// gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=12

void ifree(char **str)
{
    if (*str)
        free(*str);
    *str =NULL;
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnstr_fd(char *s, int fd, int n)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while ((s[i] != '\0') && (i < n))
	{
		write(fd, &s[i], 1);
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
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

	if (pre_line == NULL || buffer == NULL)
		return (NULL); //tengo que free de todas formas?
	else
	{
		join = malloc(ft_strlen(pre_line) + i + 1);
		if (join == NULL)
			return (NULL);
		ft_strlcpy(join, pre_line, ft_strlen(pre_line) + 1);
		ft_strlcpy(&join[ft_strlen(pre_line)], buffer, i + 1);
		ifree(&pre_line); //no funciona con ifree
	}	
	return (join);
}

int	ft_index_strchr(const char *s, char c)
{
	int		i;
	char	*cs;

	cs = (char *)s;
	i = 0;
	while (cs[i] != c)
	{
		if (cs[i] == '\0')
		{
			return (-1);
		}
		i++;
	}
	return (i);
}

/*char	*take_rest(char *rest, char *buffer, int i, int len)
{
	int j;

	j = 0;
	while(j < (len - i))
	{
		rest[j] = buffer[i];
		j++;
	}
	while(j <= len)
	{
		rest[j] = '\0';
		j++;
	}
	return (rest);
}*/

char	*get_next_line(int fd)
{
	int			index;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	rest[BUFFER_SIZE];
	int			i;
	int			flag;
	int			j;

	index = 0;
	flag = 1;
	
	line = (char *)ft_calloc(1,1);

	line = strjoin(line, rest, BUFFER_SIZE);
	while ((index = read(fd, buffer, BUFFER_SIZE)) && (flag == 1))
	{
		i = 0;
		buffer[index] = '\0';
		while(buffer[i] && buffer[i] != '\n')
			i++;
		line = strjoin(line, buffer, i);
		if (i != (BUFFER_SIZE))
			flag = -1;
	}
	//rest = take_rest(rest, buffer, i, BUFFER_SIZE);
	j = 0;
	while(j < (BUFFER_SIZE - i))
	{
		rest[j] = buffer[i];
		j++;
	}
	while(j <= BUFFER_SIZE)
	{
		rest[j] = '\0';
		j++;
	}
	//free(&buffer);
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
	//int i = 1;
	char *line = get_next_line(fd);
	printf("cancion:%s.\n", line);
	ifree(&line);
	line = get_next_line(fd);
	printf("%s.\n", line);
	ifree(&line);
	/*while (line)
	{
		if (line)
		{
			printf("fd(%d) #%d:	%s.", fd, i, line);
			ifree(&line);
			//line = get_next_line(fd);
			//if (!line)
				printf("\n");
		}
		i++;
	}*/
	return (0);
}