/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:28:09 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/02/19 20:28:11 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_char;

	if (n == 0)
		return ;
	i = 0;
	s_char = s;
	while (i < n)
	{
		s_char[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = NULL;
	p = (char *)malloc(count * size);
	if (!p)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	size;

	if (!s)
		return (NULL);
	sub_str = NULL;
	size = ft_strlen(s + start);
	if (size < len)
		sub_str = (char *)ft_calloc(sizeof(char), (size + 1));
	else
		sub_str = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!sub_str)
		return (sub_str);
	if (start > ft_strlen(s))
		return (sub_str);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
