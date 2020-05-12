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

int LengthOfList(Node* n) {
    int size = 0;
    while (n != nullptr) {
        size++;
        n = n->next;
    }
    return size;
}

bool IsPalindromeRecurse(Node* head, int length, Node** next) {
    if (head == nullptr || length <= 0) {
        (*next) = head;
        return true;
    } else if (length == 1) {
        (*next) = head->next;
        return true;
    }
    /* Recurse on sublist. */
    bool result = IsPalindromeRecurse(head->next, length - 2, next);

    /* If child calls are not a palindrome, pass back up a failure. */
    if (!result || next == nullptr) {
        return false;
    }

    /* Check if matches corresponding node on other side. */
    result = (head->data == (*next)->data);

    /* Shift to corresponding node */
    (*next) = (*next)->next;

    return result;
}

bool IsPalindrome(Node* head) {
    int length = LengthOfList(head);
    Node** next = new Node*;
//    (*next) = new Node();
    return IsPalindromeRecurse(head, length, next);
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