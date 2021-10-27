/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:55:40 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/23 15:26:09 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	printList(t_list *n)
{
	while (n != NULL)
	{
        printf(" %c ", *(char *)n->content);
        n = n->next;
    }
}

void	del(void *elem)
{
	free (elem);
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

    // allocate 3 nodes in the heap
    head = (t_list*)malloc(sizeof(t_list));
    second = (t_list*)malloc(sizeof(t_list));
    third = (t_list*)malloc(sizeof(t_list));

	head->content = ft_itoa(1);
	head->next = second;
    second->content = ft_itoa(2); // assign data to second node
    second->next = third;  // Link second node with the third node
	third->content = ft_itoa(3);
    third->next = NULL;

	printList(head);
	printf("| Elementos de la lista: %d \n", ft_lstsize(head));

	printf("| Elementos de la lista si es NULL: %d \n", ft_lstsize(newelement));
	newelement= ft_lstnew(ft_itoa(4));
	printList(newelement);
	printf("Elementos de la nueva lista: %d \n", ft_lstsize(newelement));

	ft_lstadd_back(&head, newelement);
	printList(head);
	printf("| Elementos de la lista con elemento anadido al final: %d \n", ft_lstsize(head));


	//ft_lstclear(&third, &del);
	printList(head);
	printf("| Elementos de la lista despues de borrar elemento (2): %d \n", ft_lstsize(head));
	
	free (head);
	free (second);
	//free (third);
	//free (newelement);
	return (0);
}