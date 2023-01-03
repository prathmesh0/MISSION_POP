#include <iostream>
#include <queue>
using namespace std;

// max heap
void Print(priority_queue<int> pq)
{
    priority_queue<int> p = pq;
    while (!p.empty())
    {
        cout << p.top() << "\t";
        p.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int> pq;
    for (int i = 1; i <= 5; i++)
    {
        pq.push(i);
    }
    cout << "The element in the priority queue " << endl;
    Print(pq);

    cout << "the size of the priority queue " << pq.size() << endl;
    cout << "the top element of the priority queue " << pq.top() << endl;
    pq.pop();
    cout << "after removing the top element " << endl;
    Print(pq);
    return 0;
}