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

Node* ReverseAndClone(Node* node) {
    Node* head = nullptr;
    while (node != nullptr) {
        Node* n = new Node();
        n->data = node->data;
        n->next = head;
        head = n;
        node = node->next;
    }
    return head;
}

bool IsEqual(Node* l1, Node* l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data != l2->data) {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}



bool IsPalindrome(Node* head) {
    Node* reversed = ReverseAndClone(head);
    return IsEqual(head, reversed);
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