/*
 *  Passenger.h
 *  Charlotte Wong (cwong22)
 *  February 9, 2026
 *
 *  CS 15 Project 1 MetroSim
 *
 *  The purpose of this file is to implement the MetroSim class. 
 * 
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Station.h"
#include <vector>
#include <fstream>
// Put any other necessary includes here

class MetroSim
{

public:
    MetroSim(std::string stationsFile, std::string outputFile);
    ~MetroSim();

    //idk if public or private
    void print(std::ostream &output);
    void run(std::istream &input);
    void metroMove();


private:
    void readStations(std::string stationsFile);

    template<typename streamtype>
    void open_or_die(streamtype &stream, std::string fileName);

    // Put any other structs you need here
    std::vector<Station> stations;
    std::vector<PassengerQueue> train;

    std::ofstream outputFile;
    
    int currStation;
    int nextID;
};

#endif
