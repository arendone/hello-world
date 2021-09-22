/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_3strtrim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:56:11 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/22 15:50:12 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main()
{
	printf("%s.\n", ft_strtrim(" hola camaradas ", " s"));
	printf("%s.\n", ft_strtrim("", " s"));
	printf("%s.\n", ft_strtrim("hola camaradas ", "h"));
	printf("%s.\n", ft_strtrim(" hola camaradas ", "a"));
	printf("%s.\n", ft_strtrim(" hola camaradas ", "  "));
	printf("%s.\n", ft_strtrim(NULL, " "));
}
