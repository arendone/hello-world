/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorsandfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:19:59 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/29 17:20:10 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char **nums, t_info *push)
{
	ft_putendl_fd("Error", 2);
	ft_freearray(nums);
	free_push(push);
	exit(1);
}

void	free_stack(t_stack *head)
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
		head = temp_node;
	}
	free(head);
	head = NULL;
}

void	free_push(t_info *push)
{
	free_stack(push->heada);
	free_stack(push->headb);
	free(push);
	push = NULL;
}
