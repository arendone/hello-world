/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2910putstrputnbr_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:05:19 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/22 10:15:28 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	ft_putstr_fd("numero extremo neg : ", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putstr_fd("\n numero extremo positivo: ", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putstr_fd("\n el 0: ", 1);
	ft_putnbr_fd(0, 1);
	ft_putstr_fd("\n numero cualquiera: ", 1);
	ft_putnbr_fd(-283648, 1);

	return (0);
}
