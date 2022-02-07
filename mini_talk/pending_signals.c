#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/*      deshabilita Control + C      */

pid_t	mypid;

void	usr1a(int sig);
void	usr1b(int sig);

int main(void)
{
	mypid = getpid();
	/* SVR4 Signal improvements */
	/* generated, delivered, pending, blocked */
	/* the value of the function can be SIG_DFL - default or
					SIG_IGN - ignore this signal */	
	sigset(SIGINT , SIG_IGN);
	sigset(SIGUSR1, usr1a);
	printf("Running as %d, hit me wtith an INT or USR1\n", mypid);
	while (1);
	return (0);
}

void	usr1a(int sig)
{
	sighold(sig);
	printf ("in usr1a, let's put a few sigusr1s in the queue\n");
	kill(mypid, SIGUSR1);
	kill(mypid, SIGUSR1);
	kill(mypid, SIGUSR1);
	printf("Put three SIGUSR1 out.  Resetting the handler to usr1b\n");
	sigset (SIGUSR1, usr1b); //???
	sigrelse(sig); //???
	printf("all done with usr1a\n");
}

void	usr1b(int sig)
{
	static int count = 0;
	printf("in usr1b, count = %d \n", count++);
}
