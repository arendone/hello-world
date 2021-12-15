/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:29:45 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/15 20:42:31 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //BORRALOOOOOOOOOO

void	sort(t_stack **pointer_heada, t_stack **pointer_headb)
{
	t_stack	*next_stacka;
	t_stack	*last_stacka;

	next_stacka = (*pointer_heada)->next;
	last_stacka = (*pointer_heada)->prev;
	while ((*pointer_heada)->number != 9)
	{
		rra(pointer_heada);//algoritmo deberia decidir si rra o ra
	}
	pb(pointer_heada, pointer_headb);
	while (((*pointer_heada)->number) < ((*pointer_headb)->number))
	{
		pb(pointer_heada, pointer_headb);
		next_stacka = (*pointer_heada)->next;
		last_stacka = (*pointer_heada)->prev;
	}
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

/*void	sort(t_stack **pointer_heada, t_stack **pointer_headb)
{
    t_stack *last_stacka;
    //t_stack *first_stackb;

    rra(pointer_heada);
    pb(pointer_heada, pointer_headb);

    last_stacka = (*pointer_heada)->pr;

    while ((((*pointer_heada)->number) != (last_stacka->number)) && (last_stacka->number > (*pointer_headb)->number))
    {
        rra(pointer_heada);
        pb(pointer_heada, pointer_headb);
        last_stacka = (*pointer_heada)->pr;
    }
    printf("LAST: %d \n", last_stacka->number);
    while ((*pointer_headb != NULL) && ((*pointer_headb)->number) > (last_stacka->number))
    {
        pa(pointer_heada, pointer_headb);
    }
    rra(pointer_heada);
    pb(pointer_heada, pointer_headb);
}*/