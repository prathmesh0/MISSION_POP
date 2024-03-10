#include <bits/stdc++.h>
using namespace std;

class Hero
{
    // property
private:
    int health;

public:
    char *name;
    char level;
    static int timeToComplete;

    Hero()
    {
        name = new char[1000];
        cout << "Default Constructor called" << endl;
    }

    // parameterized constructor
    Hero(int health, char level)
    {
        cout << "this->" << this << endl;
        this->health = health;
        this->level = level;
    }

    // Copy Constructor
    Hero(Hero &temp)

    {

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->level = temp.level;
        this->health = temp.health;
    }
    void print()
    {
        cout << endl;
        cout << "[";
        cout << "name : " << this->name << ", ";
        cout << "health : " << this->health << ", ";
        cout << "level : " << this->level << "]";
        cout << endl;
    }

    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }
    void setHealth(int h)
    {

        health = h;
    }

    void setLevel(char l)
    {
        level = l;
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    static int random()
    {
        return timeToComplete;
    }
    // Destructor
    ~Hero()
    {
        cout << "Destructor called" << endl;
    };
};

// initialization of the static keyword

int Hero::timeToComplete = 5;
int main()
{
    // creation of object
    // Hero ramesh;
    // cout << "Ramesh Health is " << ramesh.getHealth() << endl;
    // ramesh.setHealth(69);
    // // ramesh.health = 70;
    // ramesh.level = 'A';

    // cout << "health is " << ramesh.getHealth() << endl;
    // // cout << "health is " << ramesh.health << endl;
    // cout << "level is " << ramesh.level << endl;
    // cout << "Size = " << sizeof(ramesh) << endl;

    // // Static allocation
    // Hero a;
    // a.setHealth(30);
    // a.setLevel('A');
    // cout << "Level is " << a.level << endl;
    // cout << "Health is " << a.getHealth() << endl;

    // // dynamically
    // Hero *b = new Hero;
    // b->setHealth(70);
    // b->setLevel('A');
    // cout << "Level is " << (*b).level << endl;
    // cout << "Health is " << (*b).getHealth() << endl;

    // cout << "Level is " << b->level << endl;
    // cout << "Health is " << b->getHealth() << endl;

    // object created statically
    // Hero mangesh(10, 'A');
    // cout << "address of Mangesh = " << &mangesh << endl;

    // // object create dyanamically
    // Hero *m = new Hero(10, 'B');

    // Hero suresh;
    // suresh.setHealth(90);
    // suresh.setLevel('B');
    // suresh.print();

    // // Copy Constructor
    // Hero stark(suresh);
    // stark.print();

    // Shallow and Deep Copy
    // Default  Copy Constructor => Shallow Copy => Same Memory
    // Copy Constructor => Deep Copy => Different Memory
    // Hero h1;
    // h1.setHealth(12);
    // h1.setLevel('B');
    // char name[4] = "pop";
    // h1.setName(name);
    // // h1.print();

    // // default copy
    // Hero h2(h1);
    // // h2.print();
    // // Hero sham = ram;
    // h1.name[0] = 'D';
    // h1.print();

    // h2.print();

    // // copy assignment operator
    // h1 = h2;
    // h1.print();
    // h2.print();

    // statically allocate
    // Hero a;
    // // Dynamic allocate
    // Hero *b = new Hero();

    // // manually destructor called
    // delete b;

    // called Static Member
    cout << Hero::timeToComplete << endl;
    cout << Hero::random() << endl;
    // Hero x;
    // cout << x.timeToComplete << endl;

    // Hero y;
    // y.timeToComplete = 10;
    // cout << x.timeToComplete << endl;
    // cout << y.timeToComplete << endl;
    // constant KeyWord
    //  Initialization List

    return 0;
}