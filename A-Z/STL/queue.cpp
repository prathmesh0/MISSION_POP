#include <iostream>
#include <queue>
using namespace std;

void PrintQueue(queue<int> q)
{
    queue<int> q1 = q;
    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
}

int main()
{
    queue<int> q;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }
    cout << "The element of the queue are " << endl;
    PrintQueue(q);

    cout << "Size of the queue :" << q.size() << endl;
    cout << "front element of the queue " << q.front() << endl;
    q.emplace(34);
    q.emplace(56);
    PrintQueue(q);
    cout << endl;
    cout << "last element of the queue " << q.back() << endl;
    q.pop();
    PrintQueue(q);
    cout << endl;
    if (q.empty())
    {
        cout << "queue is an empty " << endl;
    }
    else
    {
        cout << "queue is not an empty " << endl;
    }
    return 0;
}