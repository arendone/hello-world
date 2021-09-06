/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:47:37 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/06 16:11:10 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	sub = malloc(len + 1);
	if (start <= (unsigned int)ft_strlen(s))
	{
		i = start;
		ft_strlcpy(sub, &s[i], len + 1);
		return (sub);
	}
	return (NULL);
}
