/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpymemmove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:22:47 by arendon-          #+#    #+#             */
/*   Updated: 2021/08/25 14:55:42 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, void *src, size_t len);

int	main(void)
{
	char	src[] = "Guten Tag *";
	char	dst[20];
	int		isrc[] = {10, 20, 30, 40, 50};
	int		n = sizeof(isrc)/sizeof(isrc[0]);
	int		idst[n], i;

	ft_memcpy(dst, src, 8);
	printf ("Copied string is: %s\n", dst);

	ft_memcpy(idst, isrc, sizeof(isrc));
	for(i = 0; i < n; i++)
		printf("%d ", idst[i]);

	ft_memmove(dst, src, 5);

	char csrc[100] = "Kartoffel";
	ft_memmove(csrc+5, csrc, strlen(csrc)+1);
	printf("\nmemmove: %s", csrc);

	char csrc3[100] = "Kartoffel";
	memmove(csrc3+5, csrc3, strlen(csrc3)+1);
	printf("\nmemmove: %s", csrc);


	char csrc2[100] = "Kartoffel";
	ft_memcpy(csrc2+5, csrc2, strlen(csrc2)+1);
	printf("\nmemcpy: %s\n", csrc2);

	char csrc4[100] = "Kartoffel";
	memcpy(csrc4+5, csrc4, strlen(csrc4)+1);
	printf("\nmemcpy: %s\n", csrc2);
	return (0);
}
