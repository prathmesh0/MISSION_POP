#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Person
{

private:
    string name;
    int age;

public:
    void set(string name, int age)
    {
        this->age = age;
        this->name = name;
    }

    void getValue()
    {
        cout << "The name of the person is " << this->name << " and the age is " << this->age << ".";
    }
};

int main()
{

    Person p;
    string name;
    int age;
    cin >> name >> age;
    p.set(name, age);
    p.getValue();

    return 0;
}