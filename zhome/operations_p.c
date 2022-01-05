/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:37:21 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:38:18 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

void	pa(t_info *push)
{
	t_stack	*new_headb;
	t_stack	*last_stackb;

	if ((push->headb != NULL))
	{
		new_headb = NULL;
		if (push->headb != ((push->headb)->next))
		{
			new_headb = (push->headb)->next;
			last_stackb = (push->headb)->prev;
			(last_stackb->next) = new_headb;
			(new_headb->prev) = last_stackb;
		}
		((push->headb)->next) = push->headb;
		((push->headb)->prev) = push->headb;
		if (push->heada != NULL)
			close_p(push, 'a');
		push->heada = push->headb;
		push->headb = new_headb;
		push->size_a++;
		push->size_b--;
	}
	write(1, "pa\n", 3);
}

/*
** push b - take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void	pb(t_info *push)
{
	t_stack	*new_heada;
	t_stack	*last_stacka;

	if ((push->heada != NULL))
	{
		new_heada = NULL;
		if (push->heada != ((push->heada)->next))
		{
			new_heada = (push->heada)->next;
			last_stacka = (push->heada)->prev;
			(last_stacka->next) = new_heada;
			(new_heada->prev) = last_stacka;
		}
		((push->heada)->next) = push->heada;
		((push->heada)->prev) = push->heada;
		if (push->headb != NULL)
			close_p(push, 'b');
		push->headb = push->heada;
		push->heada = new_heada;
		push->size_a--;
		push->size_b++;
	}
	write(1, "pb\n", 3);
}

void	close_p(t_info *push, char c)
{
	t_stack	*last_stack;

	if (c == 'a')
	{
		last_stack = (push->heada)->prev;
		(last_stack->next) = (push->headb);
		((push->headb)->prev) = last_stack;
		((push->heada)->prev) = (push->headb);
		((push->headb)->next) = (push->heada);
	}
	else if (c == 'b')
	{
		last_stack = (push->headb)->prev;
		(last_stack->next) = (push->heada);
		((push->heada)->prev) = last_stack;
		((push->headb)->prev) = (push->heada);
		((push->heada)->next) = (push->headb);
	}
}
