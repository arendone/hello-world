/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:59:05 by marvin            #+#    #+#             */
/*   Updated: 2021/11/02 15:06:51 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_maximum_sizet(size_t n, ...);
size_t	ft_minimum_sizet(size_t n, ...);

static size_t	ft_len_int(int n)
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

size_t	print_num_prec(int num, size_t len, size_t counter, t_print *t_spec)
{
	if (t_spec->precision_details > len)
	{
		ft_print_zeros(t_spec->precision_details - len);
		counter += (t_spec->precision_details - len);
	}
	ft_putnbr_fd(num, 1);
	return (counter);
}

size_t	print_num_withsign(int num, size_t len, t_print *t_spec)
{
	size_t	counter;

	counter = 0;
	if ((t_spec->sign == true) && (num >= 0))
	{
		ft_putchar_fd('+', 1);
		counter++;
	}
	else if (num < 0)
	{
		ft_putchar_fd('-', 1);
		counter++;
		num = num * (-1);
	}
	else if (t_spec->space == true)
	{
		ft_putchar_fd(' ', 1);
		counter++;
	}
	if (len > 0)
		counter = print_num_prec(num, len, counter, t_spec);
	return (len + counter);
}

size_t	ft_print_d_width(int num, size_t len, size_t max, t_print *t_spec)
{
	if (!t_spec->dash)
	{
		if ((t_spec->zero == true) && (t_spec->precision == false))
			ft_print_zeros(t_spec->width_details - max);
		else
			ft_print_spaces(t_spec->width_details - max);
		len = print_num_withsign(num, len, t_spec);
	}
	else
	{
		len = print_num_withsign(num, len, t_spec);
		if ((t_spec->zero == true) && (t_spec->precision == false))
			ft_print_zeros(t_spec->width_details - max);
		else
			ft_print_spaces(t_spec->width_details - max);
	}
	return (t_spec->width_details);
}

int	print_d(int i, t_print *t_spec)
{
	int		num;
	size_t	len;
	size_t	max;

	num = va_arg(t_spec->args, int);
	len = ft_len_int(num);
	if ((num == 0) && (t_spec->precision_details == 0))
		len = 0;
	max = ft_maximum_sizet(2, len, t_spec->precision_details);
	if ((num < 0) || (t_spec->sign == true) || (t_spec->space == true))
		max++;
	if (!t_spec->precision)
		t_spec->precision_details = 1;
	if (t_spec->width_details > max)
		len = ft_print_d_width(num, len, max, t_spec);
	else
		len = print_num_withsign(num, len, t_spec);
	t_spec->len_total += len;
	return (i + 1);
}
