/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:29:45 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/16 16:45:50 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //BORRALOOOOOOOOOO

int	if_orden(t_stack **ha, int num)
{
	int			i;
	t_stack		*sig1;
	t_stack		*sig2;

	sig1 = (*ha);
	sig2 = sig1->next;
	i = 0;
	while (sig2 != (*ha))
	{
		if ((sig1->number) < (sig2->number))
			i++;
		sig1 = sig2;
		sig2 = sig1->next;
	}
	if (i == (num - 1))
		return (i);
	else
		return (0);
}

void	sort_two(t_stack **ha)
{
	sa(ha);
}

//solo llamarla si hace falta ordenar
void	sort_tree(t_stack **ha)
{
	t_stack	*nx;
	t_stack	*pr;

	nx = (*ha)->next;
	pr = (*ha)->prev;
	if ((((*ha)->number) < (nx->number)) && (((*ha)->number) < (pr->number)))
	{
		rra(ha);
		sa(ha);
	}
	else if ((((*ha)->number) < (nx->number))
		&& (((*ha)->number) > (pr->number)))
		rra(ha);
	else if (((*ha)->number) < (pr->number))
		sa(ha);
	else if ((nx->number) > (pr->number))
	{
		ra(ha);
		sa(ha);
	}
	else
	{
		rra(ha);
		rra(ha);
	}
}

void	sort_four(t_stack **ha, t_stack **hb)
{
	t_stack	*nx;
	t_stack	*pr;

	nx = (*ha)->next;
	pr = (*ha)->prev;
	if (((nx->number) < ((*ha)->number)) && ((nx->number) < (pr->number)))
	{
		sa(ha);
		pb(ha, hb);
	}
	else if (((pr->number) < ((*ha)->number)) && ((pr->number) < (nx->number)))
	{
		rra(ha);
		pb(ha, hb);
	}
	else
		pb(ha, hb);
	if (if_orden(ha, 3) == 0)
		sort_tree(ha);
	pa(ha, hb);
	nx = (*ha)->next;
	if (((*ha)->number) > (nx->number))
		sa(ha);
}

void	send_min(t_stack **ha, t_stack **hb)
{
	t_stack	*nx;
	t_stack	*pr;

	nx = (*ha)->next;
	pr = (*ha)->prev;
	if (((nx->number) < ((*ha)->number)) && ((nx->number) < (pr->number)))
	{
		sa(ha);
		pb(ha, hb);
	}
	else if (((pr->number) < ((*ha)->number))
		&& ((pr->number) < (nx->number)))
	{
		rra(ha);
		pb(ha, hb);
	}
	else
		pb(ha, hb);
}

void	sort_five(t_stack **ha, t_stack **hb)
{
	t_stack	*nx;
	t_stack	*nxb;

	send_min(ha, hb);
	send_min(ha, hb);
	if (if_orden(ha, 3) == 0)
		sort_tree(ha);
	nxb = (*hb)->next;
	if (((*hb)->number) < (nxb->number))
		sb(hb);
	pa(ha, hb);
	nx = (*ha)->next;
	if (((*ha)->number) > (nx->number))
		sa(ha);
	pa(ha, hb);
	nx = (*ha)->next;
	if (((*ha)->number) > (nx->number))
		sa(ha);
}
