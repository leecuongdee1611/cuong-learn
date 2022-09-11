/*
    Two types of multitasking: process-based and thread-based
    Process-based
        handles the concurrent execution of programs
    Thread-based
        handles the concurrent execution of pieces of the same program
    Upon the operating system
    POSIX threads or pthread
    Content
        Creating threads -> pthread_create
        Terminating threads -> pthread_exit
        Passing Argument to threads use struct
        Joining and Detaching Threads
    Run: g++ multithreading.cpp -lpthread
*/
#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

struct thread_data
{
    int thread_id;
    const char *message;
};

void *PrintHello(void *threadarg)
{
    struct thread_data *my_data;
    my_data = (struct thread_data *)threadarg; // ep kieu

    cout << "Thread ID: " << my_data->thread_id;
    cout << " Message: " << my_data->message << endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "main(): Creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = "This is message";
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);

        if (rc)
        {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);

    return 0;
}