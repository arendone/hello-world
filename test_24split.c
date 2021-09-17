/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_24split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:18:17 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/17 14:26:04 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main (void)
{
	char **split;
	int i = 0;
	char s[10]= " cuenta  ";
	split = ft_split(s, ' ');
	while(split[i] != NULL)
	{
		printf("%s", *(split + i));
		i++;
	}
	free (split);
	/*
	printf("words: %d\n", countwords("", ' '));
	printf("words: %d\n", countwords(" cuen    ta  las p a l a     bras   ", ' '));
	printf("words: %d\n", countwords("   cuenta las palabras    a", ' '));*/
	return (0);
}
