#include <unistd.h>     /* standard unix functions, like getpid()       */
#include <sys/types.h>  /* various type definitions, like pid_t         */
#include <signal.h>     /* signal name macros, and the kill() prototype */
#include <stdio.h>

int main(void)
{
	int		i;
	pid_t	my_pid;

	i = 0;
	my_pid = getpid();
	printf("pid: %d\n", my_pid);
	while (i < 10000)
	{
		printf("%d, ", i);
		i++;
		if (i == 5000)
			kill(my_pid, SIGSTOP); // si lo hago en i pequenas suspende antes de imprimir
			//supongo que la velocidad importa mucho, las senales son rapidas
	}
	printf("pid: %d\n", my_pid);
	return (0);
}
