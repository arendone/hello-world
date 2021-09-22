/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1819memchrmemcmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:47:58 by marvin            #+#    #+#             */
/*   Updated: 2021/09/22 11:13:53 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

#include "libft.h"

int	main(void)
{
	unsigned char str[] = "hola";
	
    printf("direccion; %p \n", ft_memchr("hola corazon", 'c', 8));
    printf("direccion; %p \n", memchr("hola corazon", 'c', 8));

    printf("direccion; %p \n", ft_memchr("hola corazon", 'z', 8));
    printf("direccion; %p \n", memchr("hola corazon", 'z', 8));

    printf("direccion; %p \n", ft_memchr("hola corazon", '\0', 8));
    printf("direccion; %p \n", memchr("hola corazon", '\0', 8));

    printf("direccion; %p \n", ft_memchr("hola\0corazon", '\0', 8));
    printf("direccion; %p \n", memchr("hola\0corazon", '\0', 8));

    printf ("Return: %d \n", ft_memcmp(str, str, 3));	
	printf ("Return: %d \n", memcmp(str, str, 3));

    printf ("Return: %d \n", ft_memcmp("hola", "hoLa", 3));	
	printf ("Return: %d \n", memcmp("hola", "hoLa", 3));

    printf ("Return: %d \n", ft_memcmp("ho ", "hola", 3));	
	printf ("Return: %d \n", memcmp("ho ", "hola", 3));

    printf ("Return: %d \n", ft_memcmp("ho\0la", "ho\0La", 5));	
	printf ("Return: %d \n", memcmp("ho\0la", "ho\0La", 5));

}