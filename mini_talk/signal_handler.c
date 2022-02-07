#include <stdio.h>     /* standard I/O functions                         */
#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <signal.h>    /* signal name macros, and the signal() prototype */
#include <sys/types.h>   /* various type definitions, like pid_t      */

/* first, here is the signal handler */
void	catch_int(int sig_num)
{
	/* re-set the signal handler again to catch_int, for next time */
	signal(SIGINT, catch_int); // why? answer >>>
	printf("Don't do that\n");
	fflush(stdout); //fflush() is typically used for output stream only.
					// Its purpose is to clear (or flush) the output buffer 
					//and move the buffered data to console (in case of stdout) 
					//or disk (in case of file output stream).
}
/* >>>
On some systems (such as HP-UX), when a signal handler is called, the system
automatically resets the signal handler for that signal to the default handler.
Thus, we re-assign the signal handler immediately when entering the handler
function. Otherwise, the next time this signal is received, the process will
exit (default behavior for INT signals). Even on systems that do not behave
in this way, it still won't hurt, so adding this line always is a good idea.
*/

int	main(int argc, char *argv[])
{
	pid_t	my_pid;

	my_pid = getpid();
	printf("pid: %d\n", my_pid);
	/* set the INT (Ctrl-C) signal handler to 'catch_int' */
	signal(SIGINT, catch_int);
	/* now, lets get into an infinite loop of doing nothing. */
	for ( ;; )
		pause(); //the pause() system call causes the process to halt execution, 
				//until a signal is received. it is surely better then a 'busy wait'
				// infinite loop.
	return (0);
}

/* 
'fg' - continuar despues de suspender (con control + Z)
kill -INT <PID>         -INT == Control + C
Control + \  == quit, this signal causes the process to immediately terminate.
				Pretty similar to Control + C
*/