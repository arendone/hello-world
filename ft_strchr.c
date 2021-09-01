/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:06:19 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/01 16:37:41 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cs;

	cs = (char *)s;
	i = 0;
	while (cs[i] != c)
	{
		if (cs[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return (&cs[i]);
}
