/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:44:13 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/29 21:49:07 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//gcc -L ./libft -lft .\check_string_argv.c .\errorsandfree.c .\init_push.c .\main_pushswap.c .\operations_p.c .\operations_s.c .\operations_r.c .\operations_rr.c .\small_stack.c sort.c .\print_stack.c .\algorithm_utils.c .\libft/ft_split.c .\libft\ft_freearray.c .\libft\ft_putendl_fd.c .\libft\ft_substr.c .\libft\ft_strtrim.c .\libft\ft_strlcpy.c .\libft\ft_strdup.c .\libft\ft_strlen.c .\libft\ft_putstr_fd.c .\libft\ft_strchr.c -o push_swap

int	main(int argc, char **argv)
{
	int		i;
	t_info	*push;

	i = 1;
	push = init_push();
	if (push == NULL)
		return (-1);
	if (argc > 1)
	{
		while (argv[i] && i < argc)
		{
			if (invalid_argv(argv[i], push, 0))
			{
				free_push(push);
				return (-1);
			}
			i++;
		}
        //pre_sort(push);
        //return (1);
	}
    //else
    //   return (-1);


	printf("\nstack A:\n");
	print_stack(&(push->heada));
	printf("\nstack B:\n");
	print_stack(&(push->headb));

	//pre_sort(&heada, &headb);
	//ss(push);
	//pb(push);
    //pb(push);
    //rrr(push);
    //rb(push);
    //normalization(push);
    pre_sort(push); //debe ir dentro del if arriba
	printf("\nstack A:\n");
	print_stack(&(push->heada));
	printf("\nstack B:\n");
	print_stack(&(push->headb));
    printf("size A: %d, ", push->size_a);
    printf("size B: %d. ", push->size_b);
	free_push(push);
	//system("leaks push_swap");
	return (0);
}
