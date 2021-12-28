/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:29:45 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/22 19:52:35 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //BORRALOOOOOOOOOO

int	if_orden(t_stack **ha, int numb)
{
	int			i;
	t_stack		*sig1;
	t_stack		*sig2;

	if (numb == 0 || numb == 1)
		return (1);
	sig1 = (*ha);
	sig2 = sig1->next;
	i = 0;
	while (sig2 != (*ha))
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
	if ((((*ha)->num) < (nx->num)) && (((*ha)->num) < (pr->num)))
	{
		rra(ha);
		sa(ha);
	}
	else if ((((*ha)->num) < (nx->num))
		&& (((*ha)->num) > (pr->num)))
		rra(ha);
	else if (((*ha)->num) < (pr->num))
		sa(ha);
	else if ((nx->num) > (pr->num))
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
	if (((nx->num) < ((*ha)->num)) && ((nx->num) < (pr->num)))
	{
		sa(ha);
		pb(ha, hb);
	}
	else if (((pr->num) < ((*ha)->num)) && ((pr->num) < (nx->num)))
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
	if (((*ha)->num) > (nx->num))
		sa(ha);
}

void	send_min(t_stack **ha, t_stack **hb)
{
	t_stack	*nx;
	t_stack	*pr;

	nx = (*ha)->next;
	pr = (*ha)->prev;
	if (((nx->num) < ((*ha)->num)) && ((nx->num) < (pr->num)))
	{
		sa(ha);
		pb(ha, hb);
	}
	else if (((pr->num) < ((*ha)->num))
		&& ((pr->num) < (nx->num)))
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
	if (((*hb)->num) < (nxb->num))
		sb(hb);
	pa(ha, hb);
	nx = (*ha)->next;
	if (((*ha)->num) > (nx->num))
		sa(ha);
	pa(ha, hb);
	nx = (*ha)->next;
	if (((*ha)->num) > (nx->num))
		sa(ha);
}
