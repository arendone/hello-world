/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_17strncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:12:34 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/08 11:22:54 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

#include "libft.h"

int	main(void)
{
    printf ("Return: %d \n", ft_strncmp("ho", "hola", 3));	
	printf ("Return: %d \n", strncmp("ho", "hola", 3));

    printf ("Return: %d \n", ft_strncmp("hola", "hoLa", 3));	
	printf ("Return: %d \n", strncmp("hola", "hoLa", 3));

    printf ("Return: %d \n", ft_strncmp("ho ", "hola", 3));	
	printf ("Return: %d \n", strncmp("ho ", "hola", 3));

    printf ("Return: %d \n", ft_strncmp("ho\0la", "ho\0La", 5));	
	printf ("Return: %d \n", strncmp("ho\0la", "ho\0La", 5));
}