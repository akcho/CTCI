// This time, the digits aren't in reverse. So the head node is not the ones digit. The last node holds the ones digit.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class PartialSum {
public:
    Node* sum = nullptr;
    int carry = 0;
};

void PrintList(Node* n) {
    while (n != nullptr) {
        cout << n->data << " " ;
        n = n->next;
    }
}

int FindLength(Node* l) {
    int count = 0;
    Node* p = l;
    while ( p != nullptr) {
        ++count;
        p = p->next;
    }
    return count;
}

Node* InsertBefore(Node* list, int x) {
    Node* n = new Node();
    n->data = x;
    n->next = list;
    return n;
}

/* pad lists with zeroes so that the number of digits match */
Node* PadList(Node* list, int padding) {
    Node* head = list;
    for (int i = 0; i < padding; i++) {
        head = InsertBefore(head, 0);
    }
    return head;
}

PartialSum* AddListsHelper(Node* l1, Node* l2) {
    if (l1== nullptr && l2 == nullptr) {
        PartialSum* sum = new PartialSum();
        return sum;
    }

    /* Add smaller digits recursively */
    PartialSum* sum = AddListsHelper(l1->next, l2->next);

    /* Add carry to current data */
    int val = sum->carry + l1->data + l2->data;

    /* Return sum so far, and the carry value */
    sum->sum = InsertBefore(sum->sum, val % 10);
    sum->carry = val / 10;
    return sum;
}

Node* AddLists(Node* l1, Node* l2) {
    int len1 = FindLength(l1);
    int len2 = FindLength(l2);

    /* Pad the shorter list with zeros */
    if (len1 < len2) {
        l1 = PadList(l1, len2 - len1);
    } else {
        l2 = PadList(l2, len1 - len2);
    }

    /* Add lists */
    PartialSum* sum = AddListsHelper(l1, l2);

    /* If there was a carry value left over, insert this at the front of the list.
     * Otherwise, just return the linked list. */
    if (sum->carry == 0) {
        return sum->sum;
    } else {
        Node* result = InsertBefore(sum->sum, sum->carry);
        return result;
    }
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

    Node* answer = AddLists(first, A);
    PrintList(answer);
    return 0;
}
