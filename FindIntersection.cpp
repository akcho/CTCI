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

class Result {
public:
    Node* tail;
    int size;
    Result(Node* t, int s) {
        tail = t;
        size = s;
    }
};

Result GetTailAndSize(Node* list) {
    if (list == nullptr) return Result(nullptr, 0);
    int size = 1;
    Node* current = list;
    while (current->next != nullptr) {
        size++;
        current = current->next;
    }
    return Result(current, size);
}

Node* GetKthNode(Node* head, int k) {
    Node* current = head;
    while (k > 0 && current != nullptr) {
        current = current->next;
        k--;
    }
    return current;
}

Node* FindIntersection(Node* list1, Node* list2) {
    if (list1 == nullptr || list2 == nullptr) return nullptr;

    /* Get tail and sizes. */
    Result result1 = GetTailAndSize(list1);
    Result result2 = GetTailAndSize(list2);

    /* If different tail nodes, then there's no intersection. */
    if (result1.tail != result2.tail) return nullptr;

    /* Set pointers to the start of each linked list */
    Node* shorter = result1.size < result2.size? list1 : list2;
    Node* longer = result1.size < result2.size? list2 : list1;

    /* Advance the pointer for the longer LL by difference in lengths. */
    longer = GetKthNode(longer, abs(result1.size - result2.size));

    /* Move both pointers until you have a collision. */
    while (shorter != longer) {
        shorter = shorter->next;
        longer = longer->next;
    }

    /* Return either one. */
    return longer;
}

int main() {
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    one = new Node();
    two = new Node();
    three = new Node();

    Node* A = NULL;
    Node* B = NULL;
    Node* C = NULL;

    A = new Node();
    B = new Node();
    C = new Node();

    Node* intersection = NULL;
    Node* i2 = NULL;
    Node* i3 = NULL;

    intersection = new Node();
    i2 = new Node();
    i3 = new Node();

    intersection->data = 100;
    intersection->next = i2;

    i2->data = 200;
    i2->next = i3;

    i3-> data = 300;
    i3->next = nullptr;

    one->data = 1; // assign data in first node
    one->next = two; // Link first node with second

    two->data = 2; // assign data to second node
    two->next = three;

    three->data = 3; // assign data to third node
    three->next = intersection;

    A->data = 11; // assign data in first node
    A->next = B; // Link first node with second

    B->data = 12; // assign data to second node
    B->next = C;

    C->data = 13; // assign data to third node
    C->next = intersection;



    Node* answer = FindIntersection(A, one);
    cout << answer->data << endl;
    return 0;
}