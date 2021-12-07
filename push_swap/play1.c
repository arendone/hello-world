/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:45:25 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/07 17:18:25 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//print in reverse
void	print(t_stack **head)
{
	t_stack	*nextnum;

	if (*head != NULL)
	{
		printf("%d \n", (*head)->number);
		nextnum = (*head)->next;
		while (nextnum != *head)
		{
			printf("%d \n", nextnum->number);
			nextnum = nextnum->next;
		}
	}
	else
		printf("empty stack");
}

int	main(int argc, char **argv)
{
	t_stack	*heada;
	t_stack	*headb;
	t_stack	**pointer_heada;
	t_stack	**pointer_headb;

	heada = NULL;
	headb = NULL;
	pointer_heada = &heada;
	pointer_headb = &headb;

	heada = addToEmpty(45);
	pointer_heada = addAtEnd(pointer_heada, 34);
	pointer_heada = addAtEnd(pointer_heada, -17);
	pointer_heada = addAtEnd(pointer_heada, 0);
	pointer_heada = addAtEnd(pointer_heada, 42);

	headb = addToEmpty(8);
	/*pointer_headb = addAtEnd(pointer_headb, 3);
	pointer_headb = addAtEnd(pointer_headb, -97);
	pointer_headb = addAtEnd(pointer_headb, 4);
	pointer_headb = addAtEnd(pointer_headb, 29);*/
	printf("\nstack A:\n");
	print(pointer_heada);
	printf("\nstack B:\n");
	print(&headb);

	sa(pointer_heada);
	printf("\nstack A after sa:\n");
	print(pointer_heada);
	sb(pointer_headb);
	printf("\nstack B after sb:\n");
	print(pointer_headb);
	ss(pointer_heada, pointer_headb);
	printf("\nstack A after ss:\n");
	print(pointer_heada);
	printf("\nstack B after ss:\n");
	print(pointer_headb);
	pa(pointer_heada, pointer_headb);
	printf("\nstack A after pa:\n");
	print(pointer_heada);
	printf("\nstack B after pa:\n");
	print(pointer_headb);
	pb(pointer_heada, pointer_headb);
	printf("\nstack A after pb:\n");
	print(pointer_heada);
	printf("\nstack B after pb:\n");
	print(pointer_headb);
	return (0);
}
