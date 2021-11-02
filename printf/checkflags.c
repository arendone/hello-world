/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:52:08 by arendon-          #+#    #+#             */
/*   Updated: 2021/11/02 15:02:45 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*flags_characters(char *format, int i, t_print *t_spec)
{
	while (ft_strchr("csdiupxX%", format[i]) == NULL)
	{
		if (format[i] == '#')
			t_spec->number = true;
		if (format[i] == '0')
			t_spec->zero = true;
		if (format[i] == '-')
			t_spec->dash = true;
		if (format[i] == ' ')
			t_spec->space = true;
		if (format[i] == '+')
			t_spec->sign = true;
		if (ft_isdigit(format[i]))
			i = flag_width(format, i, t_spec);
		if (format[i] == '.')
			i = flag_precision(format, i + 1, t_spec);
		i++;
	}
	return (t_spec);
}

int	flag_width(char *format, int i, t_print *t_spec)
{
	size_t	width;

	width = 0;
	t_spec->width = true;
	if (ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i]))
		{
			width = width * 10 + (format[i] - '0');
			i++;
		}
		t_spec->width_details = width;
	}
	return (i - 1);
}

int	flag_precision(char *format, int i, t_print *t_spec)
{
	size_t	precision;

	t_spec->precision = true;
	precision = 0;
	if (ft_isdigit(format[i]))
	{
		precision = precision * 10 + (format[i] - '0');
		i++;
	}
	t_spec->precision_details = precision;
	return (i);
}
