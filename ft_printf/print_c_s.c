/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:47:53 by marvin            #+#    #+#             */
/*   Updated: 2021/11/05 11:50:51 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr_fd(char *s, int fd, int n);

int ft_print_str_width(char *str, int len, t_print *t_spec)
{
    if (!(t_spec->dash) && !(t_spec->zero))
    {
    	ft_print_spaces(t_spec->width_details - len);
    	ft_putnstr_fd(str, 1, len);
    }
    if (t_spec->dash)
    {
    	ft_putnstr_fd(str, 1, len);
    	ft_print_spaces(t_spec->width_details - len);
    }
    if (!(t_spec->dash) && (t_spec->zero))
    {
    	ft_print_zeros(t_spec->width_details - len);
    	ft_putnstr_fd(str, 1, len);
    }
    return (t_spec->width_details);
}

int	print_char(int i, t_print *t_spec)
{
	char	c;

	c = (char) va_arg(t_spec->args, int);
	if (t_spec->width && !(t_spec->dash))
		ft_print_spaces(t_spec->width_details - 1);
	ft_putchar_fd(c, 1);
	if (t_spec->width && t_spec->dash)
		ft_print_spaces(t_spec->width_details - 1);
	t_spec->len_total = t_spec->len_total
		+ ft_maximum_sizet(2, 1, t_spec->width_details);
	return (i + 1);
}

int	print_percentage(int i, t_print *t_spec)
{
	char	c;

	c = '%';
	if (t_spec->width && !(t_spec->dash))
		ft_print_spaces(t_spec->width_details - 1);
	ft_putchar_fd(c, 1);
	if (t_spec->width && t_spec->dash)
		ft_print_spaces(t_spec->width_details - 1);
	t_spec->len_total = t_spec->len_total
		+ ft_maximum_sizet(2, 1, t_spec->width_details);
	return (i + 1);
}

int	print_str(int i, t_print *t_spec)
{
	char	*str;
	size_t	len;

	str = va_arg(t_spec->args, char *);
	if (!str)
	{
        if (!(t_spec->precision))
		    len = 6;
        else
            len = ft_minimum_sizet(2, 6, t_spec->precision_details);
	    if (t_spec->width_details > len)
            len = ft_print_str_width("(null)", len, t_spec);
	    else
	    	ft_putnstr_fd("(null)", 1, len);
	    t_spec->len_total = t_spec->len_total + len;
    }
	else
	{
	    if (!(t_spec->precision))
		    len = ft_strlen(str);
        else
            len = ft_minimum_sizet(2, ft_strlen(str), t_spec->precision_details);
	    if (t_spec->width_details > len)
            len = ft_print_str_width(str, len, t_spec);
	    else
	    	ft_putnstr_fd(str, 1, len);
	    t_spec->len_total = t_spec->len_total + len;
    }
	return (i + 1);
}
