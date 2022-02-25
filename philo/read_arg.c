/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:30:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/24 21:20:58 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	read_arg(int argc, char **argv, t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (1);
	info->num_philo = philo_atoi(argv[1]);
	info->time_die = philo_atoi(argv[2]);
	info->time_eat = philo_atoi(argv[3]);
	info->time_sleep = philo_atoi(argv[4]);
	if (argc == 6)
	{
		info->meals = philo_atoi(argv[5]);
		if (info->meals < 1)
			return (1);
	}	
	if (info->num_philo < 1 || info->time_die < 1 || info->time_eat < 1
		|| info->time_sleep < 1)
		return (1);
	printf("Reading arguments... \nnum_philo: %d, time_die: %d, time_eat: %d, time_sleep: %d, meals: %d \n", info->num_philo, info->time_die, info->time_eat, info->time_sleep, info->meals);
	return (0);
}

/* Modifiqué la función para que al mismo tiempo cheque
si la cadena solo tiene dígitos */
int	philo_atoi(const char *str)
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
