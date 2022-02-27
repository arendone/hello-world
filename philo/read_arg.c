/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:30:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/26 17:41:43 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Modifiqué la función para que al mismo tiempo cheque
si la cadena solo tiene dígitos */
/**
 * @brief  ft_atoi with small modificacions
 * @note
 * @param  *str: argv[i] from main
 * @retval 0 if is not a interger or it is 0... or the interger
 */
static int	philo_atoi(const char *str)
{
	int		n;
	int		i;
	int		sign;

	n = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + (str[i] - '0');
			i++;
		}
		else
			return (0);
	}
	return (sign * n);
}

/**
 * @brief  checks if argv is only integers
 * @note
 * @param  **argv: argv from main
 * @retval true if only numbers found, false if not
 */
static bool	read_arg(char **argv, t_info *info)
{
	info->num_philo = philo_atoi(argv[1]);
	info->time_die = philo_atoi(argv[2]);
	info->time_eat = philo_atoi(argv[3]);
	info->time_sleep = philo_atoi(argv[4]);
	if (argv[5])
	{
		info->meals = philo_atoi(argv[5]);
		// flag de que num of meals is true should be true??
		if (info->meals < 1)
		{
			return (false);
		}
	}	
	if (info->num_philo < 1 || info->time_die < 1 || info->time_eat < 1
		|| info->time_sleep < 1)
		return (false);
	//printf("Reading arguments... \nnum_philo: %d, time_die: %d, time_eat: %d, time_sleep: %d, meals: %d \n", info->num_philo, info->time_die, info->time_eat, info->time_sleep, info->meals);
	return (true);
}

/**
 * @brief  sets the info struct from reading argv
 * @note   the *info is a static and can be accessed by get_info
 * @param  **argv: the argv from main
 * @retval pointer to the info struct or NULL if allocation failed
 */
t_info	*set_info(char **argv)
{
	static t_info	*info;

	if (argv == NULL)
		return (info); // it will be use by the function get_info...
	info = ft_calloc(1, sizeof(t_info));
	if (info == NULL)
		return (NULL);
	if (read_arg(argv, info) == false)
	{
		printf("Only positive integers as input allowed\n");
		free_info();
		return (NULL);
	}
	//if (set_info2() == EXIT_FAILURE)
	//	return (NULL);
	//pthread_mutex_init(input->print_lock, NULL);
	//pthread_mutex_init(input->death_lock, NULL);
	//pthread_mutex_init(input->wait_lock, NULL);
	//input = check_input(input);
	return (info);
}

/**
 * @brief  can access the static of set_info
 * @note
 * @retval pointer stored in the static of set_info
 */
t_info	*get_info(void)
{
	return (set_info(NULL));
}

/**
 * @brief  is a part of the set_info function
 * @note   only exists because of norminette (25 lines)
 * @retval will pass or fail
 */
/*
int	set_info2(void)
{
	t_info	*info;

	info = get_info();
	//input->state[is_eating] = "is eating\n";
	//input->state[grabbed_fork] = "has taken a fork\n";
	//input->state[is_sleeping] = "is sleeping\n";
	//input->state[is_thinking] = "is thinking\n";
	//input->state[is_dead] = "died\n";
	//input->state[6] = NULL;
	//input->print_lock = ft_calloc(1, sizeof(pthread_mutex_t));
	//input->death_lock = ft_calloc(1, sizeof(pthread_mutex_t));
	//input->wait_lock = ft_calloc(1, sizeof(pthread_mutex_t));
	//if (input->death_lock == NULL || input->wait_lock == NULL
	//	|| input->print_lock == NULL)
	//{
	//	free_input();
	//	return (EXIT_FAILURE);
	//}
	return (EXIT_SUCCESS);
}*/
