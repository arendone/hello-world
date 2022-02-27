/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:50:42 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/27 16:57:11 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h> //usleep
# include <stdlib.h>//free
# include <stdbool.h>
#include <sys/time.h> //gettimeofday

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
	pthread_mutex_t	*fork;
}	t_philo;

typedef struct s_info
{
	//t_philo	*set; //should I use long?
	int		num_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		meals;
}	t_info;

/* Read arguments in read_arg.c */
t_info	*set_info(char **argv);
t_info	*get_info(void);
//int		set_info2(void);

/* Init data in sit_philosophers.c*/
t_philo	**sit_philosophers(bool value);
int		init_philo(t_philo *elem, int i);
int		philos_join(t_philo	**philos);
int		philos_mutex(t_philo	**philos);
t_philo	**get_philos(void);

/* Utils in utils.c*/
void	*ft_calloc(size_t count, size_t size);
int		print_error(void);
//long	get_time(void);

/* Functions of sleeping, eating or thinking in routine.c*/
void	*routine(void *arg);
long	get_time(void); //Aqui?

/* Exit in exit.c */
void	free_info(void);
void	free_philos(void);

#endif