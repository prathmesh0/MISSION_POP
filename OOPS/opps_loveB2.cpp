#include <bits/stdc++.h>
using namespace std;

// Encapsulation
class Student
{
private:
    string name;
    int age;
    int height;

public:
    int getAge()
    {
        return this->age;
    }
};

// Inheritance
class Human
{
protected:
    int height;

public:
    int weight;

private:
    int age;

public:
    int getAge()
    {
        return this->age;
    }

    void setWeight(int w)
    {
        this->weight = w;
    }
};

class Male : private Human
{
public:
    string color;

    void sleep()
    {
        cout << "Male is sleeping" << endl;
    }
    int getHeight()
    {
        return this->height;
    }
};


int main()
{
    // Encapsulation- Wrappig up data member and the functions
    // Fully encapsulated class - all memebers are private marked
    // advantages = Inforamation/data hidings, We can make read only class,code reusability, unit testing
    Student first;

    // Inheritance
    // mode of Inheritance

    // Male object1;
    // cout << object1.age << endl;
    // cout << object1.weight << endl;
    // cout << object1.height << endl;
    // cout << object1.color << endl;
    // object1.setWeight(45);
    // cout << object1.weight << endl;
    // object1.sleep();

    // Super-class     //Base class
    /*
    Public              Public      Public
    Public              Private     Private
    Public              Protected   Protected

    Protected           Public      Protected
    Protected           Protected   Protected
    Protected           Private     Private

    Private             Public      NA
    Private             Private     NA
    Private             Protected   NA

    */
    Male m1;
    cout << m1.getHeight() << endl;

    // types of inheritance
    // Single, multi-level, multiple, hybrid, heirarchical

    return 0;
}