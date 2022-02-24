#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

//compilar gcc -pthread

pthread_mutex_t mutex;
int str[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{
    int index;

    //sleep(1);
    index = *(int *)arg;
    printf(" %d ", str[index]);
    free(arg);
}

int main(int argc, char *argv)
{
    pthread_t   th[10];
    int i;
    //int index;
    pthread_mutex_init(&mutex, NULL);

    //index = 0;
    i = 0;
    while (i < 10)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(th + i, NULL, &routine, (void *)a) != 0)
        {
            perror("Failed to create thread");
        }
        //printf("Thread %d has started\n", i);
        i++;
    }
    i = 0;
    while (i < 10)
    {
        if (pthread_join(th[i], NULL) != 0) //forza a que espere a que se acabe la execución
            perror("Failed to join thread");
        i++;
    }
    pthread_mutex_destroy(&mutex);
    return (0);
}
