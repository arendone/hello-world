/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:36:51 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:37:37 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_info *push)
{
	sa(push);
}

void	sort_tree(t_info *push)
{
	t_stack	*nx;
	t_stack	*pr;

	nx = (push->heada)->next;
	pr = (push->heada)->prev;
	if ((((push->heada)->num) < nx->num) && (((push->heada)->num) < pr->num))
	{
		rra(push);
		sa(push);
	}
	else if ((((push->heada)->num) < (nx->num))
		&& (((push->heada)->num) > (pr->num)))
		rra(push);
	else if (((push->heada)->num) < (pr->num))
		sa(push);
	else if ((nx->num) > (pr->num))
	{
		ra(push);
		sa(push);
	}
	else
	{
		rra(push);
		rra(push);
	}
}

void	sort_four(t_info *push)
{
	t_stack	*nx;
	t_stack	*pr;

	nx = (push->heada)->next;
	pr = (push->heada)->prev;
	if (((nx->num) < ((push->heada)->num)) && ((nx->num) < (pr->num)))
	{
		sa(push);
		pb(push);
	}
	else if (((pr->num) < ((push->heada)->num)) && ((pr->num) < (nx->num)))
	{
		rra(push);
		pb(push);
	}
	else
		pb(push);
	if (if_orden_a(push, 3) == 0)
		sort_tree(push);
	pa(push);
	nx = (push->heada)->next;
	if (((push->heada)->num) > (nx->num))
		sa(push);
}

void	sort_five(t_info *push)
{
	t_stack	*nx;
	t_stack	*nxb;

	send_min(push);
	send_min(push);
	if (if_orden_a(push, 3) == 0)
		sort_tree(push);
	nxb = (push->headb)->next;
	if (((push->headb)->num) < (nxb->num))
		sb(push);
	pa(push);
	nx = (push->heada)->next;
	if (((push->heada)->num) > (nx->num))
		sa(push);
	pa(push);
	nx = (push->heada)->next;
	if (((push->heada)->num) > (nx->num))
		sa(push);
}

void	send_min(t_info *push)
{
	t_stack	*nx;
	t_stack	*pr;

	nx = (push->heada)->next;
	pr = (push->heada)->prev;
	if (((nx->num) < ((push->heada)->num)) && ((nx->num) < (pr->num)))
	{
		sa(push);
		pb(push);
	}
	else if (((pr->num) < ((push->heada)->num))
		&& ((pr->num) < (nx->num)))
	{
		rra(push);
		pb(push);
	}
	else
		pb(push);
}
