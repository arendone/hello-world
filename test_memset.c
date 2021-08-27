/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:38:09 by arendon-          #+#    #+#             */
/*   Updated: 2021/08/25 10:53:16 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);

int	main(void)
{
	char	str[9] = "BBBBB BB";
	char	str2[9] = "CCCCC CC";
	char	*b;

	b = str;
	printf("printf antes: %s.\n", str);
	ft_memset(b, 65, 6);
	printf("printf despues: %s.\n", str);

	b = str2;
	printf("printf antes: %s.\n", str2);
	memset(b, 65, 6);
	printf("printf despues: %s.\n", str2);
	return (0);
}
