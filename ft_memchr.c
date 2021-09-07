/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:19:09 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/02 14:51:24 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	size_t			i;

	us = (unsigned char *)s;
	i = 0;
	while (us[i] != (unsigned char)c)
	{
		if (i == n - 1)
		{
			return (NULL);
		}
		i++;
	}
	return ((void *)&us[i]);
}
