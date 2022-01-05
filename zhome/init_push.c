/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:20:22 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:32:01 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*init_push(void)
{
	t_info		*push;

	push = (t_info *)malloc(sizeof(t_info));
	if (push == NULL)
	{
		write(2, "No space left\n", 15);
		return (NULL);
	}
	push->heada = NULL;
	push->headb = NULL;
	push->size_a = 0;
	push->size_b = 0;
	push->size_chunk = 0;
	push->swap = false;
	return (push);
}

t_stack	*addToEmpty(int numb)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (NULL);
	temp->prev = temp;
	temp->num = numb;
	temp->flag = 0;
	temp->next = temp;
	return (temp);
}

t_stack	**addAtEnd(t_info *push, int numb)
{
	t_stack	**head;
	t_stack	*new;
	t_stack	*ex_new;

	new = addToEmpty(numb);
	head = &(push->heada);
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
