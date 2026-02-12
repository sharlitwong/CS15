/*
 *  Passenger.cpp
 *  Charlotte Wong (cwong22)
 *  February 4th, 2026
 *
 *  CS 15 Project 1 MetroSim
 *
 *  File purpose:
 *  This file contains the implementation of the Passenger Class
 *
 */

#include "Passenger.h"

#include <iostream>
#include <string>

/*
 * name:      Passenger( )
 * purpose:   This is the constructor for Passenger that initializes
 *            a Passenger object with an ID, starting station, and 
 *            ending station.
 * arguments: An integer passenger ID, an integer starting station,
 *            and an integer ending station. 
 * returns:   none
 * effects:   Constructs a Passenger with the provided information.
 * note:      Students do not have to modify this function.
 */
Passenger::Passenger(int id, int startingStation, int endingStation) {
    this->id = id;
    this->startingStation = startingStation;
    this->endingStation = endingStation;
}

/*
 * name:      getId( )
 * purpose:   This is the getter (aka accessor) function that provides
 *            access to the Passenger's ID. 
 * arguments: none
 * returns:   The Passenger's ID. 
 * effects:   none
 * note:      Students do not have to modify this function.
 */
int Passenger::getId() { return id; }

/*
 * name:      getStartingStation( )
 * purpose:   This is the getter (aka accessor) function that provides
 *            access to the Passenger's starting station. 
 * arguments: none
 * returns:   The Passenger's starting station. 
 * effects:   none
 * note:      Students do not have to modify this function.
 */
int Passenger::getStartingStation() { return startingStation; }

/*
 * name:      getEndingStation( )
 * purpose:   This is the getter (aka accessor) function that provides
 *            access to the Passenger's ending station. 
 * arguments: none
 * returns:   The Passenger's ending station. 
 * effects:   none
 * note:      Students do not have to modify this function.
 */
int Passenger::getEndingStation() { return endingStation; }

/*
 * name:      print(std::ostream &output)
 * purpose:   print passenger information as [PASSENGER_ID, ARRIVAL->DEPARTURE]
 * arguments: output stream reference
 * returns:   none
 * effects:   none
 * other:     none
 */
void Passenger::print(std::ostream &output) {
    output << "[" << getId() << ", " << getStartingStation() 
            << "->" << getEndingStation() << "]";
}
