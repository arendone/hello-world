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

t_stack	*addAtBeg(t_stack *tail, int number)
{
	t_stack	*new;
	t_stack	*ex_new;

	new = addToEmpty(number);
	if (tail == NULL)
		return (new);
	else
	{
		ex_new = tail->next;
		new->prev = tail;
		new->next = ex_new;
		ex_new->prev = new;
		tail->next = new;
		return (tail);
	}
}

//print in reverse
void	print(t_stack *tail)
{
	t_stack	*nextnum;

	printf("%d \n", tail->number);
	nextnum = tail->prev;
	while (nextnum != tail)
	{
		printf("%d \n", nextnum->number);
		nextnum = nextnum->prev;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*taila;
	t_stack	*tailb;

	taila = addToEmpty(45);
	taila = addAtBeg(taila, 34);
	taila = addAtBeg(taila, -17);
	taila = addAtBeg(taila, 0);
	taila = addAtBeg(taila, 42);

	tailb = addToEmpty(8);
	tailb = addAtBeg(tailb, 3);
	tailb = addAtBeg(tailb, -97);
	tailb = addAtBeg(tailb, 4);
	tailb = addAtBeg(tailb, 29);
	printf("\nstack A:\n");
	print(taila);
	printf("\nstack B:\n");
	print(tailb);
	sa(taila);
	printf("\nstack A after sa:\n");
	print(taila);
	sb(tailb);
	printf("\nstack B after sb:\n");
	print(tailb);
	ss(taila, tailb);
	printf("\nstack A after ss:\n");
	print(taila);
	printf("\nstack B after ss:\n");
	print(tailb);
	pa(taila, tailb);
	printf("\nstack A after pa:\n");
	print(taila);
	//printf("\nstack B after pa:\n");
	//print(tailb);
	//recorrer hacia adelante 1
	/*taila = taila->next;
	print(taila);
	//recorrer hacia adelante 1 otra vez
	taila = taila->next;
	print(taila);
	//recorrer hacia atras
	taila = taila->prev;
	print(taila);*/
	return (0);
}
