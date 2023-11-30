#include <iostream>
#include <stack>
#include <queue>
using namespace std;


//Leetcode usind bruteforce

// class MyStack {
// queue<int> q1, q2;
//     // to maintain the length of the stack
//     int len;
// public:
//     MyStack() {
//        len = 0;
//     }
    
//     void push(int x) {
//         len++;
//         q2.push(x);
//         while(!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
        
//         queue<int> q = q1;
//         q1 = q2;
//         q2 = q;
//     }
    
//     int pop() {
//         if(q1.empty())
//            return -1;
        
//         int top = q1.front();
//         q1.pop();
//         len--;
//         return top;
//     }
    
//     int top() {
//         if(q1.empty())
//             return -1;
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


//Leetcode Using Optimal


class Stack
{
    queue<int> q1, q2;

public:
    void Push(int x)
    {
        q2.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }

    int Pop()
    {
        int n = q1.front();
        q1.pop();
        return n;
    }

    int Top()
    {
        return q1.front();
    }

    int Size()
    {
        return q1.size();
    }
};

int main()
{
    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);
    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size();
    return 0;
}