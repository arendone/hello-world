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
        write(1, "rra\n", 4);
		sa(ha);
        write(1, "ra\n", 3);
	}
	else if ((((*ha)->number) < (nx->number))
		&& (((*ha)->number) > (pr->number)))
    {
        rra(ha);
        write(1, "rra\n", 4);
    }
	else if (((*ha)->number) < (pr->number))
    {
        sa(ha);
        write(1, "sa\n", 3);
    }
	else if ((nx->number) > (pr->number))
	{
		ra(ha);
        write(1, "ra\n", 3);
		sa(ha);
        write(1, "sa\n", 3);
	}
	else
	{
		rra(ha);
        write(1, "rra\n", 4);
		rra(ha);
        write(1, "rra\n", 4);
	}
}

int if_orden(t_stack **ha, int num)
{
    int i;
    t_stack *sig1;
    t_stack *sig2;

    sig1 = (*ha);
    sig2 = sig1->next;
    i = 0;
    while(sig2 != (*ha))
    {
        if ((sig1->number) < (sig2->number))
            i++;
        sig1 = sig2;
        sig2 = sig1->next;
    }
    if (i == (num - 1))
        return (1);
    else
        return (0);
}

void	sort_four(t_stack **ha, t_stack **hb)
{
	t_stack	*nx;
	t_stack	*pr;
    int i = 2;

	nx = (*ha)->next;
	pr = (*ha)->prev;

    if (((nx->number) < ((*ha)->number)) && ((nx->number) < (pr->number)))
    {
        rra(ha);
        write(1, "rra\n", 4);
        pb(ha, hb);
        write(1, "pb\n", 3);
    }
    else if (((pr->number) < ((*ha)->number)) && ((pr->number) < (nx->number)))
    {
        sa(ha);
        write(1, "sa\n", 3);
        pb(ha, hb);
        write(1, "pb\n", 3);
    }
    else
    {
       pb(ha, hb);
       write(1, "pb\n", 3);
    }
    sort_tree(ha);
    pa(ha, hb);
    write(1, "pa\n", 3);
    nx = (*ha)->next;
    if(((*ha)->number) > (nx->number))
        sa(ha);
        write(1, "sa\n", 3);
}
/*
1234
1243
1324
1342
1423
1432

4312 : 3412, 
(x4) = 24

void	sort(t_stack **pointer_heada, t_stack **pointer_headb)
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