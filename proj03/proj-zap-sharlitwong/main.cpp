/*
 *  main.cpp
 *  Charlotte Wong (cwong22)
 *  March 28th, 2026
 *
 *  CS 15 Project 3 zap
 *
 *  File purpose:
 *  Entry point for the zap program. This file processes command line
 *  arguments, validates user input, and runs typewriter. 
 *
 */
#include "HuffmanCoder.h"
#include <iostream>
using namespace std;

/*
 * name:      int main(int argc, char *argv[])
 * purpose:   validates command line arguments, then runs the encoder and 
 *            decoder with the user provided files
 * arguments: 
 * returns:   
 * effects:   
 * other:     
 */
int main(int argc, char *argv[]) {
    if (argc != 4 or (string(argv[1]) != "zap" and 
                      string(argv[1]) != "unzap")) {
        cerr << "Usage: ./zap [zap | unzap] inputFile outputFile" << endl;
        return 1;
    }

    HuffmanCoder hc;
    try {
        if (string(argv[1]) == "zap") {
            hc.encoder(argv[2], argv[3]);
        } else {
            hc.decoder(argv[2], argv[3]);
        }
    } catch (const runtime_error &e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}