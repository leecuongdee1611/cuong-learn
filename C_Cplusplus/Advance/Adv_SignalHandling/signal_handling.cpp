/*
Link: https://www.tutorialspoint.com/cplusplus/cpp_signal_handling.htm
Signals are the interrupts by pressing Ctrl + C
raise() function
    generate signals by function raise()
*/
#include <iostream>
#include <unistd.h>
#include <csignal>
using namespace std;

void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here
    // terminate program

    exit(signum);
}

int main()
{
    int i = 0;
    // register signal SIGINT and signal handler
    signal(SIGINT, signalHandler);

    while (++i)
    {
        cout << "Going to sleep..." << endl;
        if (i == 5)
        {
            raise(SIGINT);
        }
        sleep(1);
    }

    return 0;
}