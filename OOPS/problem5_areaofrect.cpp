#include <iostream>
using namespace std;

class Rectangle
{
public:
    int length, breadth;

    int getArea()
    {
        return (length * breadth);
    }
};

int main()
{
    // Creating an object of Rectangle class
    Rectangle rect;

    // Assigning values to length and breadth
    rect.length = 5;
    rect.breadth = 3;

    // Calculating and printing the area
    std::cout << "Area of the rectangle: " << rect.getArea() << std::endl;

    return 0;
}
