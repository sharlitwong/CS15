/*
 *
 */

#include "MetroSim.h"

using namespace std;

MetroSim::MetroSim(string stationsFile, string outFile){
    currStation = 0;
    nextID = 1;
    readStations(stationsFile);
    open_or_die(outputFile, outFile);
}

MetroSim::~MetroSim() {
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

void MetroSim::readStations(string stationsFile) {
    ifstream infile;
    open_or_die(infile, stationsFile);
    string stationName;
    while(getline(infile, stationName)) {
        stations.push_back(Station(stationName));
        train.push_back(PassengerQueue());
    }
    infile.close();
}

template<typename streamtype>
void MetroSim::open_or_die(streamtype &stream, string fileName) {
    stream.open(fileName);
    if(not stream.is_open()) {
        cerr << "Error: could not open file " << fileName << endl; //endl??
        exit(EXIT_FAILURE);
    }
}

void MetroSim::print(ostream &output) {
    output << "Passengers on the train: {";
    for(int i = 0; i < stations.size(); i++) { //iterate through train
        train[i].print(output);
    }
    output << "}" << endl;
    
    string pre = "";

    for(int i = 0; i < stations.size(); i++) {
        if (currStation == i) {
            pre = "TRAIN: ";
        } else {
            pre = "       ";
        }
        output << pre << "[" << i << "] " << stations[i].getName() << " {";
        stations[i].waitingQueue().print(output);
        output << "}" << endl;
    }
}

void MetroSim::run(istream &input) {
    print(cout);
    string command;
    bool play = true;
    cout << "Command? ";
    while(play and input >> command) {
        if (command == "m") {
            string sub;
            input >> sub;
            if (sub == "f") play = false;
            else if (sub == "m") {
                metroMove();
                print(cout);
            }
        } else if (command == "p") {
            int arr, dep;
            input >> arr >> dep;
            stations[arr].addPassenger(Passenger(nextID, arr, dep));
            nextID++;        
            print(cout);
        }
        cout << "Command? ";
    }
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
}

void MetroSim::metroMove() {
    while(not (stations[currStation].empty())) {
        Passenger board = stations[currStation].waitingQueue().front();
        train[board.getEndingStation()].enqueue(board);
        stations[currStation].waitingQueue().dequeue();
    }
    currStation = (currStation + 1) % stations.size();
    while(not (train[currStation].size() == 0)) {
        outputFile << "Passenger " << train[currStation].front().getId() 
        << " left train at station " << stations[currStation].getName() << endl;
        train[currStation].dequeue();
    }
}