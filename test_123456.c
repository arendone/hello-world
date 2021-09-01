/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test123456.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:31:16 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/01 10:46:02 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "libft.h"

int main()
{
    char a;
    int b;

    a ='s';
    b = 3;
    
    printf("funcion 1 creada:\n");
    printf("La funcion ft_isalpha develve: %i para variable a\n", ft_isalpha(a));
    printf("La funcion ft_isalpha develve: %i para variable b\n", ft_isalpha(b));
    printf("La funcion ft_isalpha develve: %i para j\n", ft_isalpha('j'));
    printf("La funcion ft_isalpha develve: %i para Z\n", ft_isalpha('Z'));
    printf("La funcion ft_isalpha develve: %i para 6\n", ft_isalpha('6'));
    printf("La funcion ft_isalpha develve: %i para *\n", ft_isalpha('*'));
    printf("La funcion ft_isalpha develve: %i para 0\n", ft_isalpha('0'));
    printf("La funcion ft_isalpha develve: %i para 120 sin comillas (x)\n", ft_isalpha(120));
    printf("La funcion ft_isalpha develve: %i para salto de linea \n", ft_isalpha('\n'));
    printf("La funcion ft_isalpha develve: %i para salto de linea -1\n", ft_isalpha(-1));
    printf("funcion 1 original:\n");
    printf("La funcion isalpha develve: %i para variable a\n", isalpha(a));
    printf("La funcion isalpha develve: %i para variable b\n", isalpha(b));
    printf("La funcion isalpha develve: %i para j\n", isalpha('j'));
    printf("La funcion isalpha develve: %i para Z\n", isalpha('Z'));
    printf("La funcion isalpha develve: %i para 6\n", isalpha('6'));
    printf("La funcion isalpha develve: %i para *\n", isalpha('*'));
    printf("La funcion isalpha develve: %i para 0\n", isalpha('0'));
    printf("La funcion isalpha develve: %i para 120 sin comillas (x)\n", isalpha(120));
    printf("La funcion isalpha develve: %i para salto de linea \n", isalpha('\n'));
    printf("La funcion isalpha develve: %i para -1 \n", isalpha(-1));
	
	printf("\n");
    printf("funcion 2 creada:\n");
    printf("La funcion ft_isdigit develve: %i para variable a\n", ft_isdigit(a));
    printf("La funcion ft_isdigit develve: %i para variable b\n", ft_isdigit(b));
    printf("La funcion ft_isdigit develve: %i para j\n", ft_isdigit('j'));
    printf("La funcion ft_isdigit develve: %i para Z\n", ft_isdigit('Z'));
    printf("La funcion ft_isdigit develve: %i para 6\n", ft_isdigit('6'));
    printf("La funcion ft_isdigit develve: %i para *\n", ft_isdigit('*'));
    printf("La funcion ft_isdigit develve: %i para 0\n", ft_isdigit('0'));
    printf("La funcion ft_isdigit develve: %i para 120 sin comillas (x)\n", ft_isdigit(120));
    printf("La funcion ft_isdigit develve: %i para salto de linea \n", ft_isdigit('\n'));
    printf("La funcion ft_isdigit develve: %i para salto de linea -1\n", ft_isdigit(-1));
    printf("funcion 2 original:\n");
    printf("La funcion isdigit develve: %i para variable a\n", isdigit(a));
    printf("La funcion isdigit develve: %i para variable b\n", isdigit(b));
    printf("La funcion isdigit develve: %i para j\n", isdigit('j'));
    printf("La funcion isdigit develve: %i para Z\n", isdigit('Z'));
    printf("La funcion isdigit develve: %i para 6\n", isdigit('6'));
    printf("La funcion isdigit develve: %i para *\n", isdigit('*'));
    printf("La funcion isdigit develve: %i para 0\n", isdigit('0'));
    printf("La funcion isdigit develve: %i para 120 sin comillas (x)\n", isdigit(120));
    printf("La funcion isdigit develve: %i para salto de linea \n", isdigit('\n'));
    printf("La funcion isdigit develve: %i para -1 \n", isdigit(-1));
    
	printf("\n");
    printf("funcion 3 creada:\n");
    printf("La funcion ft_isalnum develve: %i para variable a\n", ft_isalnum(a));
    printf("La funcion ft_isalnum develve: %i para variable b\n", ft_isdigit(b));
    printf("La funcion ft_isalnum develve: %i para j\n", ft_isalnum('j'));
    printf("La funcion ft_isalnum develve: %i para Z\n", ft_isalnum('Z'));
    printf("La funcion ft_isalnum develve: %i para 6\n", ft_isalnum('6'));
    printf("La funcion ft_isalnum develve: %i para *\n", ft_isalnum('*'));
    printf("La funcion ft_isalnum develve: %i para 0\n", ft_isalnum('0'));
    printf("La funcion ft_isalnum develve: %i para 120 sin comillas (x)\n", ft_isalnum(120));
    printf("La funcion ft_isalnum develve: %i para salto de linea \n", ft_isalnum('\n'));
    printf("La funcion ft_isalnum develve: %i para salto de linea -1\n", ft_isalnum(-1));
    printf("funcion 3 original:\n");
    printf("La funcion isalnum develve: %i para variable a\n", isalnum(a));
    printf("La funcion isalnum develve: %i para variable b\n", isalnum(b));
    printf("La funcion isalnum develve: %i para j\n", isalnum('j'));
    printf("La funcion isalnum develve: %i para Z\n", isalnum('Z'));
    printf("La funcion isalnum develve: %i para 6\n", isalnum('6'));
    printf("La funcion isalnum develve: %i para *\n", isalnum('*'));
    printf("La funcion isalnum develve: %i para 0\n", isalnum('0'));
    printf("La funcion isalnum develve: %i para 120 sin comillas (x)\n", isalnum(120));
    printf("La funcion isalnum develve: %i para salto de linea \n", isalnum('\n'));
    printf("La funcion isalnum develve: %i para -1 \n", isalnum(-1));

	printf("\n");
    printf("funcion 4 creada:\n");
    printf("La funcion ft_isascii develve: %i para variable a\n", ft_isascii(a));
    printf("La funcion ft_isascii develve: %i para variable b\n", ft_isascii(b));
    printf("La funcion ft_isascii develve: %i para j\n", ft_isascii('j'));
    printf("La funcion ft_isascii develve: %i para Z\n", ft_isascii('Z'));
    printf("La funcion ft_isascii develve: %i para 6\n", ft_isascii('6'));
    printf("La funcion ft_isascii develve: %i para *\n", ft_isascii('*'));
    printf("La funcion ft_isascii develve: %i para 0\n", ft_isascii('0'));
    printf("La funcion ft_isascii develve: %i para 120 sin comillas (x)\n", ft_isascii(120));
    printf("La funcion ft_isascii develve: %i para salto de linea \n", ft_isascii('\n'));
    printf("La funcion ft_isascii develve: %i para salto de linea -1\n", ft_isascii(-1));
    printf("funcion 4 original:\n");
    printf("La funcion isascii develve: %i para variable a\n", isascii(a));
    printf("La funcion isascii develve: %i para variable b\n", isascii(b));
    printf("La funcion isascii develve: %i para j\n", isascii('j'));
    printf("La funcion isascii develve: %i para Z\n", isascii('Z'));
    printf("La funcion isascii develve: %i para 6\n", isascii('6'));
    printf("La funcion isascii develve: %i para *\n", isascii('*'));
    printf("La funcion isascii develve: %i para 0\n", isascii('0'));
    printf("La funcion isascii develve: %i para 120 sin comillas (x)\n", isascii(120));
    printf("La funcion isascii develve: %i para salto de linea \n", isascii('\n'));
    printf("La funcion isascii develve: %i para -1 \n", isascii(-1));
    
	printf("\n");
	printf("funcion 5 creada:\n");
    printf("La funcion ft_isprint develve: %i para variable a\n", ft_isprint(a));
    printf("La funcion ft_isprint develve: %i para variable b\n", ft_isprint(b));
    printf("La funcion ft_isprint develve: %i para j\n", ft_isprint('j'));
    printf("La funcion ft_isprint develve: %i para Z\n", ft_isprint('Z'));
    printf("La funcion ft_isprint develve: %i para 6\n", ft_isprint('6'));
    printf("La funcion ft_isprint develve: %i para *\n", ft_isprint('*'));
    printf("La funcion ft_isprint develve: %i para 0\n", ft_isprint('0'));
    printf("La funcion ft_isprint develve: %i para 120 sin comillas (x)\n", ft_isprint(120));
    printf("La funcion ft_isprint develve: %i para salto de linea \n", ft_isprint('\n'));
    printf("La funcion ft_isprint develve: %i para salto de linea -1\n", ft_isprint(-1));
    printf("funcion 5 original:\n");
    printf("La funcion isprint develve: %i para variable a\n", isprint(a));
    printf("La funcion isprint develve: %i para variable b\n", isprint(b));
    printf("La funcion isprint develve: %i para j\n", isprint('j'));
    printf("La funcion isprint develve: %i para Z\n", isprint('Z'));
    printf("La funcion isprint develve: %i para 6\n", isprint('6'));
    printf("La funcion isprint develve: %i para *\n", isprint('*'));
    printf("La funcion isprint develve: %i para 0\n", isprint('0'));
    printf("La funcion isprint develve: %i para 120 sin comillas (x)\n", isprint(120));
    printf("La funcion isprint develve: %i para salto de linea \n", isprint('\n'));
    printf("La funcion isprint develve: %i para -1 \n", isprint(-1));
	
	printf("\n");
	printf("Length of the string ft funtion:%lu \n", ft_strlen(""));
	printf("Length of the string original funtion:%lu \n", strlen(""));
	printf("Length of the string ft funtion:%lu \n", ft_strlen("wie geht es dir?"));
	printf("Length of the string original funtion:%lu \n", strlen("wie geht es dir?"));
	printf("Length of the string ft funtion:%lu \n", ft_strlen("wie geht es \0 dir?"));
	printf("Length of the string original funtion:%lu \n", strlen("wie geht es \0 dir?"));
	printf("Length of the string ft funtion:%lu \n", ft_strlen("wie geht es \n dir? "));
	printf("Length of the string original funtion:%lu \n", strlen("wie geht es \n dir? "));
	
    return (0);
}
