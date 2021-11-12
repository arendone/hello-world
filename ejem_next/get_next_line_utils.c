/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:45:04 by sachmull          #+#    #+#             */
/*   Updated: 2021/10/05 18:43:12 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*sc(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index] != c && s[index] != '\0')
	{
		index++;
	}
	return ((char *)s + index);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	counter;

	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	counter = 0;
	while (counter < nitems * size)
	{
		((char *)ptr)[counter] = 0;
		counter++;
	}
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (dst == NULL || src == NULL)
		return ((size_t)0);
	index = 0;
	while (src[index] != '\0' && index + 1 < size)
	{
		dst[index] = src[index];
		index++;
	}
	if (size > 0)
		dst[index] = '\0';
	return (sc(src, 0) - src);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((unsigned char *)str)[counter] = (unsigned char)c;
		counter++;
	}
	return (str);
}
