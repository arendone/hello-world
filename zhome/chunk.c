/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:58:46 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:48:06 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_size_chunkcalculator(t_info *push)
{
	int	res;
	int	size;

	size = push->size_a;
	res = 0;
	if (push->size_a > 1)
	{
		res = ((3 * size) / 40) + (45 / 2);
		while (res % 5 != 0)
			res += 1;
	}
	push->size_chunk = res;
}

void	algorithm_createchuncks(t_info *push)
{
	int		i;
	int		j;
	t_stack	*tmp;

	algorithm_size_chunkcalculator(push);
	i = 0;
	j = 1;
	while (push->size_a != 0)
	{
		tmp = push->heada;
		if (tmp->num < (push->size_chunk * j))
		{
			pb(push);
			if (tmp->num < (push->size_chunk * j) - (push->size_chunk / 2)
				&& push->size_chunk > 25)
				rb(push);
			i++;
		}
		else
			ra(push);
		if (i == push->size_chunk * j)
			j++;
	}
}

void	algorithm_pushinorder(t_info *push)
{
	int	i;

	i = push->size_b;
	i--;
	while (i >= 0)
	{
		algorithm_putnumbertop(push, i);
		pa(push);
		i--;
		if (push->swap == true)
		{
			if ((push->size_b > 1)
				&& ((push->headb->num) < (push->headb->next->num)))
				ss(push);
			else
				sa(push);
			push->swap = false;
			i--;
		}
	}
	return ;
}

void	algorithm_chunk(t_info *push)
{
	normalization(push);
	algorithm_createchuncks(push);
	algorithm_pushinorder(push);
	return ;
}
