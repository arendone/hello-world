/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:35:12 by arendon-          #+#    #+#             */
/*   Updated: 2021/08/27 12:48:09 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*a;
	unsigned char	x;

	i = 0;
	a = (char *)b;
	x = (unsigned char)c;
	if (b == NULL)
		return (b);
	while (i < len)
	{
		a[i] = x;
		i ++;
	}
	return (b);
}
