/*
 * This program demonstrates the use of the C++ vector facility, which
 * is the equivalent of an ArrayList implementation in the C++
 * Standard Template Library (STL).  The STL contains industrial
 * strength implementations of a wide variety of data structures.  In
 * real life you wouldn't implement these, but in CS 15, you will
 * learn how they work!
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> names;       // Creates vector. no size necessary!
                                // You put element type in the <  >
  
    names.push_back("alice");   // add 3 elements, each to the end (back)
    names.push_back("bob");
    names.push_back("carol");
  
    cout << "names[0] is " << names[0] << endl; 
    cout << "names[1] is " << names[1] << endl;

    names[0] = "diego";

    // we even have a size() function!
    cout << "names currently has " << names.size() << " elements." << endl;

    for (size_t i = 0; i < names.size(); i++) {
        /* we can also use the vector at() function.
         * this is nearly identical to [], but it also will raise an error
         * if I try to access an out-of-bounds address.
         */
        cout << "names[" << i << "]" << " = " << names.at(i) << endl;
    }

    // removes last element
    names.pop_back(); 

    cout << "names currently has " << names.size() << " elements." << endl;

    return 0;
}