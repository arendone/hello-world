/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:44:13 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:52:44 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_info	*push;

	if (argc > 1)
	{
		i = 1;
		push = init_push();
		if (push == NULL)
			return (-1);
		while (argv[i] && i < argc)
		{
			if (invalid_argv(argv[i], push, 0))
			{
				free_push(push);
				return (0);
			}
			i++;
		}
		pre_sort(push);
		free_push(push);
		return (0);
	}
	return (0);
}

/*
void	print_stack(t_stack **head)
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
*/

/*		
system("leaks push_swap");
while (1); 
*/

/* 
gcc -L ./libft -lft 
.\check_string_argv.c .\errorsandfree.c
.\init_push.c .\main_pushswap.c .\operations_p.c 
.\operations_s.c .\operations_r.c .\operations_rr.c 
.\small_stack.c sort.c .\print_stack.c .\algorithm_utils.c 
.\chunk.c .\libft/ft_split.c .\libft\ft_freearray.c 
.\libft\ft_putendl_fd.c 
.\libft\ft_substr.c .\libft\ft_strtrim.c .\libft\ft_strlcpy.c 
.\libft\ft_strdup.c 
.\libft\ft_strlen.c .\libft\ft_putstr_fd.c 
.\libft\ft_strchr.c -o push_swap 
*/