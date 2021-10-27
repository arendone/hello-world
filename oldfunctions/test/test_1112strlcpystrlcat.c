/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1112strlcpystrlcat.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:45:19 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/22 11:03:51 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	//funcion strlcpy
	char dst[30];
	char src[] = "123456789";

	ft_strlcpy(dst, src, 7);
	printf("Copia con ft: %s.\n", dst);
	printf("Valor devuelto: %lu\n", ft_strlcpy(dst, src, 7));
	strlcpy(dst, src, 7);
	printf("Copia con funcion original: %s.\n", dst);
	printf("Valor devuelto: %lu\n", strlcpy(dst, src, 7));

	char dst2[30];
	char src2[] = "123456789";

	ft_strlcpy(dst2, src2, 0);
	printf("Copia con ft: %s.\n", dst2);
	printf("Valor devuelto: %lu\n", ft_strlcpy(dst2, src2, 0));
	strlcpy(dst2, src2, 0);
	printf("Copia con funcion original: %s.\n", dst2);
	printf("Valor devuelto: %lu\n", strlcpy(dst2, src2, 0));
	
	//funcion strlcat
	size_t	len_dst;
	char src3[15]="concatenar";
	char dst3[20]="destino";
	char dst4[20]="destino";

	printf("str1 : %s, str2: %s\n", dst3, src3);
	printf("ft_buff = 18: %lu \n", ft_strlcat(dst3, src3, 18));
	
	printf("buff = 18: %lu \n", strlcat(dst4, src3, 18));

	printf("ft_buff = 0: %lu \n", ft_strlcat(dst3, src3, 0));
	printf("buff = 0: %lu \n", strlcat(dst3, src3, 0));
	
	printf("ft_buff = 5: %lu \n", ft_strlcat(dst3, src3, 5));
	printf("buff = 5: %lu \n", strlcat(dst3, src3, 5));
	
	return (0);
}
