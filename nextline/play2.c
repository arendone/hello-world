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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	else
	{
		join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (join == NULL)
			return (NULL);
		ft_strlcpy(join, s1, ft_strlen(s1) + 1);
		ft_strlcpy(&join[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
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


char	*get_next_line(int fd)
{
	int		index;
	char	buffer[BUFFER_SIZE + 1];
	char	*line;

	index = -1;
	//el problema es que *line no esta inicializada y me imprime basura
	while ((index = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[index] = '\0';
		line = ft_strjoin(line, buffer);
		//tengo que hacer free a line en mi otra funcion !!!!
	}

	//index = ft_index_strchr(buffer, '/n');
	//if (index == -1)
	//	return 

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
	printf("cancion:%s.", line);
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