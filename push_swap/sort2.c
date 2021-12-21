/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:45:35 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/22 00:10:13 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
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

int	minimum(int n, ...)
{
	int		i;
	int		val;
	int		min;
	va_list	vl;

	va_start (vl, n);
	min = va_arg(vl, int);
	i = 1;
	while (i < n)
	{
		val = va_arg(vl, int);
		if (min > val)
			min = val;
		i++;
	}
	va_end(vl);
	return (min);
}

int	minimum2(int n, ...)
{
	int		i;
	int		val;
	int		min;
	int		min2;
	va_list	vl;

	va_start (vl, n);
	min = va_arg(vl, int);
	min2 = va_arg(vl, int);
	i = 1;
	while (i < n)
	{
		val = va_arg(vl, int);
		if (min2 < min)
			min2 = val;
		if ((min2 > val) && (val > min))
		{
			min2 = val;
		}
		i++;
	}
	va_end(vl);
	return (min2);
}

void	fill_flags(int max, t_subg *sg)
{
	if (((sg->head_right) == max) || ((sg->head_left) == max))
		sg->flag1 = 1;
	else
		sg->flag1 = 0;
	if (((sg->next_right) == max) || ((sg->next_left) == max))
		sg->flag2 = 1;
	else
		sg->flag2 = 0;
	if (((sg->prev_right) == max) || ((sg->prev_left) == max))
		sg->flag3 = 1;
	else
		sg->flag3 = 0;
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
	printf("%d, %d, %d \n", sg->flag1, sg->flag2, sg->flag3);
}

int	count_right(t_stack **node)
{
	int			i;
	t_stack		*sig1;
	t_stack		*sig2;

	sig1 = (*node);
	sig2 = sig1->next;
	i = 0;
	while ((sig1->num) < (sig2->num))
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
	while ((sig1->num) < (sig2->num))
	{
		i++;
		sig1 = sig2;
		sig2 = sig1->prev;
	}
	return (i);
}

void	send_subgroup(t_stack **heada, t_stack **headb, t_stack **mina)
{
	t_stack	*nxa;
	t_stack	*pra;
	int		min2;
	int		max;

	nxa = (*heada)->next;
	pra = (*heada)->prev;
	while ((*heada) != NULL)
	{
		if ((*mina) == (*heada))
		{
			pb(heada, headb);
			if ((*heada) == NULL)
				break ;
		}
		else if ((*mina) == nxa)
		{
			sa(heada);
			pb(heada, headb);
		}
		else if ((*mina) == pra)
		{
			rra(heada);
			pb(heada, headb);
		}
		nxa = (*heada)->next;
		pra = (*heada)->prev;
		max = maximum(4, (*heada)->num, nxa->num, pra->num, (*headb)->num);
		if (((*headb)->num) == max)
			break ;
		min2 = minimum2(3, (*headb)->num, (*heada)->num, nxa->num, pra->num);
		if (((*heada)->num) == min2)
			mina = heada;
		else if ((nxa->num) == min2)
			mina = &nxa;
		else if ((pra->num) == min2)
			mina = &pra;
	}
}

void	send_back(t_stack **heada, t_stack **headb)
{
	t_stack	*nxb;
	t_stack	*prb;
	int		max;

	while ((*headb) != NULL)
	{
		nxb = (*headb)->next;
		prb = (*headb)->prev;
		max = maximum(3, (*headb)->num, nxb->num, prb->num);
		if (max == ((*headb)->num))
		{
			pa(heada, headb);
		}
		else if (max == nxb->num)
		{
			sb(headb);
			pa(heada, headb);
		}
		else if (max == prb->num)
		{
			rrb(headb);
			pa(heada, headb);
		}
	}
}

void	chose_subgroup(t_stack **heada, t_stack **headb, t_subg *data)
{
	t_stack	*nxa;
	t_stack	*pra;
	int		min;
	int		min2;

	data_subgroup(data, heada);
	nxa = (*heada)->next;
	pra = (*heada)->prev;
	min = minimum(3, (*heada)->num, nxa->num, pra->num);
	min2 = minimum2(3, min, (*heada)->num, nxa->num, pra->num);
	if ((((*heada)->num) == min) && (data->flag1 == 1))
		send_subgroup(heada, headb, heada);
	else if (((nxa->num) == min) && (data->flag2 == 1))
		send_subgroup(heada, headb, &nxa);
	else if (((pra->num) == min) && (data->flag3 == 1))
		send_subgroup(heada, headb, &pra);
	else if ((((*heada)->num) == min2) && (data->flag1 == 1))
		send_subgroup(heada, headb, heada);
	else if (((nxa->num) == min2) && (data->flag2 == 1))
		send_subgroup(heada, headb, &nxa);
	else if (((pra->num) == min2) && (data->flag3 == 1))
		send_subgroup(heada, headb, &pra);
}

