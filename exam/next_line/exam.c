/* ******1) HEADER 	get_net_line.h*****/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>		// [man 2 open]
# include <unistd.h>	// [man 2 read]
# include <stdio.h>		// [man 3 printf]
# include <stdlib.h>	// [man free]

char	*get_next_line(int fd);

#endif

/* ******* 2) Main function *********** */
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("gnl-files/nl", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/* ************* get_next_line ************ */
// 1)while (no hay \n o EOF) >>> leer buff_size caracteres y copiarlos a line
// 2)guarda el rest de la linea y la copia al principio de la linea nueva

static char	*ft_calloc(size_t count, size_t size) //malloc y llena con (unsigned char)0
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
		i++;
	}
	return(pr);
}

static void ifree(char **str)
{
	if(*str)
		free(str);
	*str = NULL;
}

static size_t	fr_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

static void	ft_strlcpy(char *dst, const char *src, size_t dstsize) //copy src a dst
{
	size_t	i;
	char	*csrc; //copy of src sin const
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
}

static char	*strjoin(char *pre_line, char *buffer, int i) //join pre_line & i-primeros bits de buffer
{
	char *join;
	if (pre_line || buffer == NULL)
	{
		ifree(&pre_line);
		ifree(&buffer);
		return (NULL);
	}
	else
	{
		join = malloc(ft_strlen(pre_line) + i + 1);
		if (join == NULL)
			return (NULL);
		ft_strlcpy(join, pre_line, ft_strlcpy(pre_line) + 1); //no olvides el +1 por NULL terminator
		ft_strlcpy(&join[ft_strlen(pre_line)], buffer, i + 1);
		ifree(&pre_line);
	}
	return (join);
}

static char	*clean_string(char *str, size_t start) // limpia string deste bite "start"
{
	while (string(start))
	{
		string[start] = '/0';
		start++;
	}
	return(str);
}

static int	search_nextline(char *line, char *rest) //si encuentra devuelve num>=0 y guarda rest
{
	int	i;
	int	j;

	i = 0;
	while(line[i] != '/0')
	{
		if(line[i] == '\n')
		{
			j = 0;
			while(line[i + 1 + j] =! '\0') //guarda el rest
			{
				rest[j] = line[i + 1 + j];
				j++;
			}
			clean_string(line, i + 1); //quita el rest de line
		}
		i++;
	}
	return (-1); //si no encuentra fin de linea regresa num negativo
}

char	*read_more(int fd, char* line, char *rest) //read hasta que encuentra /n, luego llama clan_and_keep_rest
{
	int		i;
	int		index;
	char	*buffer;
	int		j;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while ((search_nextline(line, rest) < 0) && (index >= 0))
	{
		i = 0;
		clean_string(buffer, 0);
		index = read(fd, buffer, BUFFER_SIZE);
		buffer[index] = '\0';
		while (buffer[i] && buffer[i] != '\n')) // cuanta bits sin EOF o \n para comparar abajo
			i++;
		line = strjoin(line, buffer, i + 1);
		if (BUFFER_SIZE > i) // si i < BUFFER_SIZE quiere decir que alcanzo EOF o \n y no hay que leer mas
			index = -1;
	}
	//guarda rest, free buffer
	j = 0;
	while(j < BUFFER_SIZE - i)
	{
		rest[j] = line[i + 1 + j];
		j++;
	}
	ifree(&buffer);
	return(line);
}

char	*get_next_line(int fd) //no hay nada para free
{
	static char	rest[BUFFER_SIZE];
	char		*line;

	if(fd < 0 || fd > 10240 || BUFFER_SIZE < 1) //seguridad
		return (NULL);
	line = ft_calloc(BUFFER_SIZE + 1, 1); //iniciar line + seguridad
	if (line == NULL)
		return(NULL);
	ft_strlcpy(line, rest, BUFFER_SIZE + 1); //copy rest a line (al principio no tiene nada pero despues puede que si)
	clean_string(rest, 0);
	if (search_nextline(line, rest) >= 0) //busca \n, si encuentra gaurda rest y return
		return (line);
	return (read_more(fd, line, rest)); //else, lee
}

