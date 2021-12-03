/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:58:49 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/03 18:59:56 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *taila)
{
	t_stack	*first;
	t_stack	*second;
	int		first_num;

	//agregar funcion para contar num de elementos 
	//y no hacer nada si hay menos de 2
	first = taila;
	second = first->prev;
	first_num = first->number;
	first->number = second->number;
	second->number = first_num;
}

void	sb(t_stack *tailb)
{
	t_stack	*first;
	t_stack	*second;
	int		first_num;

	//agregar funcion para contar num de elementos 
	//y no hacer nada si hay menos de 2
	first = tailb;
	second = first->prev;
	first_num = first->number;
	first->number = second->number;
	second->number = first_num;
}

void	ss(t_stack *taila, t_stack *tailb)
{
	sa(taila);
	sb(tailb);
}

void	pa(t_stack *taila, t_stack *tailb)
{
	t_stack	*last_stacka;
	t_stack	*new_first_stacka;
	t_stack	*newteil_b;
	t_stack	*new_teilb;
	
	//do nothing if b is empty
	last_stacka = taila->next;
	new_first_stacka = taila->prev;
	newteil_b = taila;
	//close A
	last_stacka->prev = taila->prev;
	new_first_stacka->next = last_stacka;
	//add to stack b
	
	//last_stacka->prev = tailb;
	//last_stacka->next =*newteil_b;
	//*newteil_b->prev =last_stacka;
	//tailb->next =last_stacka;
}
