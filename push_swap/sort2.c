/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:45:35 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/16 21:31:28 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include <stdarg.h>
#include <stdio.h> //BORRALOOOOOOOOOO

int	maximum(int n, ...)
{
	int		i;
	int		val;
	int		largest;
	va_list	vl;

	va_start (vl, n);
	largest = va_arg(vl, int);
	i = 1;
	while (i < n)
	{
		val = va_arg(vl, int);
		if (largest < val)
			largest = val;
		i++;
	}
	va_end(vl);
	return (largest);
}

void	fill_flags(int max, t_subg *sg)
{
	if ((sg->head_right) == max)
		sg->flag1 = 1;
	else
		sg->flag1 = 0;
	if ((sg->head_left) == max)
		sg->flag2 = 1;
	else
		sg->flag2 = 0;
	if ((sg->next_right) == max)
		sg->flag3 = 1;
	else
		sg->flag3 = 0;
	if ((sg->next_left) == max)
		sg->flag4 = 1;
	else
		sg->flag4 = 0;
	if ((sg->prev_right) == max)
		sg->flag5 = 1;
	else
		sg->flag5 = 0;
	if ((sg->prev_left) == max)
		sg->flag6 = 1;
	else
		sg->flag6 = 0;
}

void	data_subgroup(t_subg *sg, t_stack **head)
{
	t_stack		*nx;
	t_stack		*pr;
	int			max;
	int			flag;

	nx = (*head)->next;
	pr = (*head)->prev;
	sg->head_right = count_right(head);
	sg->head_left = count_left(head);
	sg->next_right = count_right(&nx);
	sg->next_left = count_left(&nx);
	sg->prev_right = count_right(&pr);
	sg->prev_left = count_left(&pr);
	max = maximum(6, sg->head_right, sg->head_left, sg->next_right,
			sg->next_left, sg->prev_right, sg->prev_left);
	fill_flags(max, sg);
	printf("%d, %d, %d, %d, %d, %d \n", sg->head_right, sg->head_left,
		sg->next_right, sg->next_left, sg->prev_right, sg->prev_left);
	printf("%d, %d, %d, %d, %d, %d \n", sg->flag1, sg->flag2,
		sg->flag3, sg->flag4, sg->flag5, sg->flag6);
}

int	count_right(t_stack **node)
{
	int			i;
	t_stack		*sig1;
	t_stack		*sig2;

	sig1 = (*node);
	sig2 = sig1->next;
	i = 0;
	while ((sig1->number) < (sig2->number))
	{
		i++;
		sig1 = sig2;
		sig2 = sig1->next;
	}
	return (i);
}

int	count_left(t_stack **node)
{
	int			i;
	t_stack		*sig1;
	t_stack		*sig2;

	sig1 = (*node);
	sig2 = sig1->prev;
	i = 0;
	while ((sig1->number) < (sig2->number))
	{
		i++;
		sig1 = sig2;
		sig2 = sig1->prev;
	}
	return (i);
}

void	sort(t_stack **pointer_heada, t_stack **pointer_headb)
{
	t_subg	*data;

	data = (t_subg *)malloc(sizeof(t_subg));
	data_subgroup(data, pointer_heada);
	free (data);
}
