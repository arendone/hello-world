/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:41:30 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/27 16:53:48 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief  ft_memset of libft (but static)
 * @note
 * @param  *b: the pointer whose values to set
 * @param  c: the ascii to set it to (converted to an unsigned char)
 * @param  n: the number of characters to set
 * @retval its first argument
 */
static void	*ft_memset(void *s, int c, size_t n)
{
	char	*buf;

	buf = s;
	while (n > 0)
	{
		*buf = c;
		buf++;
		n--;
	}
	return (s);
}

/**
 * @brief  ft_calloc of libft
 * @note
 * @param  count: number of elements
 * @param  size: the size of each element
 * @retval the pointer to the allocated memory or NULL if allocation failed
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*pr;

	pr = malloc(count * size);
	if (pr == NULL)
		return (NULL);
	return (ft_memset(pr, 0, (count * size)));
}

/**
 * @brief  print instruccions
 * @note   with colors
 * @retval only exists to save some lines
 */
int	print_error(void)
{
	printf("Wrong input!\nPlease use like: '\
\033[0;37m./philo\033[0;31m a\033[0;32m b\033[0;33m c\
\033[0;34m d\033[0;35m e\
\n\033[0;31ma = [number_of_philosophers]\n\033[0;32mb = [time_to_die]\
\n\033[0;33mc = [time_to_eat]\n\033[0;34md = [time_to_sleep]\
\n\033[0;35me = [number_of_times_each_philosopher_must_eat]\
\n\033[0;37m*Every value but \033[0;35me\033[0;37m is mandatory.\n");
	return (EXIT_FAILURE);
}

