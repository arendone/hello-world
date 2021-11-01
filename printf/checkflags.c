/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:52:08 by arendon-          #+#    #+#             */
/*   Updated: 2021/10/29 19:15:30 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h> //BORRALOOOOO

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
		{
			flag_width(format, i, t_spec);
			while (ft_isdigit(format[i + 1]))
				i++;
		}
		if (format[i] == '.')
		{
			flag_precision(format, i + 1, t_spec);
			while (ft_isdigit(format[i + 1]))
				i++;
			if (format[i + 1] == '-')
				i++;
		}
		i++;
	}
	return (t_spec);
}

//funciones incompletas!!!!
void	*flag_width(char *format, int i, t_print *t_spec)
{
	size_t	width;

	width = 0;
	t_spec->width = true;
	//if (format[i] == '*')
	
		//son 2 casos.... solo asterisco y hay que tomar el num de la lista y recorrer la lista o *m$ y hay que sacar a m 
		//para guardarla en t_spec->width_details
	
	if (ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i]))
		{
			width = width * 10 + (format[i] - '0');
			i++;
		}
		t_spec->width_details = width;
	}
		//convertir el num a int para saber t_spec->width_details
	
		//chechar otras condiciones y si hay mas caracteres que forman parte de esta no olvidar incrementar a la i (recuerda que ya se incrementa en 1) y si es necesario modificar a struct t_print
	return (t_spec);
}

void	*flag_precision(char *format, int i, t_print *t_spec)
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
		//chechar otras condiciones y si hay mas caracteres que forman parte de esta no olvidar incrementar a la i (recuerda que ya se incrementa en 1) y si es necesario modificar a struct t_print
        //caso con *$
        //que pasa cuando hay prec negativo?
	return (t_spec);
}

/*while (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == ' ' || format[i] == '+' || format[i] == '*'
		|| ft_isdigit(format[i]) || format[i] == '.')*/