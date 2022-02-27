/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:43:10 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/27 17:00:24 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief  create the philosophers and start the simulation
 * @note
 * @param ?
 * @retval none?
 */
void	start_simulation()
{
	t_philo		**philos;

	philos = sit_philosophers(true);
	if (philos == NULL)
	{
		free_info();
		printf("Failed create philosophers\n");
		return ;
	}
	printf("Hola\n");
	//usleep(10000000);
	//printf("Hola2\n");
	free_philos();
	free_info();
}

int	main(int argc, char **argv)
{
	t_info		*info;
	//t_philo		**philos;

	info = NULL;
	if (!(argc == 5 || argc == 6))
		return (print_error());
	info = set_info(argv);
	if (info == NULL)
		return (EXIT_FAILURE);
	//else
	//{
	//	philos = init_philos(true);
	//	if (philos == NULL || philos[0] == NULL)
	//	{
	//		printf("Error while creating philosophers\n");
	//		return (EXIT_FAILURE);
	//	}
	//	if (thread_creation(info, philos) == EXIT_FAILURE)
	//		return (EXIT_FAILURE);
	//}
	start_simulation(); //cambiar
	return (EXIT_SUCCESS);
}
