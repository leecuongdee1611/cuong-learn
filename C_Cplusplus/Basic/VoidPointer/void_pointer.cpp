/*
    ep kieu: int *intPtr = static_cast<int*>(voidPtr)
    ung dung: viet ham khac kieu du lieu dau vao
*/

#include <iostream>
using namespace std;

enum Type
{
    INT,
    DOUBLE
};

void printValueOfPointer(void *ptr, Type type)
{
    switch (type)
    {
    case INT:
        // ep con tro void thanh con tro int
        cout << *(static_cast<int *>(ptr)) << endl;
        break;
    case DOUBLE:
        // ep con tro void thanh con tro double
        cout << *(static_cast<double *>(ptr)) << endl;
        break;
    }
}

int main()
{
    int nValue = 10;
    double dValue = 6.9;

    printValueOfPointer(&nValue, INT);
    printValueOfPointer(&dValue, DOUBLE);

    system("pause");
    return 0;
}