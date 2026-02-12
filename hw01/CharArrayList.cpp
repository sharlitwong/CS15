/*
 *  CharArrayList.cpp
 *  Charlotte Wong
 *  January 20, 2026
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  File purpose:
 *  This file contains the implementation of the CharArrayList class.
 * 
 */

#include "CharArrayList.h"
using namespace std;

/*
 * name:      CharArrayList (default constructor)
 * purpose:   initialize an empty CharArrayList
 * arguments: none
 * returns:   none
 * effects:   numItems & capacity to 0, buffer points to nullptr
 * other:     none
 */
CharArrayList::CharArrayList() {
    numItems = 0; 
    capacity = 0; 
    buffer = nullptr;
}

/*
 * name:      CharArrayList (second constructor)
 * purpose:   initialize an new CharArrayList with one specified character
 * arguments: one character to be in the CharArrayList
 * returns:   none
 * effects:   numItems & capacity to 1, new array list created
 * other:     none
 */
CharArrayList::CharArrayList(char c) {
    buffer = new char[1]; 
    numItems = 1; 
    capacity = 1; 
    buffer[0] = c; 
}

/*
 * name:      CharArrayList (third constructor)
 * purpose:   takes array of characters & its integer length to create an array
 *            list of the characters and their order contained in that array.
 * arguments: character array and it's integer size (number of characters)
 * returns:   none
 * effects:   new char array created with same length and capacity as given
 *            array
 * other:     none
 */
CharArrayList::CharArrayList(char arr[], int size) {
    numItems = size;
    capacity = size;
    
    if (size == 0) {
        buffer = nullptr;
    } else {
        buffer = new char[size];
        for(int i = 0; i < size; i++) {
            buffer[i] = arr[i];
        }
    }
}

/*
 * name:      CharArrayList (copy constructor)
 * purpose:   creates a deep copy of the given character array list instance
 * arguments: reference of instance of a character array
 * returns:   none
 * effects:   deep copy of provided character array list created, with exactly 
 *            same attributes
 * other:     none
 */
CharArrayList::CharArrayList(const CharArrayList &other) {
    numItems = other.numItems; 
    capacity = other.capacity; 

    if(other.numItems == 0){
        buffer = nullptr;
    }else{
        buffer = new char[capacity];
        for(int i = 0; i < numItems; i++) {
            buffer[i] = other.buffer[i]; 
        }
    }
}

/*
 * name:      CharArrayList (destructor)
 * purpose:   destroy heap-allocated data in current array list
 * arguments: none
 * returns:   none
 * effects:   clears heap allocated memory
 * other:     none
 */
CharArrayList::~CharArrayList() {
    delete [] buffer; 
}

/*
 * name:      CharArrayList operator "="
 * purpose:   recycles memory of instance on the left of assignment, and 
 *            makes a deep copy of the instance on the right into the instance 
 *            on the left
 * arguments: reference to existing character array list instance
 * returns:   character array list deep copy
 * effects:   left instance becomes deep copy of right instance
 * other:     none
 */
CharArrayList &CharArrayList::operator=(const CharArrayList &other) {
    //check if deep copy is being made of oneself, so that its not deleted 
    if (this == &other) return *this;
    delete [] buffer;
    numItems = other.numItems; 
    capacity = other.capacity; 

    if (capacity == 0) {
        buffer = nullptr;
    } else {
        buffer = new char[capacity];
        for(int i = 0; i < numItems; i++) {
            buffer[i] = other.buffer[i]; 
        }
    }
    //allow chained assignments
    return *this; 
}

/*
 * name:      isEmpty
 * purpose:   determine whether an array list is empty
 * arguments: none
 * returns:   boolean true if arraylist is empty, false otherwise
 * effects:   none
 * other:     none
 */
bool CharArrayList::isEmpty() const {
    return (numItems == 0); 
}

/*
 * name:      size
 * purpose:   return number of characters in the character array list
 * arguments: none
 * returns:   integer number of characters in array list
 * effects:   number of items in array list returned
 * other:     none
 */
int CharArrayList::size() const {
    return numItems;
}

/*
 * name:      clear
 * purpose:   clear a character arraylist
 * arguments: none
 * returns:   none
 * effects:   numItems to zero
 * other:     none
 */
void CharArrayList::clear() {
    delete [] buffer;
    buffer = nullptr;
    numItems = 0; 
    capacity = 0;
}

/*
 * name:      first
 * purpose:   return first character in array list
 * arguments: none
 * returns:   character that's first in the arraylist 
 * effects:   none
 * other:     error thrown if array list is empty
 */
char CharArrayList::first() const {
    if(isEmpty()) throw runtime_error("cannot get first of empty ArrayList");
    return buffer[0];
}

/*
 * name:      last
 * purpose:   return last character in array list
 * arguments: none
 * returns:   character that's last in the arraylist
 * effects:   none
 * other:     appropriate error thrown if array list is empty
 */
