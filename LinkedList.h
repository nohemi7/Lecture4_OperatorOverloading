// Author: Nohemi Morales (from Lectures by Nicolas L.)
// Date: 23.07.21
// Header files include only declarations, no function imlpementation

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>

class LinkedList 
{
public:
    LinkedList(); // constructor
    LinkedList(const LinkedList &other); // copy constructor

    void append(int x); // adds a new node to the list with info=x
    void print() const; // prints the list
    std::vector<int> vectorize() const; // turns the list into a vector

    LinkedList &operator=(const LinkedList &other); // copy assignment

    bool operator==(const LinkedList &other) const; // compare for value equality
    
private:
    // definition of node
    struct node
    {
        int info;
        node *next; // points to the next node in the linked list
            // will return NULL if tail
    };
    
    node *head; // pointer to first node
    node *tail; // pointer to last node
};

#endif