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

Node* Partition(Node* n, int x) {    // Pass in the head of the linked list and the value to partition around
    Node* before_start = nullptr;
    Node* before_end = nullptr;
    Node* after_start = nullptr;
    Node* after_end = nullptr;

    while (n != nullptr) {
        Node* next = n->next;
        n->next = nullptr;
        if (n->data < x) {    // insert node into end of "before" list
            if (before_start == nullptr) {
                before_start = n;
                before_end = before_start;
            } else {
                before_end->next =n;
                before_end = n;
            }
        } else {    // insert node into end of "after" list
            if (after_start == nullptr) {
                after_start = n;
                after_end = after_start;
            } else {
                after_end->next = n;
                after_end = n;
            }
        }
        n = next;
    }
    if (before_start == nullptr) return after_start;
    /* Merge the two lists */
    before_end->next = after_start;
    return before_start;
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

    PrintList(head);

    return 0;
}