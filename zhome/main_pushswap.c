/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:44:13 by arendon-          #+#    #+#             */
/*   Updated: 2021/12/29 20:07:22 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	}

	printf("\nstack A:\n");
	print_stack(&(push->heada));
	printf("\nstack B:\n");
	print_stack(&(push->headb));

	//pre_sort(&heada, &headb);

	/*printf("\nstack A:\n");
	print_stack(&(push->heada));
	printf("\nstack B:\n");
	print_stack(&(push->headb));*/
	free_push(push);
	//system("leaks push_swap");
	return (0);
}
