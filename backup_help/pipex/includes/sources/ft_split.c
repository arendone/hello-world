/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:18:30 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/02/19 20:01:54 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_size_one(char *s, char c)
{
	int	i;

	i = 1;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		if (*s == '\0')
			return (++i);
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (i);
		i++;
	}
	return (i);
}

static int	ft_word_len(char *str, char c)
{
	int	i;

	i = 0;
	while (*str != c && *str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

static char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*e;
	int		start;

	if (!s1 || !set)
		return (NULL);
	s = (char *)s1;
	start = 0;
	while (ft_strchr(set, *s) && *s)
	{
		start++;
		s++;
	}
	e = (char *)s1;
	while (*e)
		e++;
	if (e == s)
		return (ft_strdup(""));
	--e;
	while (ft_strchr(set, *(e)))
		e--;
	return (ft_substr(s1, start, (e - s + 1)));
}

static void	ft_extract(char **split, char *str, char c, int len)
{
	int	i;
	int	wlen;

	i = 0;
	while (i < len - 1)
	{
		wlen = ft_word_len(str, c);
		split[i] = (char *)ft_calloc(wlen + 1, sizeof(char));
		if (!split[i])
		{
			split = ft_free_tab(split);
			return ;
		}
		ft_memcpy(split[i], str, wlen);
		if (ft_strchr(str, c))
		{
			str = ft_strchr(str, c);
			while (*str == c)
				str++;
		}
		else
			str++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*str;
	int		i;
	int		len;
	char	set[2];

	split = NULL;
	if (s == NULL)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	str = ft_strtrim(s, set);
	if (!str)
		return (split);
	i = 0;
	len = ft_size_one(str, c);
	split = (char **)malloc(len * sizeof(char *));
	if (!split)
		return (split);
	while (i < len)
		split[i++] = NULL;
	ft_extract(split, str, c, len);
	free(str);
	return (split);
}
