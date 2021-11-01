/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:59:05 by marvin            #+#    #+#             */
/*   Updated: 2021/11/01 15:59:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h> //Borralo!!!

size_t	ft_maximum_sizet(size_t n, ...);
size_t	ft_minimum_sizet(size_t n, ...);

size_t	ft_len_int(int n)
{
	size_t	digits;

	digits = 1;
	while (n / 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

int print_num_withsign(int num, size_t len, t_print *t_spec)
{
    if((t_spec->sign == true) && (num >= 0))
    {
        write(1, "+", 1);
        t_spec->len_total++;
    }
    else if(num < 0)
    {
        write(1, "-", 1);
        t_spec->len_total++;
        num = num * (-1);
    }
    if ((num == 0) && (t_spec->precision_details == 0))
        ft_putchar_fd(' ', 1);
    else
    {
        if (t_spec->precision_details > len)
        {
            ft_print_zeros(t_spec->precision_details - len);
            len = t_spec->precision_details;
        }
        ft_putnbr_fd(num, 1);
        return (len);
    }
}

int ft_print_d_width(int num, size_t len, size_t max, t_print *t_spec)
{
    if ((num == 0) && (t_spec->precision_details == 0))
        t_spec->zero = false;
    if (!(t_spec->dash) && !(t_spec->zero))
    {
    	ft_print_spaces(t_spec->width_details - max);
    	len = print_num_withsign(num, len, t_spec);
    }
    if (t_spec->dash)
    {
    	len = print_num_withsign(num, len, t_spec);
    	ft_print_spaces(t_spec->width_details - max);
    }
    if (!(t_spec->dash) && (t_spec->zero))
    {
    	ft_print_zeros(t_spec->width_details - max);
    	len = print_num_withsign(num, len, t_spec);
    }
    return (t_spec->width_details);
}

int print_d(int i, t_print *t_spec)
{
    int num;
    size_t len;
    size_t max;
    
    num = va_arg(t_spec->args, int);
    len = ft_len_int(num);
    max = ft_maximum_sizet(2, len, t_spec->precision_details);
    if((num < 0) || (t_spec->sign == true))
        max++;
    if(!t_spec->precision)
        t_spec->precision_details = 1;
    if (t_spec->width_details > max)
        len = ft_print_d_width(num, len, max, t_spec);
    else
        len = print_num_withsign(num, len, t_spec);
    t_spec->len_total += len;
    return(i + 1);
}
