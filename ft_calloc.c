/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:36:07 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/06 15:16:34 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*pr;
	size_t	i;

	pr = (unsigned char *)malloc(count * size);
	if (pr == NULL)
        return (NULL);
    ft_bzero(pr, (count * size));
	return ((void *)pr);
}
