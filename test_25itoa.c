/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_25itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:27:34 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/14 11:52:49 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	str[12];

	//printf("%s \n", itoa(-0, str, 10));
	printf("%s \n", ft_itoa(-12345));
	printf("%s \n", ft_itoa(-0));
	printf("%s \n", ft_itoa(-2147483648));
	printf("%s \n", ft_itoa(-2147483640));
	printf("%s \n", ft_itoa(2147483647));
}