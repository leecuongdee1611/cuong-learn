/*
Notes:
	The arguments are different. The functions need not be the same.
	Threads terminate by explicitly calling pthread_exit. Can be use exit().
Two types of multitasking: process_based and thread_based
	Process_based: Handles the concurrent execution of program
	Thread_based: Handles the concurrent execution of pieces of the same program
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
struct thread_data
{
	int thread_id;
	const char *message;
};

void *print_message_function(void *ptr);

int main(void)
{
	int ret = 0;
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
	int i;
	int iret;
	for (i = 0; i < NUM_THREADS; i++)
	{
		printf("Creating thread %d\n", i);
		td[i].thread_id = i;
		td[i].message = "This is message ";

		/* Create independent threads each of which will execute function */
		/* Arguments
		thread - returns the thread id
		attr - Set to NULL if default thread attributes are used
		void * (*start_routine) - pointer to the function to be threaded
		*arg - pointer to argument to function
		*/
		iret = pthread_create(&threads[i], NULL, print_message_function, (void *)&td[i]);
		if (iret)
		{
			printf("Error: Unable to create thread, %d\n", iret);
			ret = 1;
		}

		/* Wait till threads are complete before main continues. Unless we */
		/* wait we run the risk of executing an exit which will terminate */
		/* the process and all threads before the threads have completed. */
		if (ret == 0) // No error
		{
			pthread_join(threads[i], NULL);
		}
		printf("Thread %d returns: %d\n", i, iret);
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
