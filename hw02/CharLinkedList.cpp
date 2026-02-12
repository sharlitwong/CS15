/*
 *  CharLinkedList.cpp
 *  Charlotte Wong (cwong22)
 *  January 28, 2026
 *
 *  CS 15 HW 2 Cheshire ConCATenation
 *
 *  File purpose:
 *  This file contains the implementation of the CharLinkedList class.
 *
 */

#include "CharLinkedList.h"
#include <iostream>
using namespace std;

/*
 * name:      CharLinkedList (constructor 1)
 * purpose:   initialize an new empty character linked list
 * arguments: none
 * returns:   none
 * effects:   numItems to zero, front and back pointers point to null
 * other:     none
 */
CharLinkedList::CharLinkedList(){
    front = nullptr;
    back = nullptr;
    numItems = 0;
}

/*
 * name:      CharLinkedList (constructor 2)
 * purpose:   create a new character linked list with one only character
 * arguments: one character to be in the linked list
 * returns:   none
 * effects:   numItems to one, front and back pointer point to only existing 
 *            node
 * other:     none
 */
CharLinkedList::CharLinkedList(char c) {
    front = newNode(c, nullptr, nullptr);
    back = front;
    numItems = 1;
}

/*
 * name:      CharLinkedList (constructor 3)
 * purpose:   create character linked list with same characters and order as 
 *            provided array
 * arguments: character array containing characters to be included in linked 
 *            list, and integer size of array
 * returns:   none
 * effects:   numItems to number of characters in array, all pointers updated as
 *            necessary
 * other:     none
 */
CharLinkedList::CharLinkedList(char arr[], int size) {
    front = nullptr;
    back = nullptr;
    numItems = 0;
    for (int i = 0; i < size; i++) {
        pushAtBack(arr[i]);
    }
}

/*
 * name:      CharLinkedList (copy constructor)
 * purpose:   create a deep copy of the provided reference to an existing 
 *            character linked list 
 * arguments: reference to an existing character linked list
 * returns:   none
 * effects:   new character linked list created as a deep copy of provided one
 * other:     none
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) { 
    front = nullptr;
    back= nullptr;
    numItems = 0;
    for (int i = 0; i < other.numItems; i++) pushAtBack(other.elementAt(i));

}

/*
 * name:      ~CharLinkedList (destructor)
 * purpose:   recycle all memory associated with the linked list
 * arguments: none
 * returns:   none
 * effects:   all heap allocated memory is recycled
 * other:     none
 */
CharLinkedList::~CharLinkedList() {
    recycleRecursive(front);
}

/*
 * name:      recycleRecursive
 * purpose:   recycle all memory associated with some linked list, after some 
 *            given node
 * arguments: Node at which to begin recycling
 * returns:   none
 * effects:   recycle memory associated with linked list that comes after the
 *            provided Node
 * other:     none
 */
void CharLinkedList::recycleRecursive(Node *curr) {
    if (curr == nullptr) {
        return;
    } else {
        recycleRecursive(curr -> next);
        delete curr;
        numItems--;
    }
}

/*
 * name:      CharLinkedList assignment operator "="
 * purpose:   deletes memory associated with instance on the left, and creates a
 *            deep copy of instance on the right
 * arguments: reference of some instance of an existing character array list
 * returns:   instance that gets copied into
 * effects:   current instance's member variables become same as provided 
 *            instance on right hand side
 * other:     none
 */
CharLinkedList &CharLinkedList::operator=(const CharLinkedList &other) {
    if (this == &other) return *this;

    clear();
    for (int i = 0; i < other.numItems; i++) pushAtBack(other.elementAt(i));
    return *this;
}


/*
 * name:      newNode (private helper function)
 * purpose:   create a new node
 * arguments: character that the new Node will contain, Node pointers to the 
 *            Nodes that come immediately before and after the new one
 * returns:   pointer to newly created Node 
 * effects:   a new node is created
 * other:     none
 */
CharLinkedList::Node *CharLinkedList::newNode(char c, Node *prev, Node *next) {
    Node *node = new Node;
    node -> info = c;
    node -> next = next;
    node -> prev = prev;
    return node;
}

/*
 * name:      isEmpty
 * purpose:   determine whether or not a linked list is empty
 * arguments: none
 * returns:   boolean, true if list is empty, false otherwise
 * effects:   none
 * other:     none
 */
bool CharLinkedList::isEmpty() const {
    return (numItems == 0);
}

/*
 * name:      clear
 * purpose:   clear a linked list, reducing it to contain no elements
 * arguments: none
 * returns:   none
 * effects:   clears some linked list instance
 * other:     none
 */
void CharLinkedList::clear(){
    recycleRecursive(front);
    front = nullptr;
    back = nullptr;
}

