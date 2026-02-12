/*
 *  PassengerQueue.h
 *  Charlotte Wong (cwong22)
 *  February 4, 2026
 *
 *  CS 15 Project 1 MetroSim
 *
 *  This program implements a PassengerQueue class. A passenger queue object
 *  created with this class contains a list of passenger objects, and abstracts
 *  the list into a queue --meaning passengers may only be added to the back of 
 *  the queue, and added to the front. After creation, passengers may be added 
 *  to the back (enqueued) or removed from the front (dequeued) from the 
 *  passenger queue. Additionally, the passenger at the front is accessible, 
 *  along with the number of passengers in the queue. The queue's contents may
 *  also be printed, by printing each passengers' information from front to 
 *  back.
 * 
 */

#include <stdexcept>
#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H

#include "Passenger.h"
#include <list>

class PassengerQueue {
    public:
        Passenger front();
        void dequeue();
        void enqueue(const Passenger &passenger);
        int size() const;
        void print(std::ostream &output);

    private:
        std::list<Passenger> pqueue;
};

#endif
