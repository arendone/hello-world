/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzeromemset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:55:17 by arendon-          #+#    #+#             */
/*   Updated: 2021/08/25 11:05:31 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len);
void ft_bzero(void *s, size_t n);

int	main(void)
{
	char	str[50];

	strcpy(str, "This is string.h library function");
	puts(str);

	memset(str, 65, 7);
	puts(str);

	strcpy(str, "This is string.h library function");
	puts(str);

	ft_memset(str, '$', 7);
	puts(str);

	strcpy(str, "This is string.h library function");
	puts(str);

	bzero(str, 7);
	puts(str);
	printf("printf despues: %c.\n", str[10]);
	
	strcpy(str, "This is string.h library function");
	puts(str);
	ft_bzero(str, 7);
	puts(str);
	printf("printf despues: %c.\n", str[10]);
	return (0);
}
