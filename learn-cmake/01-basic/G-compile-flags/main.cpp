#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "Hello Compile Flags!" << endl;

// only print if compile flag set
#ifdef EX2
    cout << "Hello Compile Flag EX2!" << endl;
#endif

#ifdef EX3
    cout << "Hello Compile Flag EX3!" << endl;
#endif
    return 0;
}