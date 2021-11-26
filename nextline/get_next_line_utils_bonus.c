/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:01:47 by arendon-          #+#    #+#             */
/*   Updated: 2021/11/26 17:39:08 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ifree(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
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

char	*strjoin(char *pre_line, char *buffer, int i)
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
