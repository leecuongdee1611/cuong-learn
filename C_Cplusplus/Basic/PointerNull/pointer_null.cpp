/*
Thong thuong, con tro khong duoc khoi tao 1 gia tri -> gia tri rac
Null la gia tri dac biet, nghia la con tro chua tro den gia tri nao ca
*/
#include <iostream>
using namespace std;

void doSomething(double *ptr)
{
    // ptr la true neu no null, nguoc lai la false
    if (ptr)
    {
        cout << "You passed in " << *ptr << endl;
    }
    else
    {
        cout << "You passed in a null pointer" << endl;
    }
}

int main()
{
    doSomething(0);
    return 0;
}