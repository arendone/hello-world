/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:12:13 by arendon-          #+#    #+#             */
/*   Updated: 2021/10/29 17:49:50 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_print
{
	va_list	args;
	bool	dash;
	bool	zero;
	bool	number;
	bool	space;
	bool	sign;
	bool	width;
	size_t		width_details;
	bool	precision;
	size_t		precision_details;
	int		len_total;
}t_print;

t_print	*ft_spec_init(t_print *t_spec);
t_print	*ft_spec_reset(t_print *t_spec);
void	*flags_characters(char *format, int i, t_print *t_spec);
void	*flag_width(char *format, int i, t_print *t_spec);
void	*flag_precision(char *format, int i, t_print *t_spec);
int		print_char(int i, t_print *t_spec);
int		print_str(int i, t_print *t_spec);
int print_d(int i, t_print *t_spec);
int	ft_print_zeros(int zeros);
int	ft_print_spaces(int spaces);

#endif