/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:58:49 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/16 12:18:29 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		*head = new;
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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	ss(t_stack **pointer_heada, t_stack **pointer_headb)
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
	if (*pointer_headb != NULL)
	{
		first = *pointer_headb;
		second = first->next;
		first_num = first->number;
		first->number = second->number;
		second->number = first_num;
	}
	write(1, "ss\n", 3);
}

void	pa(t_stack **pointer_heada, t_stack **pointer_headb)
{
	t_stack	*new_headb;
	t_stack	*last_stacka;
	t_stack	*last_stackb;

	if ((*pointer_headb != NULL))
	{
		new_headb = NULL;
		if (*pointer_headb != ((*pointer_headb)->next))
		{
			new_headb = (*pointer_headb)->next;
			last_stackb = (*pointer_headb)->prev;
			(last_stackb->next) = new_headb;
			(new_headb->prev) = last_stackb;
		}
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
	write(1, "pa\n", 3);
}

void	pb(t_stack **pointer_heada, t_stack **pointer_headb)
{
	//pa(pointer_headb, pointer_heada);
	t_stack	*new_heada;
	t_stack	*last_stacka;
	t_stack	*last_stackb;

	if ((*pointer_heada != NULL))
	{
		new_heada = NULL; //ANALIZAR QUE ONDA CON new_headb que deberia ser new_heada
		if (*pointer_heada != ((*pointer_heada)->next))
		{
			new_heada = (*pointer_heada)->next;
			last_stacka = (*pointer_heada)->prev;
			(last_stacka->next) = new_heada;
			(new_heada->prev) = last_stacka;
		}
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
	write(1, "pb\n", 3);
}

void	ra(t_stack **pointer_heada)
{
	t_stack	*temp;

	if (*pointer_heada != NULL)
	{
		temp = (*pointer_heada)->next;
		*pointer_heada = temp;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack **pointer_headb)
{
	t_stack	*temp;

	if (*pointer_headb != NULL)
	{
		temp = (*pointer_headb)->next;
		*pointer_headb = temp;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack **pointer_heada, t_stack **pointer_headb)
{
	t_stack	*temp;

	if (*pointer_heada != NULL)
	{
		temp = (*pointer_heada)->next;
		*pointer_heada = temp;
	}
	if (*pointer_headb != NULL)
	{
		temp = (*pointer_headb)->next;
		*pointer_headb = temp;
	}
	write(1, "rr\n", 3);
}

void	rra(t_stack **pointer_heada)
{
	t_stack	*temp;

	if (*pointer_heada != NULL)
	{
		temp = (*pointer_heada)->prev;
		*pointer_heada = temp;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack **pointer_headb)
{
	t_stack	*temp;

	if (*pointer_headb != NULL)
	{
		temp = (*pointer_headb)->prev;
		*pointer_headb = temp;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **pointer_heada, t_stack **pointer_headb)
{
	t_stack	*temp;

	if (*pointer_heada != NULL)
	{
		temp = (*pointer_heada)->prev;
		*pointer_heada = temp;
	}
	if (*pointer_headb != NULL)
	{
		temp = (*pointer_headb)->prev;
		*pointer_headb = temp;
	}
	write(1, "rrr\n", 4);
}
