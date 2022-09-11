/*
    Link: https://www.tutorialspoint.com/cplusplus/cpp_preprocessor.htm
    Preprocessor -> begin with #
        #include, #define, #if, #else, #line, etc
    Check
        gcc -E preprocessor.cpp > test.p
    Path
        #define
        Function-Like Macros
        Conditional Compilation -> #ifdef, #ifndef, #endif
        # and ##
        Predefined

*/
#include <iostream>
using namespace std;
#define DEBUG
#define MKSTR(x) #x
#define concat(a, b) a##b

// Macro
#define PI 3.14159
// Function-Like Macros
#define MIN(a, b) (((a) < (b)) ? a : b)
//Cinditional Compilation

int main()
{
    cout << "Value of PI: " << PI << endl;

    int i, j;
    i = 100;
    j = 30;
#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif

    int xy = 100;
    cout << MKSTR(HELLO C++) << endl;
    cout << concat(x, y) << endl;
#if 0
    /* This is commented part */
    cout<<MKSTR(HELLO C++) << endl;
#endif

    cout << "The minimum is " << MIN(i, j) << endl;
#ifdef DEBUG
    cerr << "Trace: Coming out of main function" << endl;
#endif

// Predefined Macros
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;

    return 0;
}