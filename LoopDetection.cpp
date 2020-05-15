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

Node* FindBeginning(Node* head) {
    Node* slow = head;
    Node* fast = head;

    /* Find meeting point. This will be LOOP_SIZE - k steps into the linked list. */
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;    // Collision
    }

    /* Error check - no meeting point, and therefore no loop */
    if (fast == nullptr || fast->next == nullptr) return nullptr;

    /* Move slow to Head. Keep fast at Meeting Point. Each are k steps from the Loop Start. If they move at the same
     * pace, they must meet at Loop Start. */

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    /* Both now point to the start of the loop. */
    return slow;
}

int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;
    Node* sixth = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = fourth;

    fourth->data = 4; // assign data to third node
    fourth->next = fifth;

    fifth->data = 5; // assign data to third node
    fifth->next = sixth;

    sixth->data = 6; // assign data to third node
    sixth->next = fourth;

    cout << FindBeginning(head)->data;

    return 0;
}