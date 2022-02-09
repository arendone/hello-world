/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:59:27 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/09 18:58:42 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <signal.h>    /* signal name macros, and the signal() prototype */
#include <stdio.h>
#include "./libft/libft.h"

//cambiarlo por tu fr_printf

//30    SIGUSR1      terminate process    User defined signal 1
//31    SIGUSR2      terminate process    User defined signal 2

//no imprime porque el bit se reinicia a 7 cada vez
void	handler(int signum)
{
	static char	buf;//[100]; //cambiar por ft_strjoin o algo similar
	static int	bit;
	//static int	i;

	//calloc buf
	bit = 7;
	//i = 0;
	if (signum == SIGUSR1)
		write(1, "1\n", 2);
		//buf |= (1 << bit); //buf[i] |= (1 << bit);
	if (signum == SIGUSR2)// no hace nada
		write(1, "0\n", 2);
		//buf &= (1 << bit);//buf[i] &= (1 << bit);
	bit --;
	
	if (bit == -1) //bit siempre es 7!!!! 
	{
		write(1, "X\n", 2);
		bit = 7;
		//if (buf[i] == '\0')
		//{
			write(1, &buf, 1);
			//write(1, buf, i);
			//i = 0;
		//}
		//else
			//i++;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	//sigset_t			s;

	pid = getpid();
	printf("server pid: %d\n", pid);
	sa.sa_handler = handler;
	//sigemptyset(&s);
	//sigaddset(&s, SIGINT);
	sigemptyset(&sa.sa_mask);
	//sigprocmask(SIG_BLOCK, &s, NULL);
	sa.sa_flags = 0; //SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		//sigaction(SIGUSR1, &sa, NULL);
		//sigaction(SIGUSR2, &sa, NULL);
	}
	//sigprocmask(SIG_UNBLOCK, &s, NULL);
	return (0);
}
