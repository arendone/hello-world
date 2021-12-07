/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:58:49 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/07 17:12:21 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //QUITARLO

t_stack	*addToEmpty(int number)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (temp == NULL)
		return (NULL);
	temp->prev = temp;
	temp->number = number;
	temp->next = temp;
	return (temp);
}

t_stack	**addAtEnd(t_stack **head, int number)
{
	t_stack	*new;
	t_stack	*ex_new;

	new = addToEmpty(number);
	if (*head == NULL)
	{
		head = &new;
		return (head);
	}
	else
	{
		ex_new = (*head)->prev;
		new->next = *head;
		new->prev = ex_new;
		ex_new->next = new;
		(*head)->prev = new;
		return (head);
	}
}

void	sa(t_stack **pointer_heada)
{
	t_stack	*first;
	t_stack	*second;
	int		first_num;

	if (*pointer_heada != NULL)
	{
		first = *pointer_heada;
		second = first->next;
		first_num = first->number;
		first->number = second->number;
		second->number = first_num;
	}
}

void	sb(t_stack **pointer_headb)
{
	t_stack	*first;
	t_stack	*second;
	int		first_num;

	if (*pointer_headb != NULL)
	{
		first = *pointer_headb;
		second = first->next;
		first_num = first->number;
		first->number = second->number;
		second->number = first_num;
	}
}

void	ss(t_stack **pointer_heada, t_stack **pointer_headb)
{
	sa(pointer_heada);
	sb(pointer_headb);
}

void	pa(t_stack **pointer_heada, t_stack **pointer_headb)
{
	t_stack	*new_headb;
	t_stack	*last_stacka;
	t_stack	*last_stackb;

	if ((*pointer_headb != NULL))
	{
		if (*pointer_headb != ((*pointer_headb)->next))
		{
			new_headb = (*pointer_headb)->next;
			last_stackb = (*pointer_headb)->prev;
			(last_stackb->next) = new_headb;
			(new_headb->prev) = last_stackb;
		}
		else
			new_headb = NULL;
		((*pointer_headb)->next) = *pointer_headb;
		((*pointer_headb)->prev) = *pointer_headb;
		if (*pointer_heada != NULL)
		{
			last_stacka = (*pointer_heada)->prev;
			(last_stacka->next) = (*pointer_headb);
			((*pointer_headb)->prev) = last_stacka;
			((*pointer_heada)->prev) = (*pointer_headb);
			((*pointer_headb)->next) = (*pointer_heada);
		}
		*pointer_heada = *pointer_headb;
		*pointer_headb = new_headb;
	}
}

void	pb(t_stack **pointer_heada, t_stack **pointer_headb)
{
	t_stack	*new_heada;
	t_stack	*last_stacka;
	t_stack	*last_stackb;

	if ((*pointer_heada != NULL))
	{
		if (*pointer_heada != ((*pointer_heada)->next))
		{
			new_heada = (*pointer_heada)->next;
			last_stacka = (*pointer_heada)->prev;
			(last_stacka->next) = new_heada;
			(new_heada->prev) = last_stacka;
		}
		else
			new_heada = NULL;
		((*pointer_heada)->next) = *pointer_heada;
		((*pointer_heada)->prev) = *pointer_heada;
		if (*pointer_headb != NULL)
		{
			last_stackb = (*pointer_headb)->prev;
			(last_stackb->next) = (*pointer_heada);
			((*pointer_heada)->prev) = last_stackb;
			((*pointer_headb)->prev) = (*pointer_heada);
			((*pointer_heada)->next) = (*pointer_headb);
		}
		*pointer_headb = *pointer_heada;
		*pointer_heada = new_heada;
	}
}


