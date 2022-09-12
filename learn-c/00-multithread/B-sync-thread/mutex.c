#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREAD 5
#define USE_MUTEX 1

pthread_t tid[MAX_THREAD];
#if USE_MUTEX
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#endif

/* Global variablies */
int counter;

void *threadFunc(void *argv)
{
#if USE_MUTEX
	pthread_mutex_lock(&mutex);
#endif
	counter += 1;
	printf("Thread %d has started\n", counter);

	sleep(1);
	printf("Thread %d has finished\n", counter);
#if USE_MUTEX
	pthread_mutex_unlock(&mutex);
#endif

	pthread_exit(NULL);
}

int main(void)
{
	int i = 0;
	int iret = 0;

	for (i = 0; i < MAX_THREAD; i++)
	{
		iret = pthread_create(&tid[i], NULL, threadFunc, NULL);
		if (iret != 0)
		{
			printf("Thread [%d] created error\n", i);
		}
#if 0 // comment out this code to test sync thread using mutex
		if (iret == 0)
		{
			pthread_join(tid[i], NULL);
		}
#endif
	}
#if 1 // un-comment out this code to test sync thread using mutex
	for (i = 0; i < MAX_THREAD; i++)
	{
		pthread_join(tid[i], NULL);
	}
#endif

	return 0;
}