char CharArrayList::last() const {
    if(isEmpty()) throw runtime_error("cannot get last of empty ArrayList");
    return buffer[numItems - 1]; 
}

/*
 * name:      elementAt
 * purpose:   return element at some given index
 * arguments: integer specifying desired index
 * returns:   character located at specified index
 * effects:   none
 * other:     error thrown if index is out of bounds (or array list is empty)
 */
char CharArrayList::elementAt(int index) const {
    string ind = to_string(index); //make integers to strings for printing
    string size = to_string(numItems); 

    //check for out of bounds index, implicit check for empty array list
    if((index > (numItems - 1)) or index < 0) {
        throw range_error("index (" + ind + ") not in range [0.." 
        + size + ")");
    }
    return buffer[index]; 
}

/*
 * name:      toString
 * purpose:   return a message containing the character array list as a string 
 *            as well as its size
 * arguments: none
 * returns:   string with a brief message with the character array list's size 
 *            and its contents
 * effects:   none
 * other:     none
 */
string CharArrayList::toString() const {
    string word = justString(); 
    string size = to_string(numItems); 

    string message = "[CharArrayList of size " + size + " <<" + word +
    ">>]";

    return message; 
}

/*
 * name:      toReverseString
 * purpose:   return a message containing the character array list with its 
 *            characters reversed as a string as well as its size
 * arguments: none
 * returns:   string with a brief message with the character array list's size 
 *            and its contents reversed
 * effects:   none
 * other:     none
 */
string CharArrayList::toReverseString() const {
    string word = justReverseString();
    string size = to_string(numItems);

    string message = "[CharArrayList of size " + size + " <<" + word +
    ">>]";

    return message; 
}

/*
 * name:      justString
 * purpose:   a private helper function to convert a character array list into 
 *            a string
 * arguments: none
 * returns:   a string containing only the characters in the character array 
 *            list in their original order
 * effects:   none on given char array list instance
 * other:     none
 */
string CharArrayList::justString() const { 
    string str = ""; 
    for(int i = 0; i < numItems; i++) { 
        str += buffer[i]; 
    }
    return str; 
}

/*
 * name:      justReverseString
 * purpose:   a private helper function to convert a character array list into a
 *            string with character order reversed
 * arguments: none
 * returns:   string containing original characters in character array list in
 *            reverse order
 * effects:   none
 * other:     none
 */
string CharArrayList::justReverseString() const { 
    string str = "";
    for(int i = numItems; i > 0; i--) { 
        str += buffer[i-1]; //append each character in reverse order
    }
    return str;
}

/*
 * name:      pushAtBack
 * purpose:   add a character to the end of an array list
 * arguments: character to be added
 * returns:   none
 * effects:   size increments by one, capacity adjusted as necessary, array list
 *            contains the new specified character at the end
 * other:     none
 */
void CharArrayList::pushAtBack(char c) {
    if(numItems == capacity) { 
        expand(); 
    }
    buffer[numItems] = c; //add the newest element at the back
    numItems++; 
}

/*
 * name:      pushAtFront
 * purpose:   add a character to the front of an array list
 * arguments: character to be added
 * returns:   none
 * effects:   size increments by one, capacity adjusted as necessary, array list
 *            contains the new specified character at the front
 * other:     none
 */
void CharArrayList::pushAtFront(char c) {
    if(numItems == capacity) { 
        expand();
    }

    shiftforward(0); //shift elements one position forward to make room at front
    buffer[0] = c; //replace first element with desired element
    numItems++; 
}

/*
 * name:      expand
 * purpose:   private helper function to increase array list capacity when its
 *            full
 * arguments: none
 * returns:   none
 * effects:   capacity to one if initially zero, otherwise doubled, old memory
 *            recycled
 * other:     none
 */
void CharArrayList::expand() {
    if(capacity == 0) {
        capacity = 1; 
    } else { 
        capacity *= 2; 
    }

    char *new_buffer = new char[capacity]; 
    for(int i = 0; i < numItems; i++) {
        new_buffer[i] = buffer[i]; 
    }

    delete []buffer; 

    buffer = new_buffer; //make buffer point to the new memory location on heap
}

/*
 * name:      shiftforward
 * purpose:   private helper function to shift every character up by one, 
 *            starting at some specified index within the character array,
 *            leaving a duplicate of the frontmost character that's shifted 
 *            remaining at its original index 
 * arguments: integer index indicative of first element to shift forward
 * returns:   none
 * effects:   all characters starting at a certain index are shifted upward
 * other:     none
 */
void CharArrayList::shiftforward(int start) { 
    for(int i = numItems; i > start; i--) {
        buffer[i] = buffer[i-1]; 
    }
}

