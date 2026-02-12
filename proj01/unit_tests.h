/*
 *  unit_tests.h
 *  Charlotte Wong (cwong22)
 *  February 4, 2026
 *
 *  CS 15 Project 1 MetroSim
 *
 *  This file's purpose is to implement several independent tests that run using
 *  the "unit_test" terminal command. Testing through the unit_tests system 
 *  allows for easier pinpointing of bugs targetting specific functions with
 *  certain tests, so that failed tests immediately reveal the origin of the 
 *  errors.
 *
 */

#include <cassert>
#include <stdexcept>


using namespace std;
//#include "PassengerQueue.h"
#include "MetroSim.h" //new
#include <iostream>

/*
 * dummy
 * a dummy test that does nothing
 */
void dummy(){}

/*
 * passenger print
 */
void passenger_print(){
    Passenger p(1, 0, 1);
    p.print(cout);
}

/*
 * queue nullary
 *
 */
void queue_nullary() {
    PassengerQueue q;
}

/*
 * queue pushback
 *
 */
void queue_pushback() {
    PassengerQueue q;
    Passenger p(1, 0, 1);
    Passenger m(2, 1, 3);
    q.enqueue(p);
    q.enqueue(m);
    assert(q.size() == 2);
    q.front().print(cout);
    q.dequeue();
    q.front().print(cout);
}

/*
 * queue print
 *
 */
void queue_print() {
    PassengerQueue q;
    Passenger p(1, 0, 1);
    Passenger m(2, 1, 3);
    Passenger o(3, 2, 6);
    q.enqueue(p);
    q.enqueue(m);
    q.enqueue(o);
    q.print(cout);
}

/* Station tests */

void constr_station() {
    Station st("stop");
    assert(st.getName() == "stop");
}

void station_add() {
    Station st("name");
    Passenger p(1, 0, 1);
    Passenger m(2, 1, 3);
    Passenger o(3, 2, 6);
    st.addPassenger(p);
    st.addPassenger(m);
    st.addPassenger(o);
    st.waitingQueue().print(cout);
    assert(not st.empty());
}

// ./the_MetroSim stations.txt output.txt test_commands.txt

void sim_constr() {
    MetroSim sim("stations.txt", "output.txt");
}

void sim_trainprint() {
    MetroSim sim("stations.txt", "output.txt");
    sim.print(cout);
}

void play() {
    MetroSim sim("stations.txt", "output.txt");
    sim.run(cin);
}

