/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:59:27 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/11 15:30:03 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./libft/includes/libft.h" //puedo agregar ruta en el makefile.. ver makefile de libft

/*
30    SIGUSR1      terminate process    User defined signal 1
31    SIGUSR2      terminate process    User defined signal 2
*/

int	g_pid = 0;

typedef struct s_hand{
	int	bit;
	int	i;
	int	size_pib;
}	t_hand;

void	get_pid(char *str, int *pid)
{
	char	*str_pid;
	int		i;

	i = 0;
	str_pid = (char *)ft_calloc(12, 1);
	if (str_pid == NULL)
	{
		ft_printf("Calloc failed\n");
		exit (1);
	}
	while (str[i] != '$')
	{
		str_pid[i] = str[i];
		i++;
	}
	*pid = ft_atoi(str_pid);
	free(str_pid);
}

void static	cleanbuf(char *buf, t_hand *hand)
{
	ft_printf("%s", &buf[hand->size_pib]);
	hand->i = 0;
	ft_bzero(buf, 49);
	hand->size_pib = 0;
}

void static	reset_bit(char *buf, t_hand *hand)
{
	hand->bit = 7;
	if (buf[hand->i] == '$' && hand->size_pib == 0)
	{
		get_pid(buf, &g_pid);
		hand->size_pib = hand->i + 1;
	}
	if (buf[hand->i] == '\0')
	{
		ft_printf("%s", &buf[hand->size_pib]);
		kill(g_pid, SIGUSR1);
		g_pid = 0;
		hand->i = 0;
		free(buf);
	}
	else
	{
		(hand->i)++;
	}
}

static void	handler(int sig)
{
	static char		*buf;
	static t_hand	hand;

	if (g_pid == 0)
	{
		buf = (char *)ft_calloc(50, 1);
		if (buf == NULL)
		{
			ft_printf("Calloc failed\n");
			kill(g_pid, SIGUSR2);
			exit (1);
		}
		hand.bit = 7;
		hand.i = 0;
		hand.size_pib = 0;
		g_pid = 1;
	}
	if (sig == SIGUSR1)
		buf[hand.i] |= (1 << hand.bit);
	hand.bit --;
	if (hand.i == 48)
		cleanbuf(buf, &hand);
	if (hand.bit == -1)
		reset_bit(buf, &hand);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("server pid: %d\n", pid);
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
