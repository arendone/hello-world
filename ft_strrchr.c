/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:15:10 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/01 17:48:06 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*cs;

	cs = (char *)s;
	len = ft_strlen(cs) + 1;
	while (--len >= 0)
	{
		if (cs[len] == c)
			return (&cs[len]);
	}
	return (NULL);
}
