#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREAD 5
pthread_t tid[MAX_THREAD];

/* Global variablies */
int counter;

void *threadFunc(void *argv)
{
	counter += 1;
	printf("Thread %d has started\n", counter);

	sleep(1);
	printf("Thread %d has finished\n", counter);

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

		if (iret == 0)
		{
			pthread_join(tid[i], NULL);
		}
	}

	return 0;
}