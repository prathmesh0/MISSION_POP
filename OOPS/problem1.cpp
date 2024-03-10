#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class ComplexNumbers
{
    // constructor
public:
    int real, img;

    ComplexNumbers(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void plus(ComplexNumbers b)
    {
        this->real += b.real;
        this->img += b.img;
    }

    void multiply(ComplexNumbers b)
    {
        int temp = this->real;
        this->real = this->real * b.real - this->img * b.img;
        this->img = temp * b.img + b.real * this->img;
    }

    void print()
    {
        cout << real << " + "
             << "i" << img << endl;
    }
};

int main()
{
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        return 0;
    }
}