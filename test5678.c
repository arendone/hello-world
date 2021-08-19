/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5678.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:05:22 by arendon-          #+#    #+#             */
/*   Updated: 2021/08/19 14:59:46 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ME HACE RUIDO QUE PARA LA FUNCION STRLEN TENGA QUE DEFINIR DISTINTO CUANDO IMPRIMO... 
// DEBERIA SER UNSIGNED LONG INT O SOLO INT O ????

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	ft_isprint(int c);
int	ft_strlen(char *str);

int	main()
{
	char a;
	int b;

    a ='s';
    b = 3;
    
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

	printf("Length of the string ft funtion:%d \n", ft_strlen(""));
	printf("Length of the string original funtion:%lu \n", strlen(""));
	printf("Length of the string ft funtion:%d \n", ft_strlen("wie geht es dir?"));
	printf("Length of the string original funtion:%lu \n", strlen("wie geht es dir?"));
	printf("Length of the string ft funtion:%d \n", ft_strlen("wie geht es \0 dir?"));
	printf("Length of the string original funtion:%lu \n", strlen("wie geht es \0 dir?"));
	printf("Length of the string ft funtion:%d \n", ft_strlen("wie geht es \n dir? "));
	printf("Length of the string original funtion:%lu \n", strlen("wie geht es \n dir? "));
	
	return (0);
}
