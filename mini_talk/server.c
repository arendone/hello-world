/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:59:27 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/10 16:44:34 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <signal.h>    /* signal name macros, and the signal() prototype */
//#include <stdio.h>
#include "./libft/includes/libft.h" //puedo agregar ruta en el makefile.. ver makefile de libft


//30    SIGUSR1      terminate process    User defined signal 1
//31    SIGUSR2      terminate process    User defined signal 2
#define MAX_STR_LENGTH 10000000
//no imprime porque el bit se reinicia a 7 cada vez
void	handler(int sig)
{
	static char	buf[MAX_STR_LENGTH] = {'\0', }; //cambiar por ft_strjoin o algo similar
	static int	bit = 7;
	static int	i = 0;

	if (sig == SIGUSR1)
	{
		buf[i] |= (1 << bit);
	}
	if (sig == SIGUSR2)
	{
		buf[i] &= ~(1 << bit);
	}
	bit --;
	if (bit == -1)
	{
		bit = 7;
		if (buf[i] == '\0')
		{
			ft_printf("%s", buf);
			i = 0;
		}
		else
		{
			i++;
		}
	}
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