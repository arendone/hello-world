/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:30:48 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:53:52 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# include "./libft/libft.h"

typedef struct s_stack{
	struct s_stack	*prev;
	int				num;
	int				flag;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	t_stack	*heada;
	t_stack	*headb;
	int		size_a;
	int		size_b;
	int		size_chunk;
	bool	swap;
}t_info;

# define INT_MAX (2147483647)
# define INT_MIN (-2147483648)

/*
** ------------------------------- Common functions ---------------------------
*/

/*
** String check in file check_string_argv.c
*/

int		atoi_push_swap(char *str, char **nums, t_info *push);
int		check_rep(t_info *push, int numb);
int		invalid_argv(char *argv, t_info *push, size_t i);
void	checkandadd(t_info *push, char **nu, size_t i);

/*
** Malloc and initiation for t_info push and t_stacks
** in file init_push.c
*/

t_info	*init_push(void);
t_stack	*addToEmpty(int numb);
t_stack	**addAtEnd(t_info *push, int numb);

/*
** Operations in the project - files operations_p.c,
** operations_r.c, operations_rr.c, operations_s.c
*/

void	sa(t_info *push);
void	sb(t_info *push);
void	ss(t_info *push);

void	pa(t_info *push);
void	pb(t_info *push);
void	close_p(t_info *push, char c);

void	ra(t_info *push);
void	rb(t_info *push);
void	rr(t_info *push);

void	rra(t_info *push);
void	rrb(t_info *push);
void	rrr(t_info *push);

/*
** Answers that programs can give: "Error". And free.
*/

void	error_exit(char **nums, t_info *push);
void	free_stack(t_stack *head, t_info *push);
void	free_push(t_info *push);

/*
** Algorithm starts here -
** in file sort.c
*/
int		if_orden_a(t_info *push, int numb);
void	pre_sort(t_info *push);

/*
** For 5 or less numbers
** in file small_stack.c
*/
void	sort_two(t_info *push);
void	sort_tree(t_info *push);
void	sort_four(t_info *push);
void	sort_five(t_info *push);
void	send_min(t_info *push);

/*
**  Chunks algorithm
** in file chunk.c
*/
void	algorithm_size_chunkcalculator(t_info *push);
void	algorithm_createchuncks(t_info *push);
void	algorithm_pushinorder(t_info *push);
void	algorithm_chunk(t_info *push);

/*
** Some other funtions used in the Chunk-algorithm
** in file algorithm_utils.c
*/

void	normalization(t_info *push);
bool	ismin_stacka(t_info *push, int min, int init);
int		algorithm_b_shortesway2rotate(t_info *push, int num);
void	algorithm_putnumbertop(t_info *push, int nbr);

/*
**Just to see some steps - in file print_for_convenience.c

void	print_stack(t_stack **head);*/
#endif