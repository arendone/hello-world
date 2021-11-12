/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:22:35 by sachmull          #+#    #+#             */
/*   Updated: 2021/10/05 18:57:14 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#if (BUFFER_SIZE > 0)
char	*get_next_line(int fd)
{
	static char	file_data[10240][BUFFER_SIZE];
	void		*buffer;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	line = get_leftovers(fd, file_data);
	bytes_read = 1;
	while (sc(line, '\n') == sc(line, 0) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
			break ;
		line = add_to_line(line, buffer, fd, file_data);
		ft_memset(buffer, 0, BUFFER_SIZE);
	}
	free(buffer);
	if (!(*line))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * Adds the content of bufffer to line until the first \n is encountered
 * Saves the rest in file_data
**/

char	*add_to_line(char *l, char *b, int fd, char fl_d[10240][BUFFER_SIZE])
{
	char	*new_line;

	new_line = ft_calloc(1, (sc(l, 0) - l) + (sc(b, '\n') - b) + 2);
	ft_strlcpy(new_line, l, sc(l, 0) - l + 1);
	ft_strlcpy(new_line + (sc(l, 0) - l), b, sc(b, '\n') - b + 2);
	if (sc(b, 0) != sc(b, '\n'))
		ft_strlcpy(sc(fl_d[fd], 0), sc(b, '\n') + 1, \
		BUFFER_SIZE - (sc(fl_d[fd], 0) - fl_d[fd]));
	free(l);
	return (new_line);
}

char	*get_leftovers(int fd, char fl_d[10240][BUFFER_SIZE])
{
	char	*line;	

	if (fl_d[fd][0])
	{
		line = ft_calloc(1, sc(fl_d[fd], '\n') - fl_d[fd] + 2);
		ft_strlcpy(line, fl_d[fd], sc(fl_d[fd], '\n') - fl_d[fd] + 2);
		arrange(fd, fl_d);
		return (line);
	}
	else
		return (ft_calloc(1, 1));
}

void	arrange(int fd, char fl_d[10240][BUFFER_SIZE])
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	while (i1 < BUFFER_SIZE - 1 && fl_d[fd][i1] != '\n')
	{
		fl_d[fd][i1] = 0;
		i1++;
	}
	fl_d[fd][i1] = 0;
	i1++;
	while (i1 < BUFFER_SIZE && fl_d[fd][i1] != 0)
	{
		fl_d[fd][i2] = fl_d[fd][i1];
		fl_d[fd][i1] = 0;
		i1++;
		i2++;
	}
}
#else

char	*get_next_line(int fd)
{
	return (NULL);
}
#endif
