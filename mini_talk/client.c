/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:24:01 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/10 16:39:09 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <signal.h>    /* signal name macros, and the signal() prototype */
#include <stdio.h>
#include "./libft/includes/libft.h" //puedo agregar ruta en el makefile.. ver makefile de libft

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
			kill(pid_server, SIGUSR1);
		}
		else
		{
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
	char	*pid_c;
	char	*pid_f;
	char	*pid_str;

	pid_client = getpid();
	ft_printf("pid client: %d", pid_client);
	if (argc < 3)
		return (-1);
	pid_c = ft_itoa(pid_client);
	pid_f = ft_strjoin(pid_c, "$");
	pid_server = ft_atoi(argv[1]);
	pid_str = ft_strjoin(pid_f, argv[2]);
	send_str(pid_server, pid_str);
	free(pid_c);
	free(pid_f);
	free(pid_str);
	return (0);
}
