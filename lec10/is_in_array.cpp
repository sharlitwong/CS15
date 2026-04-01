/*
 * Program to demonstrate binary search
 * 
 * Mark A. Sheldon, Tufts University
 */
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

typedef int ElemType;


void usage_abort(string program_name);
int search_target_from_command_line(int argc, char *argv[]);
bool is_in_array(ElemType array[], ElemType target, int start, int end);

int main(int argc, char *argv[])
{
        int data0[] = {};
        int data1[] = {3, 5, 9, 12, 14, 25};
        int data2[] = {3, 5, 6, 10, 12, 15, 22};

        int size0   = sizeof(data0) / sizeof(int);
        int size1   = sizeof(data1) / sizeof(int);
        int size2   = sizeof(data2) / sizeof(int);

        int search_target = search_target_from_command_line(argc, argv);

        // Make booleans print out as "true" and "false" rather than 1 and 0
        cout << boolalpha;
        
        cout << "in data0?  " << is_in_array(data0, search_target, 0, size0)
             << endl;
        cout << "in data1?  " << is_in_array(data1, search_target, 0, size1)
             << endl;
        cout << "in data2?  " << is_in_array(data2, search_target, 0, size2)
             << endl;

        return 0;
}

/* Print usage message to cerr and abort the program */
void usage_abort(string program_name)
{
        cerr << "Usage:  " << program_name << " int_to_search_for" << endl;
        exit(EXIT_FAILURE);
}

/* Get and return search target from first command line argument */
int search_target_from_command_line(int argc, char *argv[])
{
        string program_name = argv[0];

        // If search_target not provided (or extra stuff was provided), fail
        if (argc != 2)
                usage_abort(program_name);
        
        stringstream inputss(argv[1]);
        int search_target;

        // If command line arg cannot be parsed as an integer, fail
        inputss >> search_target;
        if (inputss.fail())
                usage_abort(program_name);

        return search_target;
}

/*
 * Return true if target is in array slots [start .. end)
 * Note:  includes start index, but not end index
 *        i. e., search a whole array by searching in [0 .. length)
 */
bool is_in_array(ElemType array[], ElemType target, int start, int end)
{
        cerr << "is_in_array(array, "
             << target << ", " << start << ", " << end << ")" << endl;

        int length = end - start;
        int middle = start + (length / 2);

        if (end <= start)
                return false;
        else if (target == array[middle])
                return true;
        else if (target > array[middle])
                return is_in_array(array, target, middle + 1, end); 
        else
                return is_in_array(array, target, start, middle);
}