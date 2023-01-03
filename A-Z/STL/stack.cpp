#include <iostream>
#include <stack>
using namespace std;

void PrintStack(stack<int> s)
{
    stack<int> s1 = s;
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }
    PrintStack(s);

    cout << "The size of the stack " << s.size() << endl;
    cout << "The top element of the stack " << s.top() << endl;
    s.pop();
    PrintStack(s);
    s.emplace(133);
    PrintStack(s);
    return 0;
}