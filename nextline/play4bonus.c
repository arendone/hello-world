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

char	*ft_calloc(size_t count, size_t size)
{
	char	*pr;
	size_t	i;

	pr = (char *)malloc(count * size);
	if (pr == NULL)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		pr[i] = (unsigned char)0;
		i ++;
	}
	return (pr);
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
	line = ft_calloc(BUFFER_SIZE + 1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	j = 0;
	while(j < (int)ft_strlen(rest))
	{
		line[j] = rest[j];
		j++;
	}

	i = 0;
	while(line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			j = 1;
			while (line[i + j] != '\0')
			{
				rest[j - 1] = line[i + j];
				line[i + j] = '\0';
				j++;
			}
			while(j - 1 <= BUFFER_SIZE)
			{
				rest[j - 1] = '\0';
				j++;
			}
			ifree(&buffer);
			return (line);
		}
		i++;
	}

	while ((flag == 1) && (index = read(fd, buffer, BUFFER_SIZE)))
	{
		i = 0;
		buffer[index] = '\0';
		while(buffer[i] && (buffer[i] != '\n'))
			i++;
		line = strjoin(line, buffer, i + 1);
		if ((i + 2 <= (BUFFER_SIZE)) || (buffer[i] == '\n' && BUFFER_SIZE == 1))
			flag = -1;
	}
	
	if (ft_strlen(line) == 0)
	{
		ifree(&line);
		ifree(&buffer);
		return(NULL);
	}
	j = 0;
	while(j < (BUFFER_SIZE - i + 1))
	{
		rest[j] = buffer[i + 1 + j];
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
			printf("fd(%d) #%d | %s", fd, i, line);
			ifree(&line);
			line = get_next_line(fd);
			if (!line)
			printf("\n");
		}
		i++;
	}
	//system("leaks song.out");
	return (0);
}