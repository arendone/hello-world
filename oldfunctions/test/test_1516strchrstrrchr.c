/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1516strchrstrrchr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:17:54 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/23 11:50:53 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

#include "libft.h"

int	main(void)
{
	char str[8] = "saludos";

	//strchr
	printf("adress of first s: %p \n", ft_strchr(str, 'o' + 256));
	printf("adress of first s: %p \n", strchr(str, 'o' + 256));
	printf("adress of first e: %p \n", ft_strchr(str, 'e'));
	printf("adress of first e: %p \n", strchr(str, 'e'));
	printf("adress of first \\0: %p \n", ft_strchr(str, '\0'));
	printf("adress of first \\0: %p \n", strchr(str, '\0'));

	//strrchr
	printf("adress of last s: %p \n", ft_strrchr(str, 's'));
	printf("adress of last s: %p \n", strrchr(str, 's'));
	printf("adress of last e: %p \n", ft_strrchr(str, 'e'));
	printf("adress of last e: %p \n", strrchr(str, 'e'));
	printf("adress of last \\0: %p \n", ft_strrchr(str, '\0'));
	printf("adress of last \\0: %p \n", strrchr(str, '\0'));

	return (0);
}
