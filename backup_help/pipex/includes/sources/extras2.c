/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:26:39 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/02/19 20:26:44 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_c;
	const char	*src_c;
	size_t		i;

	if (src == NULL && dst == NULL)
		return (dst);
	i = 0;
	dst_c = (char *)dst;
	src_c = (char *)src;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = ft_strlen(dst);
	if (i >= dstsize)
		return (dstsize + ft_strlen(src));
	while (i < dstsize - 1 && *src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (i + ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	l;

	dst = NULL;
	l = ft_strlen(s1);
	dst = (char *)malloc(l + 1);
	if (!dst)
		return (dst);
	ft_strlcpy(dst, s1, l + 1);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	s = NULL;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s = (char *)ft_calloc(l1 + l2 + 1, sizeof(char));
	if (!s)
		return (s);
	ft_strlcpy(s, s1, l1 + 1);
	ft_strlcat(s, s2, l1 + l2 + 1);
	return (s);
}
