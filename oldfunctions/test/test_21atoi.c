/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_21atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:00:46 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/06 14:58:16 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str[16]= "-21474836481";
	printf("ft_atoi returns: %d\n", ft_atoi(str));

	char str2[10]= "+41934";
	printf("ft_atoi returns: %d\n", ft_atoi(str2));

	char str3[15]= "  -2147483648";
	printf("ft_atoi returns: %d\n", ft_atoi(str3));
	
	char str4[10]= "  419*a 3";
	printf("ft_atoi returns: %d\n", ft_atoi(str4));
 	
	char str5[10]= "  a419";
	printf("ft_atoi returns: %d\n", ft_atoi(str5));

	char tr[16]= "-21474836481";
	printf("ft_atoi returns: %d\n", atoi(tr));

	char tr2[10]= "+41934";
	printf("ft_atoi returns: %d\n", atoi(tr2));

	char tr3[15]= "  -2147483648";
	printf("ft_atoi returns: %d\n", atoi(tr3));
	
	char tr4[10]= "  419*a 3";
	printf("ft_atoi returns: %d\n", atoi(tr4));
 	
	char tr5[10]= "  a419";
	printf("ft_atoi returns: %d\n", atoi(tr5));

	return (0);
}
