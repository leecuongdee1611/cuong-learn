#include <iostream>
using namespace std;

void swapNumber(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    auto ptrSwap = swapNumber;

    int a = 5, b = 10;
    cout << "Before: " << a << " " << b << endl;

    ptrSwap(a, b);
    cout << "After: " << a << " " << b << endl;
    
    return 0;
}