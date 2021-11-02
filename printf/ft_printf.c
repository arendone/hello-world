/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:30:52 by arendon-          #+#    #+#             */
/*   Updated: 2021/11/02 12:36:32 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char *format, ...)
{
	int		i;
	int		count;
	t_print	*t_spec;

	t_spec = (t_print *)malloc(sizeof(t_print));
	if (!t_spec)
		return (-1);
	ft_spec_init(t_spec);
	va_start(t_spec->args, format);
	i = 0;
	count = print_format(format, i, t_spec);
	count += t_spec->len_total;
	va_end(t_spec->args);
	free(t_spec);
	return (count);
}
