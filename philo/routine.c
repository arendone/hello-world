/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:49:11 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/28 18:29:15 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief  
 * @note   
 * @param 
 * @retval 
 */
void	*routine(void *temp)
{
	//t_info		*info;
	t_philo		**philos;
	t_philo		*philo;
	int			seat;
	//int			num_philos;

	philo = (t_philo *)temp;
	//info = (t_info *)get_info;
	philos = (t_philo **)get_philos;
	//printf("adress of pointer 3%p\n", philos[3]->fork); segmentation fault...
	seat = philo->seat;
	//num_philos = info->num_philo;
	//if philo is ready to eat...
	pthread_mutex_lock(philo->fork);
	//pthread_mutex_lock(philos[(seat + 1) % 5]->fork);
	printf("%lu: Filosofo %d comienza a comer\n", get_time(), seat + 1);
	usleep(2 * 1000);
	printf("%lu: Filosofo %d deja de comer\n", get_time(), seat + 1);
	pthread_mutex_unlock(philo->fork);
	//pthread_mutex_unlock(philos[(seat + 1) % 5]->fork);
	return (NULL);
}

/**
 * @brief  calculate the current timestamp in milliseconds
 * @note   uses gettimeofday
 * @retval timeofday in milliseconds
 */
long	get_time(void)
{
	long			time_mls;
	struct timeval	te;

	gettimeofday(&te, NULL);
	time_mls = (te.tv_sec * 1000);
	time_mls += (te.tv_usec / 1000);
	return (time_mls);
}
