/*
    Overloading: nap chong ham
    Ung dung
        Ham co cung chuc nang (cung ten) nhung khac kieu du lieu dau vao
    Ham khong the nap chong
        giong nhau tham so dau vao, khac nhau kieu tra ve
        ham kieu typedef
        ham kieu con tro va mang
        const -> chi khi tham chieu hoac tham tri
*/

#include <iostream>
using namespace std;

class printData
{
public:
    void print(int i)
    {
        cout << "Print interger: " << i << endl;
    }
    void print(double f)
    {
        cout << "Print double: " << f << endl;
    }
    void print(const char* c) // string constant. If not use const -> ISO C++ forbids converting a string constant to ‘char*’
    {
        cout << "Print char: " << c << endl;
    }
};

int main()
{
    printData pd;
    pd.print(5);
    pd.print(5.1);
    pd.print("Hello world"); 

    return 0;
}
