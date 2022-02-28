/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:46:55 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/28 18:20:51 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief  create an array of pointers, whose pointers are the philosophers
 * @note   call the funcions philos_join and philos_mutex
 * @param value
 * @retval when it is value is true return the array philos (get_philos), 
 * when value is false do what it is described in the brief.
 */
t_philo	**sit_philosophers(bool value)
{
	int				i;
	static t_philo	**philos;
	t_info			*info;

	if (value == false)
		return (philos);
	info = get_info();
	philos = (t_philo **)ft_calloc(info->num_philo + 1, sizeof(t_philo *));
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < info->num_philo)
	{
		philos[i] = init_philo(i);
		if (philos[i] == NULL)
		{
			free_philos();
			return (NULL);
		}
		i++;
	}
	if (philos_join(philos) == EXIT_FAILURE)
		//|| philos_mutex(philos) == EXIT_FAILURE)
		free_philos();
	return (philos);
}

/**
 * @brief  create the thread philo
 * @note
 * @param adress seat of the philo ???
 * @retval pointer to the info of the philo
 */
t_philo	*init_philo(int i)
{
	t_philo			*temp;
	pthread_mutex_t	*fork;

	temp = (t_philo *)calloc(1, sizeof(t_philo));
	if (temp == NULL)
		return (NULL);
	if (pthread_create(&temp->philo, NULL, &routine, (void *)temp) != 0)
	{
		free(temp);
		return (NULL);
	}
	fork = (pthread_mutex_t *)calloc(1, sizeof(pthread_mutex_t));
	if (fork == NULL)
	{
		free(temp);
		return (NULL);
	}
	temp->fork = fork;
	pthread_mutex_init(temp->fork, NULL);
	//printf("created philo in adress %p\n", temp);
	temp->seat = i; //cuidado con esto
	return (temp);
}

/**
 * @brief  join all the threads of all the philosophers
 * @note
 * @param array of pointers to the info of the philosophers
 * @retval EXIT_SUCCESS or EXIT_FAILURE
 */
int	philos_join(t_philo	**philos)
{
	int	i;

	i = 0;
	while (philos[i] != NULL)
	{
		if (pthread_join(philos[i]->philo, NULL) != 0)
			return (EXIT_FAILURE);
		//printf("joined philo in adress %p\n", philos[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief  create the mutex that every philosopher need
 * @note
 * @param array of pointers to the info of the philosophers
 * @retval EXIT_SUCCESS or EXIT_FAILURE
 */
int	philos_mutex(t_philo	**philos)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	while (philos[i])
	{
		fork = (pthread_mutex_t *)calloc(1, sizeof(pthread_mutex_t));
		if (fork == NULL)
			return (EXIT_FAILURE);
		philos[i]->fork = fork;
		pthread_mutex_init(philos[i]->fork, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief  can access the static of sit_philosophers
 * @note
 * @retval pointer stored in the static of sit_philosophers
 */
t_philo	**get_philos(void)
{
	return (sit_philosophers(false));
}
