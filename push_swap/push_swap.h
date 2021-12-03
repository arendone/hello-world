/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:30:48 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/03 18:31:14 by arendon-         ###   ########.fr       */
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

void	sa(t_stack *taila);
void	sb(t_stack *tailb);
void	ss(t_stack *taila, t_stack *tailb);
void	pa(t_stack *taila, t_stack *tailb);
#endif