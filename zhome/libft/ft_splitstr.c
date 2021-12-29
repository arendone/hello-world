#include "libft.h"

static char		*make_the_line(int j, char **av, char *p, int len_p)
{
	if (!(av[j] = (char*)malloc((len_p + 1) * sizeof(char))))
	{
		ft_mapdel(av, j - 1);
		return (NULL);
	}
	ft_strncpy(av[j], p, len_p);
	av[j][len_p] = '\0';
	return (av[j]);
}

static char		**split_it_for_me(const char *s, char c, int len_p, char **av)
{
	int			j;
	int			i;
	char		*p;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			i++;
		p = (char*)s + i;
		if (((unsigned char)s[i] != (unsigned char)c) && (s[i] != '\0'))
		{
			len_p = 0;
			while (((unsigned char)s[i] != (unsigned char)c) && s[i])
			{
				len_p++;
				i++;
			}
			make_the_line(j, av, p, len_p);
			j++;
		}
	}
	av[j] = 0;
	return (av);
}

static int		get_words_nb(const char *s, char c)
{
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if ((char)s[i] == c)
			i++;
		else
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (nb);
}

char			**ft_splitstr(char const *s, char c)
{
	char		**av;
	int			ac;
	int			len_p;

	if (!(s && c))
		return (NULL);
	len_p = 0;
	ac = get_words_nb(s, c);
	if (!(av = (char**)malloc((ac + 1) * (sizeof(char*)))))
		return (NULL);
	split_it_for_me(s, c, len_p, av);
	return (av);
}