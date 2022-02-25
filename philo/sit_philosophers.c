/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:46:55 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/25 19:13:49 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine()
{
    printf("Routine\n");
	usleep(1000000);
	return (NULL);
}

t_philo	*sit_philosophers(t_info *info)
{
	int		i;
	t_philo	*set;

	set = malloc(sizeof(t_philo) * info->num_philo);
	if (set == NULL)
	{
		free(info);
		return (NULL);
	}
	i = 0;
	printf("num de filosofos: %d", info->num_philo);
	while (i < info->num_philo)
	{
		if (init_philo(set + i, i) == 1)
		{
			free(set);
			return (NULL);
		}
		printf("i: %d\n", i);
		i++;
	}
	return (set);
}

int	init_philo(t_philo *elem, int i) //se tienen que poner por separado el join y el create !!!!!
{
	elem->seat = i + 1; //cuidado con esto
	pthread_mutex_init(&elem->fork, NULL);
	if (pthread_create(&elem->philo, NULL, &routine, NULL) != 0) //falta argumento
        return (1); //falta free
	if (pthread_join(elem->philo, NULL) != 0)
        return (1); //falta free
	pthread_mutex_destroy(&elem->fork);
	return (0);
}

/*int free_all(t_info *info)
{
	free(*set);
	free(info);
	return
}*/