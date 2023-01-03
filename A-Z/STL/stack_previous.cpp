#include <iostream>
#include <stack>
using namespace std;

void showstack(stack<int> g)
{
    stack<int> lp = g;
    while (!lp.empty())
    {
        cout << lp.top() << " ";
        lp.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> dog; // works on lifo principle
    dog.push(12);
    dog.push(8);
    dog.push(32);
    dog.push(10);
    showstack(dog);
    dog.push(39);
    showstack(dog);

    dog.pop(); // pop topmost element
    showstack(dog);

    cout << "top elemnent in the stack = " << dog.top() << endl;
    dog.emplace(40);
    showstack(dog);

    cout << "swapping two stack: " << endl;
    stack<int> man;
    stack<int> lady;
    man.push(12);
    man.push(10);
    man.push(11);
    lady.push(15);
    lady.push(17);
    lady.push(18);
    cout << "before swapping:" << endl;
    showstack(man);
    showstack(lady);
    man.swap(lady);
    cout << "after swapping:" << endl;
    showstack(man);
    showstack(lady);
    //----> stack empty or not
    if (man.empty())
    {
        cout << "stack is empty " << endl;
    }
    else
    {
        cout << "stack is not empty " << endl;
    }

    cout << "size of stack:" << man.size() << endl;
    return 0;
}