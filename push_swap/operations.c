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
#include <stdio.h> //QUITARLO

void	sa(t_stack *heada)
{
	t_stack	*first;
	t_stack	*second;
	int		first_num;

	//agregar funcion para contar num de elementos 
	//y no hacer nada si hay menos de 2
	first = heada;
	second = first->next;
	first_num = first->number;
	first->number = second->number;
	second->number = first_num;
}

void	sb(t_stack *headb)
{
	t_stack	*first;
	t_stack	*second;
	int		first_num;

	//agregar funcion para contar num de elementos 
	//y no hacer nada si hay menos de 2
	first = headb;
	second = first->next;
	first_num = first->number;
	first->number = second->number;
	second->number = first_num;
}

void	ss(t_stack *heada, t_stack *headb)
{
	sa(heada);
	sb(headb);
}

void	pa(t_stack	**pointer_heada, t_stack	**pointer_headb,t_stack *heada, t_stack *headb)
{
	t_stack	*last_stacka;
	t_stack	*new_heada;
	t_stack	*last_stackb;

	
	//AGREGAR <do nothing if b is empty>
	last_stacka = heada->prev;
    printf("last_stack: %d\n", last_stacka->number);
	new_heada = heada->next;
    printf("new_head: %d\n", new_heada);

	//close A
	last_stacka->next = new_heada;
    printf("last_stacka->next: %d\n", last_stacka->next);
	new_heada->prev = last_stacka;
    printf("new_heada->prev: %d\n", new_heada->prev);
	
    //add to stack b
	last_stackb->next = heada;
    heada->prev = last_stackb;
	headb->prev = heada;
	heada->next = headb;
	
    //pointer_heada = &new_heada;
    //pointer_headb = &heada;
}