/*
 * name:      insertAt
 * purpose:   insert a specified character at some specified index 
 * arguments: character to be inserted, and integer index to be inserted at
 * returns:   none
 * effects:   size increments by one, capacity adjusted as necessary, character
 *            array list contains new specified character at given location
 * other:     error thrown if index provided is outside bounds of array list
 */
void CharArrayList::insertAt(char c, int index) {
    string ind = to_string(index); 
    string size = to_string(numItems); 

    if(index < 0 or index > numItems) { 
        throw range_error("index (" + ind + ") not in range [0.." 
        + size + "]");
    }
    if(numItems == capacity) expand(); 

    //shift everything after and including the specified index forward
    shiftforward(index); //original character remains at its original index
    buffer[index] = c; //replace original character 
    numItems++;
}

/*
 * name:      insertInOrder
 * purpose:   assumes instance is already in ascending ASCII order, and insert 
 *            specified character in accordance with the sequence 
 * arguments: character to be inserted
 * returns:   none
 * effects:   size increments by one, capacity adjusted as necessary, array list
 *            contains one more character at location to maintain ASCII order
 * other:     none
 */
void CharArrayList::insertInOrder(char c) {
    int ind = 0; 
    // while(c >= buffer[ind] and ind < numItems) {
    while(ind < numItems && c >= buffer[ind]) {
        ind++;
    }
    insertAt(c, ind);

    // for(int i = 0; i < numItems; i++) { 
    //     //compare characters in array list to character to be inserted
    //     //if character comes later in ASCII order, increment index

    //     if(c > buffer[i]) ind++; 
    // }

}

/*
 * name:      popFromFront
 * purpose:   remove character at frontmost of the character array 
 * arguments: none
 * returns:   none
 * effects:   front character removed, size decrements by one
 * other:     throws appropriate error if the array list is already empty
 */
void CharArrayList::popFromFront() {
    if(isEmpty()) throw runtime_error("cannot pop from empty ArrayList");
    removeAt(0);
}

/*
 * name:      popFromBack
 * purpose:   remove character at the end of array list
 * arguments: none
 * returns:   none
 * effects:   back character removed, size decrements by one
 * other:     throws appropriate error if the array list is already empty
 */
void CharArrayList::popFromBack() {
    if(isEmpty()) throw runtime_error("cannot pop from empty ArrayList");
    numItems--; 
}

/*
 * name:      removeAt
 * purpose:   remove a character from array list at the specified index
 * arguments: integer index from which character is to be removed
 * returns:   none
 * effects:   character at given index removed, subsequent characters shifted 
 *            down, size decrements by one
 * other:     throws appropriate error if index is not in bounds
 */
void CharArrayList::removeAt(int index) {
    string i = to_string(index);
    string s = to_string(numItems); 

    //check if index is out of bounds (implicitly checks if array list is empty)
    if(index > (numItems - 1) or index < 0) {
        throw range_error("index (" + i + ") not in range [0.." + s + ")");
    }

    //move everything after index down by one index, overwriting character at 
    //index specified & leaving a character duplicated in last two indices
    shiftbackward(index); 
    numItems--; //prevent access to character at highest index
}

/*
 * name:      shiftbackward
 * purpose:   private helper function to shift every character down by one, 
 *            starting at some given index, leaving that given index's character
 *            overwritten 
 * arguments: integer index into which earliest backward shifted character will
 *            shift into
 * returns:   none
 * effects:   all characters starting at a certain index are shifted backward
 * other:     none
 */
void CharArrayList::shiftbackward(int start) {
    for(int i = start; i < numItems - 1; i++) {
        buffer[i] = buffer[i+1]; //move every element down by one index
    }
    //this leaves the highest element unaltered, while the one right below will
    //contain its 'copy'
}

/*
 * name:      replaceAt
 * purpose:   replace a character at a specified index with a given character
 * arguments: character to replace the original, integer index at which the 
 *            original is located
 * returns:   none
 * effects:   one character is replaced with the specified one
 * other:     throws appropriate error if index is out of bounds
 */
void CharArrayList::replaceAt(char c, int index) {
    //if index is out of bounds (implicit check of empty array list)
    if(index > numItems - 1 or index < 0) {
        string i = to_string(index); 
        string s = to_string(numItems); 
        throw range_error("index (" + i + ") not in range [0.." + s + ")");
    }
    buffer[index] = c;
}

/*
 * name:      concatenate
 * purpose:   concatenate provided character array list pointer to the end of 
 *            the one on which the method is called on
 * arguments: pointer to character array list instance
 * returns:   none
 * effects:   pointer specified instance's character array is concatenated onto
 *            one on which method is called, size & capacity are adjusted 
 *            accordingly
 * other:     none
 */
void CharArrayList::concatenate(CharArrayList *other) {
    int other_size = other -> size();
    for(int i = 0; i < other_size; i++) {
        //add each element to the end of existing one
        pushAtBack(other -> elementAt(i));
    }
}