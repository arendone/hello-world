#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void		create_pthread(void);
void		pthread1(void);
void		pthread2(void);
pthread_t	thread;
pthread_t	thread1;

void	create_pthread(void)
{
	printf("create pthread1:\n");
	pthread_create(&thread, NULL, (void *)&pthread1, NULL);
	pthread_create(&thread1, NULL, (void *)&pthread2, NULL);
	//pthread_detach(thread);
	//pthread_join(thread, NULL);
	//pthread_join(thread1, NULL);
	//pthread_detach(thread1);
}

void	pthread2(void)
{
	int	i;

	i = 0;
	//while(1)
	for(i = 0; i < 9; i++)
	{
		printf("-----starting  pthread2-------\n");
		usleep(10);
	}	
	return ;
}

void	pthread1(void)
{
	int	i;

	i = 0;
	//while(1)
	for(i = 0; i < 5; i++)
	{
		printf("-----starting  pthread1-------\n");
		sleep(1);
	}	
	return ;
}

int	main(void)
{
	printf("-----starting main pthread-------\n");
	create_pthread();
	usleep(50);
	printf("end main pthread\n");
	return (0);
}
