/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:49:01 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:49:03 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotate a - shift up all elements of stack a by 1. The first element becomes
** the last one.
*/

void	ra(t_info *push)
{
	t_stack	*temp;

	if (push->heada != NULL)
	{
		temp = (push->heada)->next;
		push->heada = temp;
	}
	write(1, "ra\n", 3);
}

/*
** rotate b - shift up all elements of stack b by 1. The first element becomes
** the last one.
*/

void	rb(t_info *push)
{
	t_stack	*temp;

	if (push->headb != NULL)
	{
		temp = (push->headb)->next;
		push->headb = temp;
	}
	write(1, "rb\n", 3);
}

/*
** ra and rb at the same time.
*/

void	rr(t_info *push)
{
	t_stack	*temp;

	if (push->heada != NULL)
	{
		temp = (push->heada)->next;
		push->heada = temp;
	}
	if (push->headb != NULL)
	{
		temp = (push->headb)->next;
		push->headb = temp;
	}
	write(1, "rr\n", 3);
}
