/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:49:48 by arendon-          #+#    #+#             */
/*   Updated: 2021/11/26 17:39:47 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_string(char *string, size_t start)
{
	while (string[start])
	{
		string[start] = '\0';
		start++;
	}
	return (string);
}

int	search_nextline(char *line, char *rest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			while (line[i + 1 + j] != '\0')
			{
				rest[j] = line[i + 1 + j];
				line[i + 1 + j] = '\0';
				j++;
			}
			clean_string(rest, j);
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*read_more(int fd, char *line, char *rest)
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
		while (buffer[i] && (buffer[i] != '\n'))
			i++;
		line = strjoin(line, buffer, i + 1);
		if (BUFFER_SIZE > i)
			index = -1;
	}
	return (clean_and_keep_rest(line, rest, buffer, i));
}

char	*clean_and_keep_rest(char *line, char *rest, char *buffer, int i)
{
	int	j;

	j = 0;
	while (j < (BUFFER_SIZE - i + 1))
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

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_calloc(BUFFER_SIZE + 1, 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, rest, BUFFER_SIZE + 1);
	if (search_nextline(line, rest) >= 0)
		return (line);
	return (read_more(fd, line, rest));
}
