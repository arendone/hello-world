/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:49:13 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:49:20 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** reverse rotate a - shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

void	rra(t_info *push)
{
	t_stack	*temp;

	if (push->heada != NULL)
	{
		temp = (push->heada)->prev;
		push->heada = temp;
	}
	write(1, "rra\n", 4);
}

/*
** reverse rotate b - shift down all elements of stack b by 1.
** The last element becomes the first one.
*/

void	rrb(t_info *push)
{
	t_stack	*temp;

	if (push->headb != NULL)
	{
		temp = (push->headb)->prev;
		push->headb = temp;
	}
	write(1, "rrb\n", 4);
}

/*
** rra and rrb at the same time.
*/

void	rrr(t_info *push)
{
	t_stack	*temp;

	if (push->heada != NULL)
	{
		temp = (push->heada)->prev;
		push->heada = temp;
	}
	if (push->headb != NULL)
	{
		temp = (push->headb)->prev;
		push->headb = temp;
	}
	write(1, "rrr\n", 4);
}
