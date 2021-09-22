/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:55:40 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/22 12:28:40 by arendon-         ###   ########.fr       */
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

void	*del(void *elem)
{
	elem = (void *)0;
	return (elem);
}
	/*ANOTHER WAY TO HAVE ACCESS TO THE ELEMENTS
	printf(" %d ", *(int *)(head->content));
	printf(" %d ", *(int *)second->content);
	printf(" %d ", *(int *)third->content);*/

int main(void)
{
	t_list	*second = NULL;
	t_list	*third = NULL;
	t_list	*head = NULL;
	t_list	*newelement = NULL;

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
 
    // allocate 3 nodes in the heap
    head = (t_list*)malloc(sizeof(t_list));
    second = (t_list*)malloc(sizeof(t_list));
    third = (t_list*)malloc(sizeof(t_list));

	head->content = &a;
	head->next = second;
    second->content = &b; // assign data to second node
    second->next = third;  // Link second node with the third node
	third->content = &c;
    third->next = NULL;

	printList(head);
	printf("| Elementos de la lista: %d \n", ft_lstsize(head));

	printf("| Elementos de la lista si es NULL: %d \n", ft_lstsize(newelement));
	newelement= ft_lstnew(&d);
	printList(newelement);
	printf("Elementos de la nueva lista: %d \n", ft_lstsize(newelement));

	ft_lstadd_back(&head, newelement);
	printList(head);
	printf("| Elementos de la lista con elemento anadido al final: %d \n", ft_lstsize(head));


	/*ft_lstclear(&third, del(third->content));
	printList(head);
	printf("| Elementos de la lista despues de borrar elemento (2): %d \n", ft_lstsize(head));
	*/
	free (head);
	free (second);
	free (third);
	free (newelement);
	return (0);
}