/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:45:26 by arendon-          #+#    #+#             */
/*   Updated: 2021/08/27 15:48:22 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*csrc;
	size_t	len_dst;
	int		i;

	csrc = (char *)src;
	len_dst = ft_strlen(dst);
	i = 0;
	if (dstsize > 0 && dstsize < len_dst)
	{
		while ((len_dst < dstsize - 1) && (csrc[i] != 0))
		{
			dst[len_dst] = csrc[i];
			len_dst++;
			i++;
		}
		dst[dstsize] = '\0';
	}
	return (ft_strlen(dst));
}
