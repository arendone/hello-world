/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:43:10 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/25 19:09:20 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_info(t_info *info)
{
	info->num_philo = 0;
	info->time_die = 0;
	info->time_eat = 0;
	info->time_sleep = 0;
	info->meals = 0;
}

void	start_simulation(t_info *info)
{
	t_philo		*set;
	set = sit_philosophers(info);
	if (set == NULL)
	{
		free(info);
		printf("Fallo sit philosophers\n");
		return ;
	}
	printf("Hola\n");
	//usleep(1000000);
	//printf("Hola2\n");
	free(set);
	free(info);
}

int	main(int argc, char **argv)
{
	t_info		*info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
	{
		printf("Malloc failed\n");
		return (1);
	}
	init_info(info);
	if (read_arg(argc, argv, info) == 0)
		start_simulation(info);
	else
	{
		printf("Wrong arguments\n");
		free(info);
		return (1);
	}
	return (0);
}
