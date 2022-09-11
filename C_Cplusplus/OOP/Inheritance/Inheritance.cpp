#include <iostream>
using namespace std;

// Base class (parent)
class MyClass
{
public:
    void myFunction()
    {
        cout << "Some content in parent class." << endl;
    }
};

// Derived class (child)
class MyChild : public MyClass
{
};

// Another base class
class MyOtherClass
{
public:
    void myOtherFunction()
    {
        cout << "Some content in another class." << endl;
    }
};

// Derived class (grandchild)
class MyGrandChild : public MyChild, public MyOtherClass
{
};

int main()
{
    MyGrandChild myObj;
    myObj.myFunction();
    myObj.myOtherFunction();
    return 0;
}