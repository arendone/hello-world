/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:29:45 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/04 16:52:18 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_orden_a(t_info *push, int numb)
{
	int			i;
	t_stack		*sig1;
	t_stack		*sig2;

	if (numb == 0 || numb == 1)
		return (1);
	sig1 = (push->heada);
	sig2 = sig1->next;
	i = 0;
	while (sig2 != (push->heada))
	{
		if ((sig1->num) < (sig2->num))
			i++;
		sig1 = sig2;
		sig2 = sig1->next;
	}
	if (i == (numb - 1))
		return (1);
	else
		return (0);
}

void	pre_sort(t_info *push)
{
	int		size;

	size = push->size_a;
	if (if_orden_a(push, size) == 0)
	{
		if (size == 2)
			sa(push);
		else if (size == 3)
			sort_tree(push);
		else if (size == 4)
			sort_four(push);
		else if (size == 5)
			sort_five(push);
		else
			algorithm_chunk(push);
	}
}
