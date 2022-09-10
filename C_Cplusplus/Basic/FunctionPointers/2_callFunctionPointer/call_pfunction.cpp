#include <iostream>
using namespace std;

void swapNumber(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    void(*ptrSwap)(int &, int &) = swapNumber;

    int a = 5, b=10;
    cout << "Before: " << a << " " << b << endl;

    // goi ham tuong minh
    (*ptrSwap)(a,b);
    cout << "After: " << a << " " << b << endl;

    // goi ham ngam dinh
    ptrSwap(a,b);
    cout << "After: " << a << " " << b << endl;

    // goi ham truc tiep
    swapNumber(a,b);
    cout << "After: " << a << " " << b << endl;
}