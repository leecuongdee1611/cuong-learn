#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

void *wait(void *t)
{
    int i;
    long tid;

    tid = (long)t;
    
    sleep(1);

    printf("Sleeping in thread \n");
    printf("Thread with id: %ld ...exiting\n", tid);
}

int main(void)
{
    int rc;
    int i;

   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void *status;

   /* Initialize and set thread joinable */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for (i = 0; i < NUM_THREADS; i++)
   {
        printf("Main: Creating thread %d\n", i);
        rc = pthread_create(&threads[i], &attr, wait, (void *)&i);
        if (rc)
        {
            printf("Error: Unable to create thread %d\n", rc);
            exit(-1);
        }
   }

   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);
   for (i = 0; i < NUM_THREADS; i++)
   {
    rc = pthread_join(threads[i], &status);
    if(rc)
    {
        printf("Error: Unable to join %d\n", rc);
        exit(-1);
    } 
    printf("Main: completed thread id: %d ",i);
    printf("exiting with status: \n");
   }

   printf("Main: Program exiting.\n");
   pthread_exit(NULL);

    return 0;
}
