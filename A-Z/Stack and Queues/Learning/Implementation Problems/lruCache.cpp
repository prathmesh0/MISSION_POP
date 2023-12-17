#include <iostream>
#include <unordered_map>

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    std::unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newnode) {
        Node* temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node* delnode) {
        Node* prevv = delnode->prev;
        Node* nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int ans = resNode->val;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

void simulateLRUCache() {
    LRUCache obj(2); // Creating an LRU Cache with capacity 2

    obj.put(1, 10); // Adding key=1, value=10
    obj.put(2, 20); // Adding key=2, value=20

    std::cout << obj.get(1) << std::endl; // Output: 10
    obj.put(3, 30); // Adding key=3, value=30 (Evicting key=2 as it's the least recently used)

    std::cout << obj.get(2) << std::endl; // Output: -1 (Key 2 is no longer present)
    obj.put(4, 40); // Adding key=4, value=40 (Evicting key=1)

    std::cout << obj.get(1) << std::endl; // Output: -1 (Key 1 is no longer present)
    std::cout << obj.get(3) << std::endl; // Output: 30
    std::cout << obj.get(4) << std::endl; // Output: 40
}

int main() {
    simulateLRUCache(); // Simulate operations on LRUCache
    return 0;
}
