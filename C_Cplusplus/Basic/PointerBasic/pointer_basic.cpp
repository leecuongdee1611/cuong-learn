/*
    - khai bao con tro khac bitwise -> con tro 1 ngoi, biwise 2 ngoi
    - & -> address of operator
    - * -> dereference operator
    - size of pointer: x86 -> 32bit (4bytes), x64 -> 64bit (8bytes)
*/
#include <iostream>
using namespace std;

char *chPtr;
int *iPtr;
struct SomeThing
{
    int nX, nY, nZ;
};
SomeThing *somethingPtr;

/*
    - p la tham chieu den con tro
*/
void foo(int *&p)
{
}

int main()
{
    // basic
    int value = 10;
    int *ptr = &value;
    cout << &value << endl;
    cout << ptr << endl;

    // kieu du lieu cua con tro
    double dValue = 50.23;
    double *dPtr = &dValue;
    cout << typeid(ptr).name() << endl;

    // size of pointer
    cout << sizeof(chPtr) << endl;
    cout << sizeof(iPtr) << endl;
    cout << sizeof(somethingPtr) << endl;

    // truy cap con tro khong hop le
    int *p;
    foo(p);
    cout << *p;

    return 0;
}