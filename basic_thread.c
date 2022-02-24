#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//compilar gcc -pthread

int g_x = 2;

void *routine()
{
    g_x++;
    sleep(2);
    printf("Value of x: %d\n", g_x);
}

void *routine2()
{
    sleep(4);
    printf("Value of x: %d\n", g_x);
}

int main(int argc, char *argv)
{
    pthread_t   t1;
    pthread_t   t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, &routine2, NULL) != 0)
        return 2;
    if (pthread_join(t1, NULL) != 0) //forza a que espere a que se acabe la execución
        return 3;
    if (pthread_join(t2, NULL) != 0)
        return 4;
    return (0);
}