/*
 * name:      size
 * purpose:   return the size (number of characters)
 * arguments: none
 * returns:   integer size of given linked list
 * effects:   none
 * other:     none
 */
int CharLinkedList::size() const {
    return numItems;
}

/*
 * name:      first
 * purpose:   return the first character in the linked list
 * arguments: none
 * returns:   character at the front of the linked list
 * effects:   none
 * other:     throw a runtime error if the list is empty
 */
char CharLinkedList::first() const {
    if (isEmpty()){ 
        throw runtime_error("cannot get first of empty LinkedList");
    }
    return front -> info;
}

/*
 * name:      last
 * purpose:   return the last character in the linked list
 * arguments: none
 * returns:   character at the back of the linked list
 * effects:   none
 * other:     throw a runtime error if the list is empty
 */
char CharLinkedList::last() const {
    if (isEmpty()){ 
        throw runtime_error("cannot get last of empty LinkedList");
    }
    return back -> info;
}

/*
 * name:      elementAt
 * purpose:   return the character located at some given index
 * arguments: integer indicating the index at which to return a character from
 * returns:   element located at the the provided index
 * effects:   none
 * other:     throw a range error if the index provided is out of bounds
 */
char CharLinkedList::elementAt(int index) const {
    Node *curr = front;
    return findElement(index, curr) -> info;
}

/*
 * name:      findElement (private recursive helper)
 * purpose:   return a pointer to a Node located at a certain number of indices
 *            away from a given Node pointer
 * arguments: integer index difference from which the desired node is located 
 *            relative to Node pointer provided, Node pointer for aforementioned
 *            purposes
 * returns:   Node pointer to Node of interest
 * effects:   none
 * other:     throw a runtime error if the linked list is empty or index 
 *            provided is out of bounds
 */
CharLinkedList::Node *CharLinkedList::findElement(int index, Node *curr) const {
    if (isEmpty() or index < 0 or index > numItems - 1) {
        throw range_error("index (" + to_string(index) + 
                            ") not in range [0.." + to_string(numItems) + ")");
    }
    if (index == 0) return curr;
    else return findElement(index - 1, curr -> next);
}

/*
 * name:      toString
 * purpose:   sythesize and return a message containing linked list's size and 
 *            contents
 * arguments: none
 * returns:   string message containing linked list's size and contents
 * effects:   none
 * other:     none
 */
string CharLinkedList::toString() const {
    string str = "";
    getStr(front, &str);
    string size = to_string(numItems);
    string message = "[CharLinkedList of size " + size + " <<" + str + ">>]";
    return message;
}

/*
 * name:      getStr (private helper function)
 * purpose:   addend linked list contents in their given order to a string, 
 *            starting at some given character/element
 * arguments: Node at which to begin constructing the string, and string pointer
 *            to be addended to
 * returns:   none
 * effects:   none
 * other:     none
 */
void CharLinkedList::getStr(Node *start, string *str_p) const {
    if (start == nullptr) {
        *str_p += "";
    } else {
        *str_p += (start -> info);
        getStr(start -> next, str_p);
    }
}

/*
 * name:      toReverseString
 * purpose:   synthesize and return a message containing linked list's size and
 *            contents in reversed order
 * arguments: none
 * returns:   string message containing linked list's size and contents in 
 *            reversed order
 * effects:   none
 * other:     none
 */
string CharLinkedList::toReverseString() const {
    string str = "";
    getRevStr(back, &str);
    string size = to_string(numItems);
    string message = "[CharLinkedList of size " + size + " <<" + str + ">>]";
    return message;
}

/*
 * name:      getRevStr
 * purpose:   addend characters from a linked list to a string in reverse order,
 *            starting from some given character
 * arguments: Node pointer to the Node containing character to start addending
 *            at, pointer to a string to be addended to
 * returns:   none
 * effects:   none
 * other:     none
 */
void CharLinkedList::getRevStr(Node *start, string *str_p) const {
    if (start == nullptr) { 
        *str_p += "";
    } else {
        *str_p += (start -> info);
        getRevStr(start -> prev, str_p);
    }
}

/*
 * name:      pushAtBack
 * purpose:   push a new character to the back of a linked list
 * arguments: character to be pushed to the back
 * returns:   none
 * effects:   new character pushed to the back, numItems accordingly 
 *            incremented, pointers for last two nodes adjusted
 * other:     none
 */
void CharLinkedList::pushAtBack(char c){
    Node *node = newNode(c, nullptr, nullptr);
    if (isEmpty()) {
        front = node;
        back = node;
    } else {
        node -> prev = back;
        back -> next = node;
        back = node;
    }
    numItems++;
}

/*
 * name:      pushAtFront
 * purpose:   push a new character to the front of a linked list
 * arguments: character to be pushed to the back
 * returns:   none
 * effects:   new character pushed to the front, numItems accordingly
 *            incremented, pointers for first two nodes adjusted
 * other:     none
 */
