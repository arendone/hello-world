/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:49:11 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/27 17:08:38 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief  
 * @note   
 * @param 
 * @retval 
 */
void	*routine(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	printf("Routine %d, time: %lu \n", 1, get_time());
	usleep(100);
	printf("Routine %d, time: %lu \n", info->num_philo, get_time());
	return (NULL);
}

/**
 * @brief  gets the time in ms
 * @note   uses gettimeofday
 * @retval timeofday in ms
 */
long	get_time(void)
{
	long			time_ms;
	struct timeval	te;

	gettimeofday(&te, NULL);
	time_ms = (te.tv_sec * 1000);
	time_ms += (te.tv_usec / 1000);
	return (time_ms);
}
