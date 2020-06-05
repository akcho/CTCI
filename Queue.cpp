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
Node* first;
Node* last;

void add(int i) {
    Node* n = new Node(i);
    if (last != nullptr) last->next = n;
    last = n;
    if (first == nullptr) first = last;
}

int remove() {
    if (first == nullptr) exit(1);
    int data = first->data;
    first = first->next;
    if (first == nullptr) last = nullptr;
    return data;
}

int peek() {
    if (first == nullptr) exit(1);
    return first->data;
}

bool is3() {
    return first == nullptr;
}

int main() {
    Node A(1);
    Node B(2);
    Node C(3);


    return 0;
}