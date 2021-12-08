/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:30:48 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/07 22:04:58 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//# include "./libft/libft.h"
# include <stdlib.h>

typedef struct s_stack{
	struct s_stack	*prev;
	int				number;
	struct s_stack	*next;
}	t_stack;

t_stack	*addToEmpty(int number);
t_stack	**addAtEnd(t_stack **head, int number);
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
#endif