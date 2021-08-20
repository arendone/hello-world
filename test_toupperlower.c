/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupperlower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:35:01 by arendon-          #+#    #+#             */
/*   Updated: 2021/08/20 15:49:25 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

#include "header.h"

int	main()
{
	printf("\n");
    printf("funcion toupper creada:\n");
	printf("letra f se vuelve %c \n", ft_toupper('f'));
	printf("El num 3 se vuelve %c \n", ft_toupper('3'));
	printf("letra G se vuelve %c \n", ft_toupper('G'));
	printf("Un * se vuelve:%c \n", ft_toupper('*'));
	printf("Salto de linea:%c.\n", ft_toupper('\n'));
	printf("EOF es:%c.\n", ft_toupper('\0'));
	printf("\n");
    printf("funcion toupper original:\n");
	printf("letra f se vuelve %c \n", toupper('f'));
	printf("El num 3 se vuelve %c \n", toupper('3'));
	printf("letra G se vuelve %c \n", toupper('G'));
	printf("Un * se vuelve:%c \n", toupper('*'));
	printf("Salto de linea:%c.\n", toupper('\n'));
	printf("EOF es:%c.\n", toupper('\0'));

	printf("\n");
    printf("funcion tolower creada:\n");
	printf("letra f se vuelve %c \n", ft_tolower('f'));
	printf("El num 3 se vuelve %c \n", ft_tolower('3'));
	printf("letra G se vuelve %c \n", ft_tolower('G'));
	printf("Un * se vuelve:%c \n", ft_tolower('*'));
	printf("Salto de linea:%c.\n", ft_tolower('\n'));
	printf("EOF es:%c.\n", ft_tolower('\0'));
	printf("\n");
    printf("funcion tolower original:\n");
	printf("letra f se vuelve %c \n", tolower('f'));
	printf("El num 3 se vuelve %c \n", tolower('3'));
	printf("letra G se vuelve %c \n", tolower('G'));
	printf("Un * se vuelve:%c \n", tolower('*'));
	printf("Salto de linea:%c.\n", tolower('\n'));
	printf("EOF es:%c.\n", tolower('\0'));
}
