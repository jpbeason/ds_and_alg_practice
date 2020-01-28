//
//  linked_list.cpp
//  interview_prep
//
//  Created by Jake Beason on 8/28/19.
//  Copyright © 2019 Jake Beason. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cassert>

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
    
public:
    // default constructor
    IntList() : head(nullptr) {}
    
    // EFFECTS: returns true if the list is empty
    bool empty() const {
        return head == nullptr;
    }
    
    // REQUIRES: the list is not empty
    // EFFECTS: Returns (by reference) the first element
    int & front() {
        assert(!empty());
        return head->datum;
    }
    
    // EFFECTS: inserts datum at the front of the list
    void push_front(int datum) {
        Node *p = new Node;
        p->datum = datum;
        p->next = head;
        head = p;
    }
    
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
    }
    
    // LEFT OFF AT SLIDE 22
    
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
