/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:30:48 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/29 20:08:51 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
#include <stdio.h> //TEMPORAL

# include "./libft/libft.h"

typedef struct s_stack{
	struct s_stack	*prev;
	int				num;
	bool			flag;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	t_stack	*heada;
	t_stack	*headb;
	int		size_a;
	int		size_b;
	/*char	**input_array;
	int		array_size;
	int		chunk;
	bool	swap;*/
}t_info;

# define INT_MAX (2147483647)
# define INT_MIN (-2147483648)

/*
** ------------------------------- Common functions ---------------------------
*/

/*
** String check in file - check_string_argv.c
*/

int		atoi_push_swap(char *str, char **nums, t_info *push);
int		check_rep(t_info *push, int numb);
int		invalid_argv(char *argv, t_info *push, size_t i);
void	checkandadd(t_info *push, char **nu, size_t i);

/*
** Malloc and initiation for t_info push and t_stacks
** in file - init_push.c
*/

t_info	*init_push(void);
//void				*ft_xmalloc(size_t size); ???
t_stack	*addToEmpty(int numb);
t_stack	**addAtEnd(t_info *push, int numb);
//t_stack	**addAtEnd(t_stack **head, int numb);

/*
** Operations in the project - files operations_p.c,
** operations_r.c, operations_rr.c, operations_s.c
*/

//void				sa(t_push *push);
//void				sb(t_push *push);
//void				ss(t_push *push);
//
//void				pa(t_push *push);
//void				pb(t_push *push);
//
//void				ra(t_push *push);
//void				rb(t_push *push);
//void				rr(t_push *push);
//
//void				rra(t_push *push);
//void				rrb(t_push *push);
//void				rrr(t_push *push);

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

/*
** Answers that programs can give: "Error". And free.
*/

void	error_exit(char **nums, t_info *push);
void	free_stack(t_stack *head);
void	free_push(t_info *push);
//void				error_operations(char *str, t_push *push);
//, "KO", "OK" - for checker
//void				ko(t_push *push);
//void				ok(t_push *push);

/*
**Just to see some steps - in file print_for_convenience.c
*/
void	print_stack(t_stack **head);


/*void	sort_two(t_stack **ha);
void	sort_tree(t_stack **pointer_heada);
void	sort_four(t_stack **ha, t_stack **hb);
void	sort_five(t_stack **ha, t_stack **hb);
int		if_orden(t_stack **ha, int num);*/

/*
int		count_left(t_stack **node);
int		count_right(t_stack **node);
int		lstsize(t_stack **head);
int		maximum(int n, ...);
int		minimum(int n, ...);
int		minimum2(int n, ...);
void	data_subgroup(t_subg *sg, t_stack **head);
void	send_subgroup(t_stack **heada, t_stack **headb, t_stack **mina);
void	pre_sort(t_stack **heada, t_stack **headb);
void	sort(t_stack **heada, t_stack **headb, int size);
void	reverse(t_stack **heada, t_stack **headb, int mina);
void	hide_min(t_stack **heada, t_subg *data);
void	send_back(t_stack **heada, t_stack **headb);*/
#endif