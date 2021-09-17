/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:55:40 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/16 13:41:04 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	printList(t_list *n)
{
	while (n != NULL)
	{
        printf(" %d ", *(int *)n->content);
        n = n->next;
    }
}

int main(void)
{
	t_list	*second = NULL;
	t_list	*third = NULL;
	t_list	*head = NULL;

	int a = 1;
	int b = 2;
	int c = 3;
 
    // allocate 3 nodes in the heap
    head = (t_list*)malloc(sizeof(t_list));
    second = (t_list*)malloc(sizeof(t_list));
    third = (t_list*)malloc(sizeof(t_list));

	head->content = &a;
	head->next = second;
	// assign data to second node
    second->content = &b;
 
    // Link second node with the third node
    second->next = third;
	third->content = &c; // assign data to third node
    third->next = NULL;

	printList(head);
	
	printf(" %d ", *(int *)(head->content));
	printf(" %d ", *(int *)second->content);
	printf(" %d ", *(int *)third->content);

	printf("alementos de la lista: %d \n", ft_lstsize(head));
	
	return (0);
}