//en esta funcion se pueden hacer mejoras al algoritmo pero se complica la funcion 
void	reverse(t_stack **pointer_heada, t_stack **pointer_headb, int mina)
{
	t_stack	*nxb;
	t_stack	*nxa;

	nxb = ((*pointer_headb)->next);
	if (mina < (nxb->num))
	{
		while (mina < (nxb->num) && (*pointer_headb != NULL))
		{
			pa(pointer_heada, pointer_headb);
			if (*pointer_headb != NULL)
				nxb = ((*pointer_headb)->next);
		}
	}
	if (((*pointer_headb != NULL) && ((*pointer_headb)->num) < (nxb->num)))
		sb(pointer_headb);
}

/*void	reverse(t_stack **pointer_heada, t_stack **pointer_headb, t_stack **mina)
{
	t_stack	*nxb;
	t_stack	*nxa;

	nxb = ((*pointer_headb)->next);
	if (((*mina)->num) < (nxb->num))
	{
		while (((*mina)->num) > (nxb->num))
		{
			pb(pointer_heada, pointer_headb);
			nxb = ((*pointer_headb)->next);
		}
	}
	else
	{
		pb(pointer_heada, pointer_headb); //tener cuidado con que headb sea null
		nxb = ((*pointer_headb)->next);
	}
	if (((*pointer_headb)->num) < (nxb->num))
	{
		nxa = ((*pointer_heada)->next);
		if (((*pointer_heada)->num) < (nxa->num))
			ss(pointer_heada, pointer_headb);
		else
		sb(pointer_headb);
	}
}*/

void	hide_min(t_stack **pointer_heada, t_subg *data)
{
	t_stack	*nxa;
	t_stack	*pra;
	int		min;
	int		min2;

	nxa = (*pointer_heada)->next;
	pra = (*pointer_heada)->prev;
	min = minimum(3, (*pointer_heada)->num, nxa->num, pra->num);
	min2 = minimum2(3, min, (*pointer_heada)->num, nxa->num, pra->num);
	if ((((*pointer_heada)->num) == min) && (data->flag1 == 1))
		ra(pointer_heada);//NOTA QUE PODRIA USAR RR en cada ra PERO NO MANDAR EL ULTIMO.
	else if (((nxa->num) == min) && (data->flag2 == 1))
	{
		sa(pointer_heada);
		ra(pointer_heada);
	}
	else if ((((*pointer_heada)->num) == min2) && (data->flag1 == 1))
		ra(pointer_heada);
	else if (((nxa->num) == min2) && (data->flag2 == 1))
	{
		sa(pointer_heada);
		ra(pointer_heada);
	}
}

void	sort(t_stack **pointer_heada, t_stack **pointer_headb)
{
	t_subg	*data;
	t_stack	*heada;
	t_stack	*nxa;
	t_stack	*pra;
	int		min;
	int		min2;

	data = (t_subg *)malloc(sizeof(t_subg));
	
	chose_subgroup(pointer_heada, pointer_headb, data);
	
	printf("\nstack A:\n");
	print(pointer_heada);
	printf("\nstack B:\n");
	print(pointer_headb);
	
	while ((*pointer_heada) != NULL)
	{
		printf("tenemos que esconder al min\n");
		data_subgroup(data, pointer_heada);
		hide_min(pointer_heada, data);

		printf("\nstack A:\n");
		print(pointer_heada);
		printf("\nstack B:\n");
		print(pointer_headb);

		heada = (*pointer_heada);
		nxa = heada->next;
		pra = heada->prev;
		printf("Reversa, para min \n");
		reverse(pointer_heada, pointer_headb, pra->num);
		printf("\nstack A:\n");
		print(pointer_heada);
		printf("\nstack B:\n");
		print(pointer_headb);

		chose_subgroup(pointer_heada, pointer_headb, data);
	}

	printf("\nstack A:\n");
	print(pointer_heada);
	printf("\nstack B:\n");
	print(pointer_headb);
	
	send_back(pointer_heada, pointer_headb);
	free (data);
	if (if_orden(pointer_heada, 30) == 0)
		sort(pointer_heada, pointer_headb);
}