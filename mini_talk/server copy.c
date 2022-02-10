/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:59:27 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/10 16:18:12 by arendon-         ###   ########.fr       */
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

	//calloc buf
	//bit = 7;
	//i = 0;
	if (sig == SIGUSR1)
	{
		//write(1, "1\n", 2);
		//ft_printf("%c", &buf[i]);
		buf[i] |= (1 << bit);
		//ft_printf("%d, %c\n", buf[i], &buf[i]);
	}
		
	if (sig == SIGUSR2)// no hace nada
	{
		buf[i] &= ~(1 << bit);
		//ft_printf("%d, %c\n", buf[i], &buf[i]);
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
			//ft_printf("i vale %d\n", i);
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	//sigset_t			s;

	pid = getpid();
	ft_printf("server pid: %d\n", pid);
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