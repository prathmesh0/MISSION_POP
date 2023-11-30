#include <iostream>

// The Node class definition

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// The Stack class definition

class Stack
{
    Node *head;
    int size;

public:
    Stack()
    {
        head = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        size++;
    }

    void pop()
    {
        if (size == 0)
        {
            return;
        }
        Node *h = head;
        head = head->next;
        delete h;
        size--;
    }

    int getTop()
    {
        if (size == 0)
        {
            return -1;
        }
        return head->data;
    }
};

// Input function for the Stack

void input(Stack &stack)
{
    int n, element;
    std::cout << "Enter the number of elements to push: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> element;
        stack.push(element);
    }
}

int main()
{
    Stack stack;
    input(stack);

    // Example: Displaying the top element after pushing input
    std::cout << "Top element on the stack: " << stack.getTop() << std::endl;

    return 0;
}
