#include <iostream>
#include "stringlinkedlist.h"

using namespace std;

//it's better to have size as a private variable, rather than making a function 
//to calculate size each time

StringLinkedList::StringLinkedList() {
    front = nullptr;
}

//private helper function
StringLinkedList::Node *StringLinkedList::newNode(string newData, Node *next) {
    Node *node = new Node;
    node -> data = newData;
    node -> next = next;
    return node;
}

void StringLinkedList::addAtFront(string elem) {
    //Node *newFront = newNode(elem, front);
    front = newNode(elem, front);
}

//prints list using a loop
void StringLinkedList::printLoopily() {
    //while node's next is not nullptr
    //print current node
    //go to next node
    //print last node

    //while curr not equal to nullptr
    //start curr at front
    //go to next linked node

    //curr = front;
    //while(curr != nullptr){
    //  curr = curr -> next;
    //{

    for(Node *curr = front; curr != nullptr; curr = curr->next) {
        //this compiles into a while loop
        cout << curr -> data << " ";
    }
    cout << "\n";
}

//prints everything starting from curr
void StringLinkedList::printRecHelper(Node *curr){
    //needs an argument, so that something can change each call
    if(curr == nullptr) { //base case
        cout << "\n";
    } else { //recursive case
        cout << curr -> data << " ";
        printRecHelper(curr -> next);
    }
}

//recycles each node in the list beginning at curr
//helper function for the destructor!
//recursive helper function
void StringLinkedList::recycleRecursive(Node *curr) {
    if(curr == nullptr) {
        return;
    } else {
        //want backward order, so make recursive call first, and THEN take action (deleting in this case)
        //we'd do the same thing for reverse string in HW!!
        recycleRecursive(curr -> next);
        delete curr;
    }
}

void StringLinkedList::removeAtBack(){
    //assume back pointer is a thing
    //while curr -> next != nullptr, temp = temp -> next
    //delete temp

    //keep track of size
    //iterate to last, delete it
    //iterate to previous second to last, make its next point to nullptr


}

void StringLinkedList::insertAt(string elem){
    front = insertAtRecHelper(front, index, elem);
}

StringLinkedList::Node *StringLinkedList::insertAtRecHelper(Node *curr, 
                                            int index, std::string elem) {
    if(index == 0) return newNode(elem, curr);
    else { //reconstructing our list
        curr -> next = return insertAtRecHelper(curr -> next, index - 1, elem);
        return curr;
    }                
}
