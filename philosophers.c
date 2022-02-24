#include <stdlib.h>
#include <sys/time.h> //time
#include <stdio.h> //time
#include <unistd.h>
#include <pthread.h>

void sleeping(int index)
{
    //int index;
    struct timeval current_time;

    //index = *(int *)arg;
    gettimeofday(&current_time, NULL);
    if (index % 2 == 0)
        printf("%ld: filosofo %d esta durmiendo\n", current_time.tv_usec, index);
    else
        printf("%ld: filosofo %d no puede dormir\n", current_time.tv_usec, index);
    usleep(5);
    if (index % 2 == 0)
        printf("%ld: filosofo %d despertó\n", current_time.tv_usec, index);
    else
        printf("%ld: filosofo %d se quedó dormido\n", current_time.tv_usec, index);
}

void *action(void *arg)
{
    int index;
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    index = *(int *)arg;

    printf("%ld :Un filosofo esta en la posición %d\n", current_time.tv_usec, index);
    usleep(8);
    sleeping(index);
    free(arg);
}

int main()
{
    pthread_t           phil[5];
    pthread_mutex_t     lock_fork;
    int                 i = 0;

    pthread_mutex_init(&lock_fork, NULL);
    while (i < 5)
    {
        int *a = malloc(sizeof(int));
        *a = i + 1;
        if (pthread_create(phil + i, NULL, &action, (void *)a) != 0)
        {
            perror("Failed to create thread");
        }
        i++;
    }
    i = 0;
    while (i < 5)
    {
        if (pthread_join(phil[i], NULL) != 0)
            perror("Failed to join thread");
        i++;
    }
    pthread_mutex_destroy(&lock_fork);
    return (0);
}
