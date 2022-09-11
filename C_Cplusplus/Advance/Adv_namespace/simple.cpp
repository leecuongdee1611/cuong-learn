#include <iostream>
using namespace std;

// first namespace
namespace first_space
{
    void func()
    {
        cout << "Inside first_space" << endl;
    }
}

// first namespace
namespace second_space
{
    void func()
    {
        cout << "Inside second_space" << endl;
    }

    // thirth_space
    namespace thirth_space
    {
        void func2()
        {
            cout << "Inside thirth_space" << endl;
        }
    }
}

// the using directive
using namespace first_space;
using namespace second_space::thirth_space;

int main()
{
    // Calls function from first name space
    first_space::func();

    // Calls function from second name space
    second_space::func();

    // The using directive
    func();
    func2();

    return 0;
}