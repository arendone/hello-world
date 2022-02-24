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
    pthread_t   t1;
    pthread_t   t2;
    pthread_mutex_init(&mutex, NULL);

    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
        return 2;
    if (pthread_join(t1, NULL) != 0) //forza a que espere a que se acabe la execución
        return 3;
    if (pthread_join(t2, NULL) != 0)
        return 4;
    pthread_mutex_destroy(&mutex);
    printf("g_mails = %d\n", g_mails);
    return (0);
}
