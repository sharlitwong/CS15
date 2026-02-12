/*
 *  Passenger.h
 *  Charlotte Wong (cwong22)
 *  February 4, 2026
 *
 *  CS 15 Project 1 MetroSim
 *
 *  The purpose of this file is to implement a Passenger class. A passenger 
 *  object created using this class has an ID number, and station numbers 
 *  indicating the passenger's arrival and departure stations. After creation,
 *  passengers' ID numbers, starting and ending station numbers can be accessed
 *  but not changed. The passengers' information can be printed in the format
 *  of [PASSENGER_ID, ARRIVAL->DEPARTURE]. 
 * 
 */

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

class Passenger {
   public:
    Passenger(int id, int startingStation, int endingStation);
    int getId();
    int getStartingStation();
    int getEndingStation();
    void print(std::ostream &output);

   private:
    int id;
    int startingStation;
    int endingStation;
};

#endif

