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
	int		width_details;
	bool	precision;
	size_t		precision_details;
	int		len_total;
}t_print;

t_print	*ft_spec_init(t_print *t_spec);
t_print	*ft_spec_reset(t_print *t_spec);
void	*flags_characters(char *format, int i, t_print *t_spec);
void	*flag_width(char *format, int i, t_print *t_spec);
void	*flag_precision(char *format, int i, t_print *t_spec);
int		ft_print_char(char *format, int i, t_print *t_spec);
int		ft_print_str(char *format, int i, t_print *t_spec);

#endif