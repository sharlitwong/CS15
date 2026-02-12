#include <iostream>
#include "IntArrayList.h"

using namespace std;

/*
 * IntArrayList:
 * Purpose: constructor
 */
IntArrayList::IntArrayList(){
    data = nullptr; //better to be explicit, than assume this'll happen
    currSize = 0;
    capacity = 0;

}

/*
 * Makes a list with initialSize repeated ints of value
 */
IntArrayList::IntArrayList(int initalSize, int value){
    capacity = 2*initialSize; //do this in hw too!
    data = new int[capacity];
    currSize = initialSize;

    for(int i = 0; i < initialSize; i++){
        data[i] = value;
    }
}

/*
 * Destructor: delete array
 */
IntArrayList::~IntArrayList(){
    delete [] data;
}

/*
 * style: capitalize class name, lowercase variable/method names
*/
int IntArrayList::size(){
    return currSize;
}

bool IntArrayList::isEmpty(){
    return (currSize == 0);
}

void IntArrayList::addAtBack(int elem){
    if(currSize == capacity){
        expand();
    }
    
    data[currSize] = elem;
    currSize++;
}

void IntArrayList expand(){
    //create a new array
    int new_capacity = capacity*2 + 2; //so that initial expansions aren't condensed
    int *new_data = new int[new capacity];

    //copy over data from old array
    for(int i = 0; i < currSize; i++){
        new_data[i] = data[i]; //copy everything over
    }

    //Recycle old array 
    delete [] data; //deletes heap memory 

    //change where data points and update data members
    data = new_data; //make new_data point at data?
    capacity = new_capacity;
}