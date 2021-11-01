/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:16:20 by marvin            #+#    #+#             */
/*   Updated: 2021/11/01 17:16:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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