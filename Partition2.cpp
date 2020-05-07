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
    Node* head = n;
    Node* tail = n;

    while (n != nullptr) {
        Node* next = n->next;
        if (n->data < x) {
            n->next = head;
            head = n;
        } else {
            tail->next = n;
            tail = n;
        }
        n = n->next;
    }
    return head;
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