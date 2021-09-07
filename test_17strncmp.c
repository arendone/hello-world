/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_17strncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:12:34 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/02 13:13:07 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

#include "libft.h"

int	main(void)
{
    printf ("Return: %d \n", ft_strncmp("hola", "hola", 3));	
	printf ("Return: %d \n", strncmp("hola", "hola", 3));

    printf ("Return: %d \n", ft_strncmp("hoLa", "hola", 3));	
	printf ("Return: %d \n", strncmp("hoLa", "hola", 3));

    printf ("Return: %d \n", ft_strncmp("ho ", "hola", 3));	
	printf ("Return: %d \n", strncmp("ho ", "hola", 3));

    printf ("Return: %d \n", ft_strncmp("ho\0la", "ho\0La", 5));	
	printf ("Return: %d \n", strncmp("ho\0la", "ho\0La", 5));
}