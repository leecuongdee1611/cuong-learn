#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 1
struct thread_data
{
	int thread_id;
	const char *message;
};

void *print_message_function(void *ptr);

int main(void)
{
	printf("Hello world!\n");
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
	int ret = 0;
	int internal_ret = 0;
	int i;

	for (i = 0; i < NUM_THREADS; i++)
	{
		printf("Creating thread %d...\n", i);
		td[i].thread_id = i;
		td[i].message = "This is message...";
	
		internal_ret = pthread_create(&threads[i], NULL, print_message_function, (void *)&td[i]);
		if (internal_ret)
		{
			printf("Error: Unable to create thread\n");
			ret = 1;
		}	

		if (ret == 0)
		{
			pthread_join(threads[i], NULL);
		}

		printf("Thread %d returns: %d\n", i, internal_ret);
	}

	return ret;
}

void *print_message_function(void *ptr)
{
	struct thread_data *my_data;
	my_data = (struct thread_data *)ptr;
	printf("Thread ID: %d. Message: %s\n", my_data->thread_id, my_data->message);
	pthread_exit(NULL);
}
