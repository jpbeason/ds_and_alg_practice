//
//  remove_dups.cpp
//  interview_prep
//
//  Created by Jake Beason on 8/28/19.
//  Copyright © 2019 Jake Beason. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cassert>
#include <sstream>

/*
 CTCI, p. 94, Interview Question 2.1
 "Remove Dups: Write code to remove duplicates from an unsorted linked list.
 
FOLLOW UP QUESTION
 "How would you solve this problem if a temporary buffer is not allowed?"
 
 */

using namespace std;

struct Node {
    int data;
    Node* next;
};
// struct Node {}


class IntList {

    struct Node {
        int datum;
        Node* next;
    }; // struct Node {}
    
    // sometimes referred to as "first"
    Node* head;
    Node* tail;
    
public:
    // default constructor
    IntList() : head(nullptr), tail(nullptr) {}
    
    
    // BIG 3 IMPL: Copy Constructor
    IntList(const IntList &other) : head(nullptr), tail(nullptr) {
        push_all(other);
    }// IntList(const IntList &other)
    
    // BIG 3 IMPL: Overloaded Assignement operator
    IntList & operator=(const IntList &rhs) {
        if (this == &rhs) return *this;
        pop_all();
        push_all(rhs);
        return *this;
    }// IntList operator =
    
    // BIG 3 IMPL: Decstructor
    ~IntList() {
        pop_all();
    }// destructor
    
    
    // EFFECTS: returns true if the list is empty
    bool empty() const {
        return head == nullptr;
    }// empty()
    
    
    // REQUIRES: the list is not empty
    // EFFECTS: Returns (by reference) the first element
    int & front() {
        assert(!empty());
        return head->datum;
    }// int & front()
    
    
    // EFFECTS: inserts datum at the front of the list
    void push_front(int datum) {
        Node *p = new Node;
        p->datum = datum;
        p->next = head;
        head = p;
    }// push_front()
    
    
    // EFFECTS: inserts datum at the back of the list
    void push_back(int datum) {
        Node *p = new Node;
        p->datum = datum;
        p->next = nullptr;
        
        // if list is empty, list only one element long
        if (empty()) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }// if()
        
    }// void push_back()
    
    
    // REQUIRES: the list is not empty
    // EFFECTS; removes the first element
    void pop_front() {
        assert(!empty());
        
        // EXPLANATION:
        // use a temp var to keep track of the Node to be destroyed
        // => now we can safely change it first
        Node *victim = head;
        head = head->next;
        delete victim;
    }// void pop_front()
    
    
    // TRAVERSING A LINKED LIST
    void print(ostream &os) const {
        for (Node *np = head; np; np = np->next) {
            os << np->datum << " ";
        }
    }// void print()
    
    
    //------------------------------
    //        BIG 3 HELPERS
    //------------------------------
    
    
    // EFFECTS: removes all ndoes from the list
    void pop_all() {
        while (!empty()) {
            pop_front();
        } // while()
        
    }// void pop_all()
    
    
    // EFFECTS: copies all nodes from the other list to this list
    void push_all(const IntList &other) {
        
        // iterate thru all nodes
        for (Node *np = other.head; np; np = np->next) {\
            
            // TO AVOID A BACKWORDS COPY, WE COULD USE PUSH_BACK
            // push_back(np->datum);
            push_front(np->datum);
        }
    }// void push_all()
    
};
// class IntList {}


//----------------------------------
//          DRIVER IMPL
//----------------------------------

int main() {
    
    // FOR TESTING PURPOSES
    
    IntList list;           // ()
    list.push_front(1);     // (1)
    list.push_front(2);     // (2, 1)
    list.push_front(3);     // (3, 2, 1)
    
    cout << list.front();   // 3
    
    list.front() = 4; // (4, 2, 1)
    
    list.pop_front(); // (2, 1)
    list.pop_front(); // (1)
    list.pop_front(); // ()
    
    cout << list.empty(); // true (or 1)
    
    return 0;
}
