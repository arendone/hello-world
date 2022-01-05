/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorsandfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:19:59 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/04 22:38:06 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char **nums, t_info *push)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_freearray(nums);
	free_push(push);
	exit(1);
}

void	free_stack(t_stack *head, t_info *push)
{
	t_stack	*temp_node;
	t_stack	*prev;

	if (head == NULL)
		return ;
	prev = (head->prev);
	prev->next = NULL;
	while (head->next)
	{
		temp_node = head->next;
		free(head);
		push->size_a--;
		head = temp_node;
	}
	free(head);
	push->size_a--;
	head = NULL;
}

void	free_push(t_info *push)
{
	free_stack(push->heada, push);
	free_stack(push->headb, push);
	free(push);
	push = NULL;
}
