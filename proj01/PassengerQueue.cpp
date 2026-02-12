/*
 *  PassengerQueue.cpp
 *  Charlotte Wong (cwong22)
 *  February 4, 2026
 *
 *  CS 15 Project 1 MetroSim
 *
 *  File purpose:
 *  This file contains the implementation of the PassengerQueue Class
 *
 */
#include "PassengerQueue.h"

#include <iostream>
#include <string>

using namespace std;

/*
 * name:      front()
 * purpose:   provides the passenger at the front of the queue
 * arguments: non
 * returns:   none
 * effects:   pointer to the passenger at the front of the queue
 * other:     none
 */
Passenger PassengerQueue::front() {return pqueue.front();}

/*
 * name:      enqueue
 * purpose:   pushes a passenger to the back end of the queue
 * arguments: reference to a passenger instance
 * returns:   none
 * effects:   list size incremented by additional passenger
 * other:     none
 */
void PassengerQueue::enqueue(const Passenger &passenger) {
    pqueue.push_back(passenger);
}

/*
 * name:      dequeue
 * purpose:   removes character from the from the front of the queue
 * arguments: none
 * returns:   none
 * effects:   list size decremented by removal of frontmost passenger
 * other:     none
 */
void PassengerQueue::dequeue() {
    pqueue.pop_front();
}

/*
 * name:      size()
 * purpose:   returns the size (number of passengers) in a queue
 * arguments: none
 * returns:   size (number of passengers) in the queue
 * effects:   none
 * other:     none
 */
int PassengerQueue::size() const {
    return pqueue.size();
}

/*
 * name:      print()
 * purpose:   prints the queue by printing the information of each passenger
 * arguments: output stream reference
 * returns:   none
 * effects:   none
 * other:     none
 */
void PassengerQueue::print(ostream &output) {
    for (list<Passenger>::iterator i=pqueue.begin(); i != pqueue.end(); ++i) {
        i -> print(output);
    }    
}