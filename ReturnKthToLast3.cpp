// Solution 2A:
// Recursive: Don't return the element

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

Node* nthToLast(Node* head, int k) {
    Node* p1 = head;
    Node* p2 = head;
    for (int i = 0; i < k; i++) {
        if (p1 == nullptr) return nullptr;
        p1 = p1->next;
    }
    while (p1 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
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

    cout << nthToLast(head, 3)->data;

    return 0;
}