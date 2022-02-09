#include <unistd.h>     /* standard unix functions, like getpid()       */
#include <sys/types.h>  /* various type definitions, like pid_t         */
#include <signal.h>     /* signal name macros, and the kill() prototype */
#include <stdio.h>

void	handler(int num)
{
	signal(SIGINT, handler); // si no lo pongo lo hace una vez 
	//y luego regresa el la sign con su funcion por defaut, creo que deberia usar otra vez sigaction
	write(STDOUT_FILENO, "I won't die!\n", 13); // Hay que usar write o ft_printf pero NO printf >>>
}

/* >>>
https://www.youtube.com/watch?v=83M5-NPDeWs
*/


void	seghandler(int num)
{
	signal(SIGTERM, seghandler); // si no lo pongo lo hace una vez y luego regresa el la sign con su funcion por defaut
	write(STDOUT_FILENO, "Seg Fault!\n", 11);
}

int	main(void)
{
	struct sigaction sa;
	//sa.sa_handler = handler;
	sa.sa_handler = seghandler;

	//sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL); //en otra terminal kill + PID

	while(1)
	{
		printf("Wasting your cycles. %d\n", getpid());
		sleep(1);
	}
	return (0);
}
