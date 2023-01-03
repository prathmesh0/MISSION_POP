#include <iostream>
#include <queue>
using namespace std;
void showq(queue<int> fd)
{
    queue<int> g = fd;
    while (!g.empty())
    {
        cout << " " << g.front();
        g.pop();
    }
    cout << endl;
}

void showq(queue<char> fd)
{
    queue<char> g = fd;
    while (!g.empty())
    {
        cout << " " << g.front();
        g.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> food;
    food.push(12);
    food.push(13);
    food.push(10);
    food.push(14);
    showq(food);
    cout << "size of q " << food.size() << endl;
    food.emplace(30);
    showq(food);
    cout << "first in q = " << food.front() << endl;
    cout << "last in q = " << food.back() << endl;

    queue<char> c;
    queue<char> d;
    c.push('s');
    c.push('p');
    d.push('a');
    d.push('b');
    cout << "before swapping " << endl;
    showq(c);
    showq(d);
    c.swap(d);
    cout << "after swapping " << endl;
    showq(c);
    showq(d);
    return 0;
}