// implementation file

#include "LinkedList.h"
#include <iostream>
#include <vector>
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(0) {}

LinkedList::LinkedList(const LinkedList &other) : head(other.head), tail(other.tail) {
     // default behavior is the above

    // this isn't good! We should copy any of the elements
    // so that if we delete on in our linked list, it doesn't affect
    // the linked list that we copied from!

    // Correct solution:
    // iterate through the linked list you want to copy.
    // append each value you see to the list you're building
    // in this constructor.
}

LinkedList& LinkedList::operator=(const LinkedList &other) {
    // default behavior is the below
    head = other.head;
    tail = other.tail;

    return *this;
    // this isn't good! We should copy any of the elements
    // so that if we delete on in our linked list, it doesn't affect
    // the linked list that we copied from!

    // Correct solution:
    // Delete all our current nodes first!
    // Iterate through the linked list you want to assign.
    // Append each value you see to ourselves.
}

void LinkedList::append(int x) {
    // make a new node (on the heap)
    node *n = new node;
    n->info = x;
    n->next = nullptr;

    // add it to the end of the current linked list
    if(head == nullptr && tail == nullptr) {
        // empty list, n is the only node
        head = n;
        tail = n;
    }
    else{
        // non-empty list
        tail->next = n;
        tail = n;
    }
}

bool LinkedList::operator==(const LinkedList &other) const {
    // itterate through both lists at the same time
    // and see if the values inside each node line up
    node *n1 = head; // our head
    node *n2 = other.head; // their head

    while(n1 != nullptr && n2 != nullptr) {
        // check if their data values are the same
        if(n1->info != n2->info) return false;
        
        // keep going; advance both pointers
        n1 = n1->next;
        n2 = n2->next;

        // once we got here, at least one of n1 and n2 is equal to nullptr
        // if both are nullptr, then the lists were the same
        if(n1 == nullptr && n2 == nullptr) return true;
        else return false; //one of the lists wasn;t empty and the other was
    }
}
vector<int> LinkedList::vectorize() const {
    vector<int> ret;

    node *n = head;
    while(n != nullptr) {
        // n->info is shorthand for (*n).info
        ret.push_back(n->info);
        n = n->next;
    }
    return ret;
}

void LinkedList::print() const {
    node *n = head;
    while(n != nullptr) {
        cout << n->info << " ";
        n = n->next;
    }
    cout << endl;
}
