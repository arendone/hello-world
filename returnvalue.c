#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

//compilar gcc -pthread

pthread_mutex_t mutex;

void *roll_dice()
{
    int value;
    int *ret;

    ret = (int *)malloc(sizeof(int));
    value = (rand() % 6) + 1;
    *ret = value;
    printf("Adress of ret %p, value %d\n", ret, value);
    return ((void *)ret);
}

int main(int argc, char *argv)
{
    pthread_t   th[4];
    int *res;
    int i;
    pthread_mutex_init(&mutex, NULL);

    i = 0;
    while (i < 4)
    {
        if (pthread_create(th + i, NULL, &roll_dice, NULL) != 0)
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
        if (pthread_join(th[i], (void **) &res) != 0) //forza a que espere a que se acabe la execución
            return 2;
        printf("Adress of res: %p, value %d\n", res, *res);
        free(res);
        i++;
    }
    pthread_mutex_destroy(&mutex);
    return (0);
}
