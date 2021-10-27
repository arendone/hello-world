/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:38:09 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/01 11:22:50 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

int	main(void)
{
	char	str[9] = "BBBBB BB";
	char	str2[9] = "BBBBB BB";
	char	str3[50];
	char	*b;

	b = str;
	printf("printf antes de ft_memset: %s.\n", str);
	ft_memset(b, 65, 6);
	printf("printf despues: %s.\n", str);

	b = str2;
	printf("printf antes de memset: %s.\n", str2);
	memset(b, 65, 6);
	printf("printf despues: %s.\n", str2);

	strcpy(str3, "This is string.h library function");
	puts(str3);
	ft_memset(str3, '$', 7);
	puts(str3);
	strcpy(str3, "This is string.h library function");
	puts(str3);
	memset(str3, '$', 7);
	puts(str3);
	
	strcpy(str3, "This is string.h library function");
	puts(str3);
	ft_bzero(str3, 7);
	puts(str3);
	printf("printf despues: %c.\n", str3[10]);
	strcpy(str3, "This is string.h library function");
	puts(str3);
	bzero(str3, 7);
	puts(str3);
	printf("printf despues: %c.\n", str3[10]);
	
	return (0);
}
