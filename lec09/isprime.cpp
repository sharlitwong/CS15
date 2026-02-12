/*
 * Simple program which checks if given numbers are prime.
 *
 * Meant to demonstrate a modular program which can read from/write to
 * cin and cout, or a given input file and output file.
 *
 * Usage: ./isprime [input_file output_file]
 *
 * If no arguments given, reads from cin and writes to cout,
 * otherwise reads from input_file and writes to output_file.
 *
 * Continues reading inputs and writing outputs until it reads
 * a negative number.
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void abort(string error_message);

template<typename streamtype>
void open_or_die(streamtype &stream, string file_name);

void run_primes_loop(istream &input, ostream &output);
bool isPrime(int num);


/* `argc` is the number of command line arguments given.
 * It counts the name of the program itself, so it is always at least 1.
 * 
 * `argv` is the array of command line arguments as strings
 * (remember: in C++, strings are actually arrays of characters).
 * argv[0] is always the name of the program.
 */
int main(int argc, char *argv[])    
{
    // Enforce correct usage: must have exactly 0 or 2 command line args.
    // Remember that the program name itself is always counted by argc.
    if (not ((argc == 1) or (argc == 3)))
        abort("Usage: ./isprime [input_file output_file]");
    else if (argc == 1) {
        run_primes_loop(cin, cout);
    }
    else {  // argc == 3
        // Declare our file streams.
        ifstream instream;
        ofstream outstream;
        // Pass instream and the first file name from command line.
        open_or_die(instream,  argv[1]);
        // Pass ostream and the second file name from command line.
        open_or_die(outstream,  argv[2]);

        // Notice: We can call run_primes_loop with either cin/cout *or*
        // instream/outstream.
        run_primes_loop(instream, outstream);

        instream.close();
        outstream.close();
    }

    
    return 0;
}

void abort(string error_message)
{
    cerr << error_message << endl;
    exit(EXIT_FAILURE);
}

/*
 * Try to open the given file.
 * Abort on failure.
 * If the function returns, caller can assume stream is open.
 * By using a template, we gain modularity: this function will work
 * for ifstreams *and* ofstreams.
 */
template<typename streamtype>
void open_or_die(streamtype &stream, string file_name)
{
    stream.open(file_name);
    if (not stream.is_open())
        abort("Unable to open:  " + file_name);
}

/*
 * Reads from given input, and prints to given output, 
 * until it reads in a negative number.
 * Notice: istream and ostream parameters *must always be* reference parameters.
 */
void run_primes_loop(istream &input, ostream &output)
{
    int curr_num;

    input >> curr_num;
    while (not input.fail() and curr_num >= 0) {
        if (isPrime(curr_num)) {
            output << "Prime!" << endl;
        } else {
            output << "Composite!" << endl;
        }
        input >> curr_num;
    }
}

bool isPrime(int num)
{
    if (num <= 1) 
        return false;
    else {
        // Brute force approach.
        for (int i = 2; i < num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
}