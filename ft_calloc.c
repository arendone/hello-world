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
	char	*pr;
	size_t	i;

	pr = (char *)malloc(count * size);
	i = 0;
	while (i <= (count * size - 1))
	{
		pr[i] = '\0';
		i++;
	}
	return ((void *)pr);
}
