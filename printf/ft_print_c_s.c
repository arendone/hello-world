/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:47:53 by marvin            #+#    #+#             */
/*   Updated: 2021/10/29 19:17:04 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h> //BORRALOOOOO

int	ft_maximoint(int n, ...);

int	ft_print_spaces(int spaces)
{
	int	j;

	j = 0;
	while (j < spaces)
	{
		ft_putchar_fd(' ', 1);
		j++;
	}
	return (spaces);
}

int	ft_print_zeros(int zeros)
{
	int	j;

	j = 0;
	while (j < zeros)
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

int	ft_print_char(char *format, int i, t_print *t_spec)
{
	char	c;

	c = (char) va_arg(t_spec->args, int);
	if (t_spec->width && !(t_spec->dash))
		ft_print_spaces(t_spec->width_details - 1);
	ft_putchar_fd(c, 1);
	if (t_spec->width && t_spec->dash)
		ft_print_spaces(t_spec->width_details - 1);
	t_spec->len_total = t_spec->len_total
		+ ft_maximoint(2, 1, t_spec->width_details);
	return (i + 1);
}

int	ft_print_str(char *format, int i, t_print *t_spec)
{
	char	*str;
	size_t	len;

	str = va_arg(t_spec->args, char *);
	if (str)
		len = ft_strlen(str);
	else
	{
		str = "(null)";
		len = 6;
	}
	if ((t_spec->precision) && (t_spec->precision_details < len))
	{
		str = ft_substr(str, 0, t_spec->precision_details);
		len = t_spec->precision_details;
	}
	if (t_spec->width_details > len)
	{
		if (!(t_spec->dash) && !(t_spec->zero))
		{
			ft_print_spaces(t_spec->width_details - len);
			ft_putstr_fd(str, 1);
		}
		if (t_spec->dash)
		{
			ft_putstr_fd(str, 1);
			ft_print_spaces(t_spec->width_details - len);
		}
		if (!(t_spec->dash) && (t_spec->zero))
		{
			ft_print_zeros(t_spec->width_details - len);
			ft_putstr_fd(str, 1);
		}
	}
	else
	{
		ft_putstr_fd(str, 1);
	}
	//free (str);
	t_spec->len_total = t_spec->len_total
		+ ft_maximoint(2, len, t_spec->width_details);
	return (i + 1);
}

          /*QUE PASA SI WIDTH ES MENOR QUE 6 Y PRECISION MENOR QUE 6 Y STR ES NULL?????
          */
