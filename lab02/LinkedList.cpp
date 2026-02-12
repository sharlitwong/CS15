/*
 * LinkedList.cpp
 *
 * CS 15 Lab 02
 * by Tyler Calabrese, January 2020
 * Edited by Matt Russell, Juliana Vega, and Alexis Blair, Jan 2021
 *
 * An implementation of the LinkedList interface, the LinkedList can be used
 * to store Planets.
 * 
 * Edited by: Charlotte Wong (cwong22)
 * Date: Jan 27, 2026
 *
 * NOTE: This is implemented using a singly-linked list with no back pointer.
 * 
 * Implementation
 */

#include "LinkedList.h"
#include <sstream>
#include <string>

/* Default constructor
 *    Purpose: Initializes an empty LinkedList 
 * Parameters: None
 *    Returns: None
 */
LinkedList::LinkedList() {
    front = nullptr;
    size  = 0;
}

/* toString
 *    Purpose: Report the state of the list as a string
 * Parameters: None
 *    Returns: A string with the state of the list
 */
std::string LinkedList::toString() const {
    std::stringstream ss;
    ss << "LinkedList of size " << this->size << "\n";
    ss << "---------------------\n";

    Node *curr = this->front;
    while (curr != nullptr) {
        ss << curr->toString() << "\n";
        curr = curr->next;
    }

    return ss.str();
}


/* ******************************************
 * TODO: implement the LinkedList destructor
 * ******************************************
 * Destructor
 *    Purpose: Free heap-allocated memory of 'this' LinkedList
 * Parameters: None
 *    Returns: None
 */
LinkedList::~LinkedList() {
    /* write code here! */

}


/* ******************************************
 * TODO: implement the pushAtFront function
 * ******************************************
 * pushAtFront
 *    Purpose: Adds a Planet to the front of the list
 * Parameters: The Planet to be added to the list
 *    Returns: None
 */
void LinkedList::pushAtFront(Planet p) {
    /* write code here! */
    Node *node = new Node(); //allocate new memory on heap and get pointer to it
    node -> info = p; //set node's info (aka planet) to be provided planet
    node -> next = front; //set node's next pointer to be original front
    front = node; //make front pointer point to the new front
    size++; //increment size
}

/*
 * ******************************************
 * TODO: implement the pushAtBack function
 * ******************************************
 * pushAtBack
 *    Purpose: Adds a Planet to the back of the list
 * Parameters: The Planet to be added to the list
 *    Returns: None
 */
void LinkedList::pushAtBack(Planet p) {
    if(size == 0) pushAtFront(p);
    /* write code here! */
    else{
        Node *node = new Node();
        node -> info = p;
        node -> next = nullptr;

        //temporarily indicates the furthest node we've found so far
        Node *temp = front; 
        //next pointing at nullptr is equivalent to being the last node

        while(temp -> next != nullptr){ 
            temp = temp -> next;
        }
        temp -> next = node;
        size++;
    }
}


/* ****************************************
 * TODO (Bonus JFFE): implement the reverse function
 * ****************************************
 * reverse
 *    Purpose: Reverses the list
 * Parameters: None
 *    Returns: None
 */
void LinkedList::reverse() {
    /* write code here! */
}
