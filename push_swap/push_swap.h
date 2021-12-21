/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:30:48 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/21 23:52:28 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack{
	struct s_stack	*prev;
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_subg
{
	int	head_right;
	int	head_left;
	int	flag1;
	int	next_right;
	int	next_left;
	int	flag2;
	int	prev_right;
	int	prev_left;
	int	flag3;
}t_subg;

t_stack	*addToEmpty(int number);
t_stack	**addAtEnd(t_stack **head, int number);
void	print(t_stack **head);
void	sa(t_stack **pointer_heada);
void	sb(t_stack **pointer_headb);
void	ss(t_stack **pointer_heada, t_stack **pointer_headb);
void	pa(t_stack **pointer_heada, t_stack **pointer_headb);
void	pb(t_stack **pointer_heada, t_stack **pointer_headb);
void	ra(t_stack **pointer_heada);
void	rb(t_stack **pointer_headb);
void	rr(t_stack **pointer_heada, t_stack **pointer_headb);
void	rra(t_stack **pointer_heada);
void	rrb(t_stack **pointer_headb);
void	rrr(t_stack **pointer_heada, t_stack **pointer_headb);
void	sort_two(t_stack **ha);
void	sort_tree(t_stack **pointer_heada);
void	sort_four(t_stack **ha, t_stack **hb);
void	sort_five(t_stack **ha, t_stack **hb);
int		if_orden(t_stack **ha, int num);
int		count_left(t_stack **node);
int		count_right(t_stack **node);
int		maximum(int n, ...);
int		minimum(int n, ...);
int		minimum2(int n, ...);
void	data_subgroup(t_subg *sg, t_stack **head);
void	send_subgroup(t_stack **heada, t_stack **headb, t_stack **mina);
void	sort(t_stack **pointer_heada, t_stack **pointer_headb);
void	reverse(t_stack **pointer_heada, t_stack **pointer_headb, int mina);
void	hide_min(t_stack **pointer_heada, t_subg *data);
void	send_back(t_stack **heada, t_stack **headb);
#endif