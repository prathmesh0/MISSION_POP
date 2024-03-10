#include <iostream>
using namespace std;

class A
{
public:
    void sayhello()
    {
        cout << "hello Pop" << endl;
    }

    int sayhello(string name, int n)
    {
        cout << "hello Pop" << endl;
        return n;
    }

    void sayhello(string name)
    {
        cout << "hello Pop" << endl;
    }
};

class B
{
public:
    int a;
    int b;

public:
    int add()
    {
        return a + b;
    }

    void operator+(B &obj)
    {
        //     int val1 = this->a;
        //     int val2 = obj.a;
        //     cout << "Output " << val2 - val1 << endl;
        cout << "Hello POP" << endl;
    }
    void operator()()
    {
        cout << "Main Bracket Hu.." << this->a << endl;
    }
};

class Animal
{
public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Barking" << endl;
    }
};
int main()
{
    // PolyMorphism - many forms
    // Two  types - Compile Time , RunTime Time

    // Compile type -> Function Overloading ->Operator Overloading

    // A obj;
    // obj.sayhello();

    // B obj1, obj2;
    // obj1.a = 4;
    // obj2.a = 7;

    // obj1 + obj2;
    // obj1();

    //  Runtime type -> Method Overriding
    Dog d;
    d.speak();
    return 0;
}