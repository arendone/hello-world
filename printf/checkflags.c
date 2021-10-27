/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:52:08 by arendon-          #+#    #+#             */
/*   Updated: 2021/10/27 16:36:21 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	flags_characters(char *format, int i, t_print *t_spec)
{
	while (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == ' ' || format[i] == '+' || format[i] == '*'
		|| (format[i] >= '0' && format[i] <= '9') || format[i] == '.')
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
		if (format[i] == '*')
			i = flag_width(format, i, t_spec);
		if (format[i] == '.')
			i = flag_precision(format, i, t_spec);
		i++;
	}
	return (i);
}

//funciones incompletas!!!!
int	flag_width(char *format, int i, t_print *t_spec)
{
	t_spec->width = true;
	/*if (format[i] == '*')
		//son 2 casos.... solo asterisco y hay que tomar el num de la lista y recorrer la lista o *m$ y hay que sacar a m 
		//para guardarla en t_spec->width_details
	
	if(format[i] >= '0' && format[i] <= '9')*/
		//convertir el num a int para saber t_spec->width_details
	
		//chechar otras condiciones y si hay mas caracteres que forman parte de esta no olvidar incrementar a la i (recuerda que ya se incrementa en 1) y si es necesario modificar a struct t_print
	return (i);
}

int	flag_precision(char *format, int i, t_print *t_spec)
{
	if (format[i] == '.')
		t_spec->precision = true;
		//chechar otras condiciones y si hay mas caracteres que forman parte de esta no olvidar incrementar a la i (recuerda que ya se incrementa en 1) y si es necesario modificar a struct t_print
	return (i);
}
