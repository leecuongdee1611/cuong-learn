/*
    Inheritance: ke thua
    Allows us to define a class in terms of another class
        Base class
        Derived class
        -> class derived-class: access-specifier base-class
            access-specifier: public, protected or private
                public: accessible from outside the class
                private: cannot be accessed (or viewed) from outside the class
                Protected: same private but can be accessed in inherited classes
*/

#include <iostream>
using namespace std;

// Base class
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }

protected:
    int width;
    int height;
};

// Derived class
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
};

int main()
{
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(7);

    // print
    cout << "Total area: " << Rect.getArea() << endl;

    return 0;
}