/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:16:59 by marvin            #+#    #+#             */
/*   Updated: 2021/11/11 14:18:43 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(long n)
{
	int	digits;

	digits = 1;
	if (n < 0)
		digits++;
	while (n / 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

int	ft_count_digits_base(long n, int base)
{
	int	digits;

	digits = 1;
	if (n < 0)
		digits++;
	while (n / base)
	{
		digits++;
		n /= base;
	}
	return (digits);
}
