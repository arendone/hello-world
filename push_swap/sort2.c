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
    int     min2;
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

void	fill_flags(int max, t_subg *sg) //podemos disminuirlo a 3 flags, porque no importa la direccion, vamos a tomar siempre el nuevo min
{
	if (((sg->head_right) == max) || ((sg->head_left) == max))
		sg->flag1 = 1;
	else
		sg->flag1 = 0;
	if (((sg->next_right) == max) ||((sg->next_left) == max) )
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

void    send_subgroup(t_stack **pointer_heada, t_stack **pointer_headb, t_stack **mina)
{
    t_stack *heada;
    t_stack *nxa;
    t_stack *pra;
    int     min2;
    int     max;

    heada = (*pointer_heada);
    nxa = heada->next;
    pra = heada->prev;
    while ((*pointer_heada) != NULL)
    {
        if ((*mina) == (*pointer_heada))
        {
            pb(pointer_heada, pointer_headb);
            if ((*pointer_heada) == NULL)
            {
                printf("Ultimo elem de stack a");
                break;
            }
        }
        else if ((*mina) == nxa)
        {
            sa(pointer_heada);
            pb(pointer_heada, pointer_headb);
        }
        else if ((*mina) == pra)
        {
            rra(pointer_heada);
            pb(pointer_heada, pointer_headb);
        }
        heada = (*pointer_heada);
        nxa = heada->next;
        pra = heada->prev;
        max = maximum(4, heada->number, nxa->number, pra->number, (*pointer_headb)->number);
        if (((*pointer_headb)->number) == max)
        {
            printf("nada mas que pasar");
            break;
        }
        min2 = minimum2(3, (*pointer_headb)->number, heada->number, nxa->number, pra->number);
        if ((heada->number) == min2)
            mina = &heada;
        else if ((nxa->number) == min2)
            mina = &nxa;
        else if ((pra->number) == min2)
            mina = &pra;
    }
}

void    reverse(t_stack **pointer_heada, t_stack **pointer_headb, t_stack **mina)
{
    t_stack *headb;
    t_stack *nxb;

    headb = (*pointer_headb);
    nxb = headb->next;

    if ((*mina)->number) < (nxb->number)) //AQUI ME QUEDE!!!
}

void	sort(t_stack **pointer_heada, t_stack **pointer_headb)
{
	t_subg	*data;
    t_stack *heada;
    t_stack *nxa;
    t_stack *pra;
    int     min;
    int     min2;

	data = (t_subg *)malloc(sizeof(t_subg));
	data_subgroup(data, pointer_heada);

    heada = (*pointer_heada);
    nxa = heada->next;
    pra = heada->prev;

    min = minimum(3, heada->number, nxa->number, pra->number);
    min2 = minimum2(3, min, heada->number, nxa->number, pra->number);
    if (((heada->number) == min) && (data->flag1 == 1))
        send_subgroup(pointer_heada, pointer_headb, &heada);
    else if (((nxa->number) == min) && (data->flag2 == 1))
        send_subgroup(pointer_heada, pointer_headb, &nxa);
    else if (((pra->number) == min) && (data->flag3 == 1))
        send_subgroup(pointer_heada, pointer_headb, &pra);
    else if (((heada->number) == min2) && (data->flag1 == 1))
        send_subgroup(pointer_heada, pointer_headb, &heada);
    else if (((nxa->number) == min2) && (data->flag2 == 1))
        send_subgroup(pointer_heada, pointer_headb, &nxa);
    else if (((pra->number) == min2) && (data->flag3 == 1))
        send_subgroup(pointer_heada, pointer_headb, &pra);


    data_subgroup(data, pointer_heada);
    heada = (*pointer_heada);
    nxa = heada->next;
    pra = heada->prev;  
    min = minimum(3, heada->number, nxa->number, pra->number);
    min2 = minimum2(3, min, heada->number, nxa->number, pra->number);
    if (((heada->number) == min) && (data->flag1 == 1))
        send_subgroup(pointer_heada, pointer_headb, &heada);
    else if (((nxa->number) == min) && (data->flag2 == 1))
        send_subgroup(pointer_heada, pointer_headb, &nxa);
    else if (((pra->number) == min) && (data->flag3 == 1))
        send_subgroup(pointer_heada, pointer_headb, &pra);
    else if (((heada->number) == min2) && (data->flag1 == 1))
        send_subgroup(pointer_heada, pointer_headb, &heada);
    else if (((nxa->number) == min2) && (data->flag2 == 1))
        send_subgroup(pointer_heada, pointer_headb, &nxa);
    else if (((pra->number) == min2) && (data->flag3 == 1))
        send_subgroup(pointer_heada, pointer_headb, &pra);
	free (data);
}
