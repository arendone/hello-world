/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:47:53 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 10:47:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_maximoint(int n, ...);

int ft_print_spaces(int spaces)
{
    int j;

    j = 0;
        while ( j < spaces)
        {
           ft_putchar_fd(' ', 1);
           j++;
        }
    return (spaces);
}

int ft_print_zeros(int zeros)
{
    int j;

    j = 0;
        while ( j < zeros)
        {
           ft_putchar_fd('0', 1);
           j++;
        }
    return (zeros);
}

int	ft_print_null(t_print *t_spec)
{
	int	j;

	if (t_spec->precision_details > 0 && t_spec->precision_details < 6)
		j = t_spec->precision_details;
	else
		j = 6;
	t_spec->len_total += write(1, "(null)", j);
    return (j);
}

int ft_print_char(char *format, int i, t_print *t_spec)
{
    char c;

    c = (char) va_arg(t_spec->args, int);
	if (t_spec->width && !(t_spec->dash))
        ft_print_spaces(t_spec->width_details - 1);
    ft_putchar_fd(c, 1);
    if (t_spec->width && t_spec->dash)
        ft_print_spaces(t_spec->width_details - 1);
    t_spec->len_total = t_spec->len_total + ft_maximoint(2, 1, t_spec->width_details);
    return (i+1);
}

int ft_print_str(char *format, int i, t_print *t_spec)
{
    char *str;
    size_t len;

    str = va_arg(t_spec->args, char *);
    /*if (t_spec->width)
    {
        if (!(t_spec->dash) && !(t_spec->zero))
        {
            if (str == NULL)
        }
        if (t_spec->dash)
        {

        }
        if (!(t_spec->dash) && (t_spec->zero))
        {

        }

    }

    {
        if
    }*/
    
}

/*

    if  width

checar 1) if !dash and !zero

           imprimir s y llenar con ' '

       2) if dash (no importa como sea zero)

          imprimir ' ' y luego s

       3) if !dash and zero

          imprimir 0 y luego s

else if precision

          len_s

          print (min (len_s o precision)
          
          
          QUE PASA SI WIDTH ES MENOR QUE 6 Y PRECISION MENOR QUE 6 Y STR ES NULL?????
          */


