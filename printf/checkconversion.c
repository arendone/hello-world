/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkconversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:07:11 by arendon-          #+#    #+#             */
/*   Updated: 2021/11/02 12:37:00 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_format(char *format, int i, t_print *t_spec)
{
	int	count;

	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			flags_characters(format, i, t_spec);
			while (ft_strchr("csdiupxX%", format[i]) == NULL)
				i++;
			i = check_conversion(format, i, t_spec);
			ft_spec_reset(t_spec);
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	return (count);
}

int	check_conversion(char *format, int i, t_print *t_spec)
{
	if (format[i] == 'd' || format[i] == 'i')
		i = print_d(i, t_spec);
	else if (format[i] == 'c')
		i = print_char(i, t_spec);
	else if (format[i] == 's')
		i = print_str(i, t_spec);
	else if (format[i] == '%')
	{
		ft_putchar_fd('%', 1);
		i++;
	}
	return (i);
}
