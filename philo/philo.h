/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:50:42 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/25 19:08:11 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h> //usleep
# include <stdlib.h>//free

typedef enum e_status
{
	is_eating = 0,
	//grabbed_fork = 1, or ready to eat
	is_sleeping = 2,
	is_thinking = 3,
	is_dead = 4,
	//is_done?
}	t_status;

typedef struct s_philo
{
	pthread_t		philo;
	int				seat;
	enum e_status	status;
	pthread_mutex_t	fork;
}	t_philo;

typedef struct s_info
{
	//t_philo	*set;
	int		num_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		meals;
}	t_info;

/* Read arguments in read_arg.c */
int		read_arg(int argc, char **argv, t_info *info);
int		philo_atoi(const char *str);

/* Init data */
t_philo	*sit_philosophers(t_info *info);
int	init_philo(t_philo *elem, int i);
void *routine(); //provisional aqui

#endif