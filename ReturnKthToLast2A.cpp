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

int PrintKthToLast(Node* head, int k) {
    if (head == nullptr) {
        return 0;
    }
    int index = PrintKthToLast(head->next, k) + 1;
    if (index == k) {
        cout << k << "th to last node is " << head->data << endl;
    }
    cout << "index is " << index << endl;
    return index;
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

    PrintKthToLast(head, 2);

    return 0;
}