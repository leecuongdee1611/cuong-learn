/*
    tree keywords: try, catch, and throw
*/

#include <iostream>
using namespace std;

int main()
{
    int x = -1;
    // Some code
    cout << "Before try \n";
    try
    {
        cout << "Inside try \n";
        if (x < 0)
        {
            // case 1: throw x;
            // case 2:throw "this a a char";
            throw 'a';
            cout << "After throw (Never executed)" << endl;
        }
    }
    catch (int x)
    {
        cerr << "Exception Caught" << endl;
    }
    catch (const char *msg)
    {
        cerr << "Exception: " << msg << endl;
    }
    catch(...)
    {
        cerr << "Default Exception" << endl;
    }

    cout << "After catch (Will be executed) \n";

    return 0;
}