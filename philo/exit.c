/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:23:19 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/28 17:31:25 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/**
 * @brief  will correctly free the info struct and its contents
 * @note
 * @retval None
 */
void	free_info(void)
{
	t_info	*info;

	info = get_info();
	//pthread_mutex_destroy(info->death_lock);
	//pthread_mutex_destroy(info->wait_lock);
	//pthread_mutex_destroy(info->print_lock);
	//free(info->death_lock);
	//free(info->wait_lock);
	//free(info->print_lock);
	free(info);
}

/**
 * @brief  will correctly free the array of philos struct
 * @note
 * @retval None
 */
void	free_philos(void)
{
	t_philo	**philos;
	int		i;

	philos = get_philos();
	//printf("philos adress%p\n", philos); //ayuda
	i = 0;
	while (philos[i])
	{
		//printf("philo in adress%p\n", philos[i]); //ayuda
		free (philos[i]);
		pthread_mutex_destroy(philos[i]->fork);
		i++;
	}
	free(philos);
	philos = NULL;
	
	//pthread_mutex_destroy(info->death_lock);
	//pthread_mutex_destroy(info->wait_lock);
	//pthread_mutex_destroy(info->print_lock);
	//free(info->death_lock);
	//free(info->wait_lock);
	//free(info->print_lock);
}
