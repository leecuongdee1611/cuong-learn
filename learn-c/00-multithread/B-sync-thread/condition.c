#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADHOLD 5
#define USE_CONDITION 0
pthread_t tid;

int counter;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#if USE_CONDITION
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
#endif

void threadFunc(void)
{
    pthread_mutex_lock(&mutex);
    printf("pthread has started\n");

    while (counter < THREADHOLD)
    {
        counter += 1;
        sleep(5);
    }
#if USE_CONDITION
    pthread_cond_signal(&cond);
#endif
    printf("pthread has finished, counter = %d\n", counter);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(void)
{
    int ret = 0;

    ret = pthread_create(&tid, NULL, (void *)(&(threadFunc)), NULL);
    if (ret != 0)
    {
        printf("Error: Thread create failed\n");
    }
#if USE_CONDITION
    pthread_mutex_lock(&mutex);
    while (1)
    {
        if (counter < THREADHOLD)
        {
            pthread_cond_wait(&cond, &mutex);
            printf("Global variable counter = %d.\n", counter);
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    pthread_join(tid, NULL);

#else
    while (1)
    {
        if (counter == THREADHOLD)
        {
            printf("Global variable counter = %d.\n", counter);
            break;
        }
    }

    pthread_join(tid, NULL);
#endif

    return 0;
}