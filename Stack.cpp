#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
    }
    Node(int i) {
        data = i;
    }
};
Node* top;

int pop() {
    if (top == nullptr) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    } else {
        int item = top->data;
        top = top->next;
        return item;
    }
}

void push(int item) {
    Node* i = new Node;
    i->next = top;
    top = i;
}

int peek() {
    if (top == nullptr) exit(1);
    return top->data;
}

bool IsEmpty() {
    return top == nullptr;
}

int main() {
    Node test(3);

    cout << test.data;
    return 0;
}