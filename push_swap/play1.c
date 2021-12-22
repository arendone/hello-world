/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:45:25 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/22 22:17:44 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print(t_stack **head)
{
	t_stack	*nextnum;

	if (*head != NULL)
	{
		printf("%d \n", (*head)->num);
		nextnum = (*head)->next;
		while (nextnum != *head)
		{
			printf("%d \n", nextnum->num);
			nextnum = nextnum->next;
		}
	}
	else
		printf("empty stack\n");
}

void	free_list(t_stack **head)
{
	t_stack	*temp_node;

	if (*head == NULL)
		return ;
	temp_node = ((*head)->prev);
	temp_node->next = NULL;
	while ((*head)->next)
	{
		temp_node = (*head)->next;
		free(*head);
		*head = temp_node;
	}
	free(*head);
	*head = NULL;
}

long long int	ft_atoi(const char *str)
{
	long long int	n;
	int				i;
	int				sign;

	n = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

int	check_rep(t_stack **heada, int numb)
{
	t_stack	*tem;

	if ((*heada) != NULL)
	{
		if (((*heada)->num) == numb)
			return (1);
		else
		{
			tem = ((*heada)->next);
			while (tem != (*heada))
			{
				if ((tem->num) == numb)
					return (1);
				tem = tem->next;
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	int				j;
	long long int	num;
	t_stack			*heada;
	t_stack			*headb;

	if (argc < 2)
		return (0);
	heada = NULL;
	headb = NULL;
	i = 0;
	while (i < (argc - 1))
	{
		j = 0;
		while (argv[i + 1][j])
		{
			if (argv[i + 1][j] < '0' || argv[i + 1][j] > '9')
			{
				if (j == 0 && (argv[i + 1][j] == '+' || argv[i + 1][j] == '-')
					&& (argv[i + 1][j + 1] >= '0' && argv[i + 1][j + 1] <= '9'))
					j++;
				else
				{
					write(1, "Error\n", 6);
					free_list(&heada);
					return (0);
				}
			}
			j++;
		}
		num = ft_atoi(argv[i + 1]);
		if (((num) < -2147483648) || ((num) > 2147483647)
			|| (check_rep(&heada, (int)num) == 1))
		{
			write(1, "Error\n", 6);
			free_list(&heada);
			return (0);
		}
		addAtEnd(&heada, (int)num);
		i++;
	}

	printf("\nstack A:\n");
	print(&heada);
	printf("\nstack B:\n");
	print(&headb);

	pre_sort(&heada, &headb);

	printf("\nstack A:\n");
	print(&heada);
	printf("\nstack B:\n");
	print(&headb);

	return (0);
}
