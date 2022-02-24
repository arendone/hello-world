#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//compilar gcc -pthread

int g_mails = 0;
pthread_mutex_t mutex;

void *routine()
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex); //protege para que ninguna otra threads la ejecute al mismo tiempo
        g_mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv)
{
    pthread_t   th[4];
    int i;
    pthread_mutex_init(&mutex, NULL);

    i = 0;
    while (i < 4)
    {
        if (pthread_create(th + i, NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
        printf("Thread %d has started\n", i);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if (pthread_join(th[i], NULL) != 0) //forza a que espere a que se acabe la execución
            return 2;
        printf("Thread %d has finished execuation\n", i);
        i++;
    }
    pthread_mutex_destroy(&mutex);
    printf("g_mails = %d\n", g_mails); //it should print 20000 but it is wrong
    return (0);
}
