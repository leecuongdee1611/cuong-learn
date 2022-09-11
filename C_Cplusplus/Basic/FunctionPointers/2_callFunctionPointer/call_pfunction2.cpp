#include <functional>
#include <iostream>
using namespace std;

void swapNumber(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    // void(*ptrSwap)(int &, int &) = swapNumber;
    function<void(int&,int&)> ptrSwap = swapNumber;

    int a = 5, b=10;
    cout << "Before: " << a << " " << b << endl;

    // goi ham ngam dinh
    ptrSwap(a,b);
    cout << "After: " << a << " " << b << endl;

    return 0;
}