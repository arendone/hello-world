/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:43:10 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/28 17:30:58 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief  create the philosophers and start the simulation
 * @note
 * @param ?
 * @retval none?
 */


void	print_ciclo(int num_philos)
{
	int	i;
	int	j;
	int cubiertos;

	i = 0;
	j = 0;
	while (i < 10) //while(1)
	{
		cubiertos = 0;
		j = 0;
		while (cubiertos < num_philos / 2)
		{
			printf("come philo %d\n", (i + j) % num_philos); //if he is ready, otherwise the next...
			j = j + 2;
			cubiertos++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		**philos;

	info = NULL;
	if (!(argc == 5 || argc == 6))
		return (print_error());
	info = set_info(argv);
	if (info == NULL)
		return (EXIT_FAILURE);
	philos = sit_philosophers(true);
	if (philos == NULL)
	{
		free_info();
		printf("Failed create philosophers\n");
		return (EXIT_FAILURE);
	}
	printf("Hola\n");
	//usleep(10000000);
	//printf("Hola2\n");
	free_philos();
	free_info();
	//print_ciclo(info->num_philo);
	return (EXIT_SUCCESS);
}
