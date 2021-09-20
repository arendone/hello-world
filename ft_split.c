/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:30:01 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/20 14:25:33 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, int c)
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

char	**newarray(char const *s, char **split, char c)
{
	int	i;
	int	k;
	int	start;
	int	end;

	i = 0;
	k = 0;
	while (s[k] == c)
	{
		k++;
	}
	while (s[k] != '\0')
	{
		start = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		end = k;
		split[i] = ft_substr(s, start, end - start);
		i++;
		while (s[k] == c)
			k++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;
	char	*set;

	if (s == NULL)
		return (NULL);
	words = countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	if (words == 0)
	{
		split[0] = NULL;
		return (split);
	}
	set = &c;
	if (words == 1)
	{
		split[0] = ft_strtrim(s, set);
		split[1] = NULL;
		return (split);
	}
	else
		return (newarray(s, split, c));
}

/*deberia usar free despues de cada fallo en 
la acomodacion de memoria (luego de strtrim y substr) ?
luego free a split[i] y devolver null?*/