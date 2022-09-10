#include <iostream>
#include <bootst/shared_ptr.hpp>
#include <bootst/filesystem.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello Third Party Include!" << endl;

    // trivial use of boost filesystem
    boost::filesystem::path path = "/usr/share/cmake/modules";
    if (path.is_relative())
    {
        std::cout << "Path is relative" << std::endl;
    }
    else
    {
        std::cout << "Path is not relative" << std::endl;
    }

    return 0;
}