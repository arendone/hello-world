/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpystrlcat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:45:19 by arendon-          #+#    #+#             */
/*   Updated: 2021/08/27 15:10:21 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
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
	
	return (0);
}
