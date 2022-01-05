/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:24:43 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/04 16:32:54 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** swap a - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements.
*/

void	sa(t_info *push)
{
	t_stack	*first;
	t_stack	*second;
	int		first_num;

	if ((push->heada != NULL) && (push->size_a > 1))
	{
		first = push->heada;
		second = first->next;
		first_num = first->num;
		first->num = second->num;
		second->num = first_num;
	}
	write(1, "sa\n", 3);
}

/*
** swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements.
*/

void	sb(t_info *push)
{
	t_stack	*first;
	t_stack	*second;
	int		first_num;

	if ((push->headb != NULL) && (push->size_b > 1))
	{
		first = push->headb;
		second = first->next;
		first_num = first->num;
		first->num = second->num;
		second->num = first_num;
	}
	write(1, "sb\n", 3);
}

/*
** sa and sb at the same time.
*/

void	ss(t_info *push)
{
	t_stack	*first;
	t_stack	*second;
	int		first_num;

	if ((push->heada != NULL) && (push->size_a > 1))
	{
		first = push->heada;
		second = first->next;
		first_num = first->num;
		first->num = second->num;
		second->num = first_num;
	}
	if ((push->headb != NULL) && (push->size_b > 1))
	{
		first = push->headb;
		second = first->next;
		first_num = first->num;
		first->num = second->num;
		second->num = first_num;
	}
	write(1, "ss\n", 3);
}
