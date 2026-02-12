/*
 *  Station.cpp
 *  Charlotte Wong (cwong22)
 *  February 4th, 2026
 *
 *  CS 15 Project 1 MetroSim
 *
 *  File purpose:
 *  This file contains the implementation of the Station Class
 *
 */

#include "Station.h"
using namespace std;

/*
 * name:      Station (constructor)
 * purpose:   creates a station with the given name
 * arguments: string indicating the name of the station
 * returns:   none
 * effects:   new station created with no passengers waiting yet
 * other:     none
 */
Station::Station(string name) {
    this -> name = name;
}

/*
 * name:      getName()
 * purpose:   returns the name of a station
 * arguments: string indicating the name of the station
 * returns:   none
 * effects:   new station created with no passengers waiting yet
 * other:     none
 */
string Station::getName() const {
    return name;
}

/*
 * name:      addPassenger()
 * purpose:   adds a passenger to the back of the queue of passengers waiting at
 *            the station
 * arguments: reference to an existing passenger
 * returns:   none
 * effects:   queue of the station has the specified passenger at the back 
 * other:     none
 */
void Station::addPassenger(const Passenger &passenger) {
    waiting.enqueue(passenger);
}

/*
 * name:      empty()
 * purpose:   returns whether a station has passengers waiting to be picked up
 *            or not
 * arguments: none
 * returns:   none
 * effects:   none 
 * other:     none
 */
bool Station::empty() const {
    return (waiting.size() == 0);
}

PassengerQueue &Station::waitingQueue() {
    return waiting;
}