/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:24:01 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/09 18:54:54 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <signal.h>    /* signal name macros, and the signal() prototype */
#include <stdio.h>
#include "./libft/libft.h"

//cambiarlo por tu fr_printf

/*int	*bin_char(int c)
{
	int		*bin_char;
	int		counter;

	bin_char = (char *)malloc(sizeof(int) * 8);
	if (bin_char == NULL)
		return (NULL);
	counter = 7;
	while (counter >= 0)
	{
		bin_char[counter] = c % 2;
		c = c / 2;
		counter--;
	}
	return (bin_char);
}*/

/*void	send_signals_char(pid_t pid_server, int c)
{
	int	counter;

	counter = 8;
	while (counter > 0 )
	{
		if ((c % 2) == 0)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		c = c / 2;
		counter--;
	}
}*/

static void	send_char(pid_t pid_server, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
		{
			write(1, "1\n", 2);
			kill(pid_server, SIGUSR1);
		}
		else
		{
			write(1, "0\n", 2);
			kill(pid_server, SIGUSR2);
		}
		usleep(100);
		bit--;
	}
}

static void	send_str(pid_t pid_server, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid_server, str[i]);
		i++;
	}
	send_char(pid_server, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid_client;
	int		pid_server;

	pid_client = getpid();
	printf("client pid: %d\n", pid_client);
	if (argc < 3)
		return (-1);
	pid_server = ft_atoi(argv[1]);
	printf("server pid: %d\n", pid_server);
	send_str(pid_server, argv[2]);
	//usleep(15);
	//kill(pid_server, SIGINT);
	return (0);
}
