#include <iostream>
using namespace std;

class Node {
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

Node* AddLists(Node* l1, Node* l2, int carry) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) return nullptr;

    Node* result = new Node();
    int value = carry;

    if (l1 != nullptr) value += l1->data;
    if (l2 != nullptr) value += l2->data;
    result->data = value % 10;    // data = ones digit

    /* Recurse */
    if (l1 != nullptr || l2 != nullptr) {
        Node* more = AddLists(l1 == nullptr? nullptr : l1->next, l2 == nullptr? nullptr : l2->next,
                value >= 10? 1: 0);
        result->next = more;
    }
    return result;
}

Node* AddLists(Node* l1, Node* l2) {
    return AddLists(l1, l2, 0);
}

int main() {
    Node* first = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    first = new Node();
    second = new Node();
    third = new Node();

    first->data = 7; // assign data in first node
    first->next = second; // Link first node with second

    second->data = 1; // assign data to second node
    second->next = third;

    third->data = 6; // assign data to third node
    third->next = NULL;

    Node* A = NULL;
    Node* B = NULL;
    Node* C = NULL;

    // allocate 3 nodes in the heap
    A = new Node();
    B = new Node();
    C = new Node();

    A->data = 5; // assign data in first node
    A->next = B; // Link first node with second

    B->data = 9; // assign data to second node
    B->next = C;

    C->data = 2; // assign data to third node
    C->next = NULL;

    PrintList(AddLists(first, A));

    return 0;
}