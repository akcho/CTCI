#include <iostream>
#include <unordered_set>
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

void DeleteDups(Node* n) {
    unordered_set<int> seen;
    struct Node *prev = nullptr;

    while (n != nullptr) {
        if (seen.find(n->data) != seen.end()) {    // if n is in the hash set
            prev->next = n-> next;    // set prev node's next to n's next (essentially skipping over that repeat node)
        } else {
            seen.insert(n->data);
            prev = n;
        }
        n = prev->next;
    }


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