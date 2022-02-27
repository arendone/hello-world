/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:46:55 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/27 17:32:21 by arendon-         ###   ########.fr       */
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
	philos = ft_calloc(info->num_philo + 1, sizeof(t_philo *));
	if (philos == NULL)
		return (NULL);
	i = 0;
	printf("num de filosofos: %d\n", info->num_philo);
	while (i < info->num_philo)
	{
		if (init_philo(philos[i], i) == EXIT_FAILURE)
		{
			printf("philo in adress para i = 0 %p\n", philos[0]); //ayuda
			free_philos();
			return (NULL);
		}
		i++;
	}
	printf("philo in adress para i = 1 %p\n", philos[1]); //ayuda
	if (philos_join(philos) == EXIT_FAILURE
		|| philos_mutex(philos) == EXIT_FAILURE)
		free_philos();
	printf("philo in adress para i = 1 %p\n", philos[1]); //ayuda
	return (philos);
}

/**
 * @brief  create the thread philo
 * @note
 * @param adress of the struct where we cant to create the thread philo
 * @retval EXIT_SUCCESS or EXIT_FAILURE
 */
int	init_philo(t_philo *philo, int i)
{
	t_info			*info;

	info = get_info();
	philo = calloc(1, sizeof(t_philo));
	if (philo == NULL)
		return (EXIT_FAILURE);
	if (pthread_create(&philo->philo, NULL, &routine, (void *)info) != 0)
		return (EXIT_FAILURE);
	printf("created philo in adress %p\n", philo); // no se guarda esta info en sit...!!!!!!
	philo->seat = i + 1; //cuidado con esto
	return (EXIT_SUCCESS);
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
	printf("Vine a join");
	printf("philo in adress para i = 1 %p\n", philos[1]);
	while (philos[i] != NULL)
	{
		printf("Entre al while");
		if (pthread_join(philos[i]->philo, NULL) != 0)
			return (EXIT_FAILURE);
		printf("joined philo in adress %p\n", philos[i]);
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
		fork = calloc(1, sizeof(pthread_mutex_t));
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
