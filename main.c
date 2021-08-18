/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:36:48 by marvin            #+#    #+#             */
/*   Updated: 2021/08/18 12:36:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int ft_isalpha(int c)
{
    if (('a' <= c && c <= 'z' ) || ('A' <= c && c <= 'Z' ))
        return(1);
    else
        return (0);
}

int ft_isdigit(int c)
{
    if ('0' <= c && c <= '9')  //I am not sure which should be the value, with '' or without.
        return(1);
    else
        return (0);
}

int ft_isalnum(int c)
{
    if ((('a' <= c && c <= 'z' ) || ('A' <= c && c <= 'Z' )) || ('0' <= c && c <= '9'))
        return(1);
    else
        return (0);
}

int ft_isascii(int c)
{
    if (0 <= c && c <= 255)
        return(1);
    else
        return (0);    
}

int main(void)
{
    char a;
    int b;
    //signed char c;

    a ='s';
    b = 3;
    //c = '-3'
   /* printf("La funcion isalpha develve: %i para variable a\n", ft_isalpha(a));
    printf("La funcion isalpha develve: %i para variable b\n", ft_isalpha(b));
    printf("La funcion isalpha develve: %i para j\n", ft_isalpha('j'));
    printf("La funcion isalpha develve: %i para Z\n", ft_isalpha('Z'));
    printf("La funcion isalpha develve: %i para 6\n", ft_isalpha('6'));
    printf("La funcion isalpha develve: %i para *\n", ft_isalpha('*'));
    printf("La funcion isalpha develve: %i para 0\n", ft_isalpha('0'));
    printf("La funcion isalpha develve: %i para o\n", ft_isalpha('o'));
    printf("La funcion isalpha develve: %i para 120 sin comillas (x)\n", ft_isalpha(120));
    
    printf("La funcion isdigt develve: %i para variable a\n", ft_isdigit(a));
    printf("La funcion isdigt develve: %i para variable b\n", ft_isdigit(b));
    printf("La funcion isdigt develve: %i para j\n", ft_isdigit('j'));
    printf("La funcion isdigt develve: %i para Z\n", ft_isdigit('Z'));
    printf("La funcion isdigt develve: %i para 6\n", ft_isdigit('6'));
    printf("La funcion isdigt develve: %i para *\n", ft_isdigit('*'));
    printf("La funcion isdigt develve: %i para 0\n", ft_isdigit('0'));
    printf("La funcion isdigt develve: %i para o\n", ft_isdigit('o'));
    printf("La funcion isdigt develve: %i para 120 sin comillas (x)\n", ft_isdigit(120));

    printf("La funcion isalnum develve: %i para variable a\n", ft_isalnum(a));
    printf("La funcion isalnum develve: %i para variable b\n", ft_isalnum(b));
    printf("La funcion isalnum develve: %i para j\n", ft_isalnum('j'));
    printf("La funcion isalnum develve: %i para Z\n", ft_isalnum('Z'));
    printf("La funcion isalnum develve: %i para 6\n", ft_isalnum('6'));
    printf("La funcion isalnum develve: %i para *\n", ft_isalnum('*'));
    printf("La funcion isalnum develve: %i para 0\n", ft_isalnum('0'));
    printf("La funcion isalnum develve: %i para o\n", ft_isalnum('o'));
    printf("La funcion isalnum develve: %i para 120 sin comillas (x)\n", ft_isalnum(120));*/

    printf("La funcion isascii develve: %i para variable a\n", ft_isascii(a));
    printf("La funcion isascii develve: %i para variable b\n", ft_isascii(b));
    printf("La funcion isascii develve: %i para variable -3\n", ft_isascii(-3));
    printf("La funcion isascii develve: %i para j\n", ft_isascii('j'));
    printf("La funcion isascii develve: %i para Z\n", ft_isascii('Z'));
    printf("La funcion isascii develve: %i para 6\n", ft_isascii('6'));
    printf("La funcion isascii develve: %i para *\n", ft_isascii('*'));
    printf("La funcion isascii develve: %i para 0\n", ft_isascii('0'));
    printf("La funcion isascii develve: %i para o\n", ft_isascii('o'));
    printf("La funcion isascii develve: %i para 120 sin comillas (x)\n", ft_isascii(120));
    return (0);
}