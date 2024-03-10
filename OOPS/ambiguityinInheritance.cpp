#include <iostream>
using namespace std;

class A
{
public:
    void func1()
    {
        cout << "Inside A class" << endl;
    }
};

class B
{
public:
    void func1()
    {
        cout << "Inside B Class" << endl;
    }
};

class C : public A, public B
{
};

int main()
{
    C obj;
    obj.A::func1();
    obj.B::func1();

    return 0;
}