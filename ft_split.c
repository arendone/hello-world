/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:30:01 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/09 18:42:45 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	countwords(char *s, int c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] != '\0' && s[i] == c)
	{
		i++;
	}
	if (s[i] != '\0')
		words = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if ((s[i + 1] != '\0') && (s[i + 1] != c))
				words++;
		}
		i++;
	}
	return (words);
}
//keep the words in an array
void	*newarray(char *s, int c)
{
	
}

/*
char	**ft_split(char const *s, char c)
{
	char	array[3][5];
	char 	**parray;
	int		i = 0;
	int		j = 0;
	size_t	k = 0;
	
	array = (char **)malloc(sizeof(char *) * 3);

	while (k < ft_strlen(s))
	{
		if (s[k] == c)
		{
			array[j][i] = s[k];
			j++;
			i = 0;
		}
		else
		{
			array[j][i] = s[k];
			//if (i == 0)
				//parray[j] = &array[j][0];
			i++;
		}
		k++;
	}
	return (array)
}
*/
int main (void)
{

	printf("words: %d\n", count("cuenta las palabras ", ' '));
	printf("words: %d\n", count("", ' '));
	printf("words: %d\n", count(" cuen    ta  las p a l a     bras   ", ' '));
	printf("words: %d\n", count("   cuenta las palabras    a", ' '));
	return (0);
}