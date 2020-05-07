// Solution 2B:
// Recursive: Use C++

#include <iostream>
using namespace std;

struct Node {
public:
    int data;
    Node* next;
};

void PrintList(Node* n) {
    while (n != nullptr) {
        cout << n->data << " " ;
        n = n->next;
    }
}

Node* nthToLast(Node* head, int k, int& i) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* nd = nthToLast(head->next, k, i);
    i++;
    if (i == k) {
        return head;
    }
    return nd;
}

Node* nthToLast(Node* head, int k) {
    int i = 0;
    return nthToLast(head, k, i);
}


int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;

    return 0;
}