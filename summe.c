#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

//compilar gcc -pthread

pthread_mutex_t mutex;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{
    int index = *(int *)arg;
    int sum = 0;

    for (int j = 0; j < 5; j++)
    {
        sum += primes[index + j];
    }
    *(int *)arg = sum;
    return (arg);
}

int main(int argc, char *argv)
{
    pthread_t   th[2];
    int i;
    //int index;
    pthread_mutex_init(&mutex, NULL);

    //index = 0;
    i = 0;
    while (i < 2)
    {
        int *a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(th + i, NULL, &routine, (void *)a) != 0)
        {
            perror("Failed to create thread");
        }
        //printf("Thread %d has started\n", i);
        i++;
    }

    int GlobalSum = 0;
    i = 0;
    while (i < 2)
    {
        int *r;
        if (pthread_join(th[i], (void **)&r) != 0) //forza a que espere a que se acabe la execución
            perror("Failed to join thread");
        GlobalSum += *r;
        free(r);
        i++;
    }
    printf("Suma: %d\n", GlobalSum);
    pthread_mutex_destroy(&mutex);
    return (0);
}
