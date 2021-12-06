/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:45:25 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/03 19:00:12 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

t_stack	*addAtBeg(t_stack *head, int number)
{
	t_stack	*new;
	t_stack	*ex_new;

	new = addToEmpty(number);
	if (head == NULL)
		return (new);
	else
	{
		ex_new = head->prev;
		new->next = head;
		new->prev = ex_new;
		ex_new->next = new;
		head->prev = new;
		return (head);
	}
}

//print in reverse
void	print(t_stack **head)
{
	t_stack	*nextnum;
    t_stack *head_here;

    head_here = *head;

	printf("%d \n", head_here->number);
	nextnum = head_here->next;
	while (nextnum != head_here)
	{
		printf("%d \n", nextnum->number);
		nextnum = nextnum->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*heada;
	t_stack	*headb;
    t_stack	**pointer_heada;
	t_stack	**pointer_headb;

    pointer_heada = &heada;
    pointer_headb = &headb;

	heada = addToEmpty(45);
	heada = addAtBeg(heada, 34);
	heada = addAtBeg(heada, -17);
	heada = addAtBeg(heada, 0);
	heada = addAtBeg(heada, 42);

	headb = addToEmpty(8);
	headb = addAtBeg(headb, 3);
	headb = addAtBeg(headb, -97);
	headb = addAtBeg(headb, 4);
	headb = addAtBeg(headb, 29);
	printf("\nstack A:\n");
	print(pointer_heada);
	printf("\nstack B:\n");
	print(pointer_headb);
    /*
	sa(heada);
	printf("\nstack A after sa:\n");
	print(heada);
	sb(headb);
	printf("\nstack B after sb:\n");
	print(headb);
	ss(heada, headb);
	printf("\nstack A after ss:\n");
	print(heada);
	printf("\nstack B after ss:\n");
	print(headb);
    */
	pa(pointer_heada, pointer_headb, heada, headb);
	printf("\nstack A after pa:\n");
	print(pointer_heada);
	//printf("\nstack B after pa:\n");
	//print(pointer_headb);
	return (0);
}
