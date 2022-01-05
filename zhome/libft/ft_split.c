/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:30:01 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 01:01:14 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, char c)
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

static char	**clean(char **split, int n)
{
	while (n > 0)
	{
		free (split[n - 1]);
		n--;
	}
	free(split);
	split = NULL;
	return (NULL);
}

static char	*ft_mallocstr(char *ptr, char delim)
{
	int		i;
	char	*strptr;

	i = 0;
	while (ptr[i] != delim && ptr[i] != '\0')
		i++;
	strptr = (char *) malloc((i + 1) * sizeof(char));
	if (strptr == NULL)
		return (NULL);
	ft_strlcpy(strptr, ptr, i + 1);
	return (strptr);
}

static char	**write_to_arr(char const *str, char **arr, char c)
{
	int	i;
	int	k;
	int	flag;

	k = 0;
	i = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] == c)
			flag = 1;
		if ((str[i] != c) && (flag == 1))
		{
			arr[k] = (char *) ft_mallocstr(&((char *)str)[i], c);
			if (arr[k] == NULL)
			{
				clean(arr, k);
				return (NULL);
			}
			k++;
			flag = 0;
		}
		i++;
	}
	return (arr);
}

/*static char	**onewordarray(char const *s, char **split, char c)
{
	char	*set;

	set = &c;
	split[0] = ft_strtrim(s, set);
	if (split[0] == NULL)
		clean(split, 0);
	split[1] = NULL;
	return (split);
}*/

static char	**newarray(char const *s, char **split, char c)
{
	int	i;
	int	k;
	int	start;
	int	end;

	i = 0;
	k = 0;
	while (s[k] == c)
		k++;
	while (s[k] != '\0')
	{
		start = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		end = k;
		split[i] = ft_substr(s, start, end - start);
		if (split[i] == NULL)
			clean(split, i);
		i++;
		while (s[k] == c)
			k++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *str, char c)
{
	int		wordcount;
	char	**arr;

	if (str == NULL)
		return (NULL);
	wordcount = countwords(str, c);
	arr = malloc((wordcount + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[wordcount] = NULL;
	if (wordcount == 1)
	{
		return (write_to_arr(str, arr, c));
	}
	else
		return (newarray(str, arr, c));
	if (arr == NULL)
		return (NULL);
	return (arr);
}//ahora corre sin errores, cuando uso la funcion onearray tiene errores y
//cuando uso mi funcion con write_to_Array en lugar de mis funciones tambien hubo
//errores

/*char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;

	if (s == NULL)
		return (NULL);
	words = countwords(s, c);
	//split = (char **)malloc(sizeof(char *) * (words + 1));
	split = malloc((words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	//if (words == 0)
	//{
	//	split[0] = NULL;
	//	return (split);
	//}
	if (words == 1)
	{
		return (write_to_arr(s, split, c));
	}
	else
		return (write_to_arr(s, split, c));
}*/
