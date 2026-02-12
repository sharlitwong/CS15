/*
 *  Station.h
 *  Charlotte Wong (cwong22)
 *  February 4, 2026
 *
 *  CS 15 Project 1 MetroSim
 *
 *  This program implements a Station class. A station object created with this
 *  class has both a name, and a passenger queue of passengers waiting to board
 *  a train. After ceation, the class permits more passengers to be added to the
 *  queue of waiting passengers, checking if this station is empty, getting the
 *  station name, and getting the passenger who first arrived at the station.
 * 
 */

#ifndef STATION_H
#define STATION_H

#include "PassengerQueue.h"

class Station {
    public:
        Station(std::string name);
        std::string getName() const;
        void addPassenger(const Passenger &passenger);
        bool empty() const;
        PassengerQueue &waitingQueue();
    private:
        std::string name;
        PassengerQueue waiting;
};

#endif