void CharLinkedList::pushAtFront(char c) {
    Node *node = newNode(c, nullptr, front);
    if (isEmpty()) {
        front = node;
        back = node;
    } else {
        front -> prev = node;
        front = node;
    }
    numItems++;
}

/*
 * name:      insertAt
 * purpose:   insert a new character into a given index in a linked list
 * arguments: character to be inserted, and index to insert at
 * returns:   none
 * effects:   new character's node inserted at desired index, pointers in
 *            surrounding nodes adjusted; front/back pointers adjusted if
 *            necessary
 * other:     throws range error if provided index is out of possible bounds
 *            to insert a character
 */
void CharLinkedList::insertAt(char c, int index) {
    if (index < 0 or index > numItems) {
        throw range_error("index (" + to_string(index) + 
                         ") not in range [0.." + to_string(numItems) + "]");
    }
    
    if (index == 0) {
        pushAtFront(c);
    } else if (index == numItems) {
        pushAtBack(c);
    } else {
        Node *after = front;
        for (int i = 0; i < index; i++) after = after->next;
        Node *node = newNode(c, after->prev, after);
        after->prev->next = node;
        after->prev = node;
        numItems++;
    }
}

/*
 * name:      insertInOrder
 * purpose:   insert a new character into a given index in a linked list
 * arguments: character to be inserted, and index to insert at
 * returns:   none
 * effects:   new character's node inserted at desired index, pointers in
 *            surrounding nodes adjusted
 * other:     throws range error if provided index is out of possible bounds
 *            to insert a character
 */
void CharLinkedList::insertInOrder(char c) {
    Node *node = front;
    int ind = 0; 
    while (ind < numItems and c >= node -> info) {
        ind++;
        node = node -> next;
    }
    insertAt(c, ind);
}

/*
 * name:      popFromFront
 * purpose:   remove the frontmost character from a linked list
 * arguments: none
 * returns:   none
 * effects:   front most character's node is removed, surrounding nodes' 
 *            pointers adjusted accordingly, and front pointer points to new 
 *            front
 * other:     throws runtime error if list is already empty
 */
void CharLinkedList::popFromFront() {
    if (isEmpty()) {
        throw runtime_error("cannot pop from empty LinkedList");
    }
    Node *temp = front;
    front = front -> next;
    if (front == nullptr) back = nullptr;
    else front -> prev = nullptr;
    delete temp;
    numItems--;
}

/*
 * name:      popFromBack
 * purpose:   remove the backmost character from a linked list
 * arguments: none
 * returns:   none
 * effects:   back most character's node is removed, surrounding nodes' 
 *            pointers adjusted accordingly, and back pointer points to new back
 * other:     throws runtime error if list is already empty
 */
void CharLinkedList::popFromBack() {
    if (isEmpty()) {
        throw runtime_error("cannot pop from empty LinkedList");
    }
    Node *temp = back;
    back = back -> prev;
    if (back == nullptr) front = nullptr;
    else back -> next = nullptr;
    delete temp;
    numItems--;
}

/*
 * name:      removeAt
 * purpose:   remove character whose node is located at provided index
 * arguments: index at which node to be removed is located
 * returns:   none
 * effects:   indicated character's node is removed, surrounding nodes' pointers
 *            adjusted accordingly, front/back pointers adjusted if necessary
 * other:     throws runtime error if list is already empty
 */
void CharLinkedList::removeAt(int index) {
    Node *node = findElement(index, front);
    if (index == 0) popFromFront();
    else if (index == numItems - 1) popFromBack();
    else {
        Node *before = node -> prev;
        Node *after = node -> next;
        before -> next = after;
        after -> prev = before;
        delete node;
        numItems--;
    }   
}

/*
 * name:      replaceAt
 * purpose:   replace character at given index with a new one
 * arguments: character to replace an old one, index at which replacement should
 *            occur
 * returns:   none
 * effects:   character at provided index is replaced with provided one
 * other:     throws range error error if provided index is not within bounds of
 *            existing linked list
 */
void CharLinkedList::replaceAt(char c, int index) {
    Node *node = findElement(index, front);
    node -> info = c;
}

/*
 * name:      concatenate
 * purpose:   concatenate linked list pointed to by provided pointer with 
 *            an existing instance of a character linked list
 * arguments: pointer to linked list to be concatenated to the existing one
 * returns:   none
 * effects:   numItems adjusted to sum of size of two linked lists, pointers at 
 *            concatenation junction adjusted accordingly
 * other:     none
 */
void CharLinkedList::concatenate(CharLinkedList *other) {
    if (other -> isEmpty()) return;
    Node *curr = other -> front;
    int other_size = other -> numItems;
    for (int i = 0; i < other_size; i++) {
        pushAtBack(curr -> info);
        curr = curr -> next;
    }
}