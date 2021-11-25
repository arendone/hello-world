/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:49:48 by arendon-          #+#    #+#             */
/*   Updated: 2021/11/25 16:20:26 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //!!!! no lo dejes

char	*clean_string(char *string, size_t start)
{
	while (string[start])
	{
		string[start] = '\0';
		start++;
	}
	return (string);
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
	if (line == NULL || buffer == NULL)
		return (NULL);
	j = 0;
	while (j < (int)ft_strlen(rest))
	{
		line[j] = rest[j];
		j++;
	}
	i = 0;
	while (line[i] != '\0')
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
			while (j - 1 <= BUFFER_SIZE)
			{
				rest[j - 1] = '\0';
				j++;
			}
			ifree(&buffer);
			return (line);
		}
		i++;
	}
	index = 0;
	while ((flag == 1) && (index = read(fd, buffer, BUFFER_SIZE)))
	{
		i = 0;
		buffer[index] = '\0';
		while (buffer[i] && (buffer[i] != '\n'))
			i++;
		line = strjoin(line, buffer, i + 1);
		if ((BUFFER_SIZE > i) || (buffer[i] == '\n' && BUFFER_SIZE == 1))
			flag = -1;
		else
		{
			i = 0;
			while (i < BUFFER_SIZE)
			{
				buffer[i] = '\0';
				i++;
			}
		}
	}
	if (ft_strlen(line) == 0)
	{
		ifree(&line);
		ifree(&buffer);
		return (NULL);
	}
	j = 0;
	while (j < (BUFFER_SIZE - i + 1))
	{
		rest[j] = buffer[i + 1 + j];
		j++;
	}
	while (j <= BUFFER_SIZE)
	{
		rest[j] = '\0';
		j++;
	}
	ifree(&buffer);
	return (line);
}
