/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:11:02 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/02 14:13:09 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (i < n && us1[i] != '\0' && us2[i] != '\0')
	{
		if (us1[i] < us2[i])
			return (us1[i] - us2[i]);
		else if (us1[i] > us2[i])
			return (us1[i] - us2[i]);
		else
			i++;
	}
	return (0);
}
