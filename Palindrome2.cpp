// Uses slow/fast runner + stack to compare two halves of a LL

#include <iostream>
#include <stack>
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

bool IsPalindrome(Node* head) {
    Node* fast = head;
    Node* slow = head;

    stack<int> stack;

    /* Push elements from first half of LL onto stack. When fast runner (which moves at 2x speed) reaches the end of
     * the LL, then we know we're at the middle */
    while (fast != nullptr && fast->next != nullptr) {
        stack.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Has odd number of elements, so skip the middle element */
    if (fast != nullptr) slow = slow->next;

    while (slow != nullptr) {
        int top = stack.top();
        stack.pop();

        /* If values are different, then it's not a palindrome */
        if (top != slow->data) return false;
        slow = slow->next;
    }
    return true;
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

    third->data = 1; // assign data to third node
    third->next = NULL;

    return IsPalindrome(head);
}