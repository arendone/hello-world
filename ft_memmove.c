/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:23:10 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/16 15:05:08 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	csrc = (char *)src;
	cdst = (char *)dst;
	i = 0;
	if (csrc > cdst)
	{
		while (len--)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	else
		while (len--)
			*(cdst + len) = *(csrc + len);
	return (cdst);
}
