/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:09:13 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/26 20:14:45 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -Wall -Werror -Wextra -D BUFFER_SIZE=15 get_next_line.c get_next_line_utils.c main.c

#include "get_next_line.h"

static void	ifree(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

static size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

/* malloc y llena con (unsigned char)0 */
static char	*ft_calloc(size_t count, size_t size)
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

/* copy src a dst */
static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

/*join pre_line & i-primeros bits de buffer*/
/* no olvides el +1 por NULL terminator */
static char	*strjoin(char *pre_line, char *buffer, int i)
{
	char	*join;

	if (pre_line == NULL || buffer == NULL)
	{
		ifree(&pre_line);
		return (NULL);
	}
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

/* limpia string deste bite "start" */
static char	*clean_string(char *str, size_t start)
{
	while (str[start])
	{
		str[start] = '\0';
		start++;
	}
	return (str);
}

/* si encuentra devuelve num>=0 y guarda rest */
static int	search_nextline(char *line, char *rest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			while (line[i + 1 + j] != '\0') //guarda el rest
			{
				rest[j] = line[i + 1 + j];
				line[i + 1 + j] = '\0'; //quita rest de line
				j++;
			}
			clean_string(rest, j); //limpia posible basura en rest
			return (i);
		}
		i++;
	}
	return (-1); //si no encuentra \n regresa num negativo
}

static char	*clean_and_keep_rest(char *line, char *rest, char *buffer, int i)
{
	int	j;

	j = 0;
	while (j < (BUFFER_SIZE - i))
	{
		rest[j] = buffer[i + 1 + j];
		j++;
	}
	clean_string(rest, j);
	if (ft_strlen(line) == 0)
	{
		ifree(&line);
		ifree(&buffer);
		return (NULL);
	}
	ifree(&buffer);
	return (line);
}

/* read hasta que encuentra /n, luego llama clan_and_keep_rest */
static char	*read_more(int fd, char *line, char *rest)
{
	int		i;
	int		index;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (line == NULL || buffer == NULL)
		return (NULL);
	index = 0;
	while ((search_nextline(line, rest) < 0) && (index >= 0))
	{
		i = 0;
		clean_string(buffer, 0);
		index = read(fd, buffer, BUFFER_SIZE);
		buffer[index] = '\0';
		while (buffer[i] && (buffer[i] != '\n')) // cuanta bits sin EOF o \n para comparar abajo
			i++;
		line = strjoin(line, buffer, i + 1);
		if (BUFFER_SIZE > i) // si i < BUFFER_SIZE quiere decir que alcanzo EOF o \n y no hay que leer mas
			index = -1;
	}
	return (clean_and_keep_rest(line, rest, buffer, i));
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 1) //seguridad
		return (NULL);
	line = ft_calloc(BUFFER_SIZE + 1, 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, rest, BUFFER_SIZE + 1); //copy rest a line (al principio no tiene nada pero despues puede que si)
	if (search_nextline(line, rest) >= 0) //busca \n, si encuentra gaurda rest y return
		return (line);
	return (read_more(fd, line, rest)); //else, lee
}