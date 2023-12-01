#include <iostream>
#include <stack>
using namespace std;

// using pairs
//  class MinStack {
//    stack < pair < int, int >> st;

//   public:
//     void push(int x) {
//       int min;
//       if (st.empty()) {
//         min = x;
//       } else {
//         min = std::min(st.top().second, x);
//       }
//       st.push({x,min});
//     }

//   void pop() {
//     st.pop();
//   }

//   int top() {
//     return st.top().first;
//   }

//   int getMin() {
//     return st.top().second;
//   }
// };

class MinStack
{
    stack<long long> st;
    long long mini;

public:
    MinStack()
    {
        while (st.empty() == false)
            st.pop();
        mini = INT_MAX;
    }

    void push(int val)
    {
        long long x = static_cast<long long>(val);
        if (st.empty())
        {
            mini = x;
            st.push(x);
        }
        else
        {
            if (x < mini)
            {
                st.push(2 * x - mini);
                mini = x;
            }
            else
            {
                st.push(x);
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        long long el = st.top();
        st.pop();
        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        long long el = st.top();
        if (el < mini)
        {
            return mini;
        }
        return el;
    }

    int getMin()
    {

        return mini;
    }
};