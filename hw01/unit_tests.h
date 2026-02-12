/*
 * unit_tests.h
 *
 * CS 15 homework 1
 * by Tyler Calabrese, January 2021
 * edited by: Milod Kazerounian, January 2022
 * edited by: Charlotte Wong, January 2026 (CS15 HW1 Character Array Lists)
 *
 * Uses Matt Russell's unit_test framework to test the CharArrayList class.
 *
 * File purpose:
 * This file's purpose is to implement several independent tests that run using
 * the "unit_test" terminal command. Testing through the unit_tests system 
 * allows for easier pinpointing of bugs targetting specific functions with
 * certain tests, so that failed tests immediately reveal the origin of the 
 * errors.
 */

#include <cassert>
#include <stdexcept>
#include "CharArrayList.h"
using namespace std;

/* 
 * dummy test
 * A dummy test to ensure class definition is syntactically correct;
 * tests nothing.
 */
void dummy_test() {}

/*
 * constructor test 0
 * Make sure no fatal errors/memory leaks in the default constructor
 * (implicit testing of destructor)
 */
void constructor_test_0() {
    CharArrayList list; 
} 

/*
 * constructor test 1
 * Make sure no fatal errors/memory leaks in the second constructor
 * (implicit testing of destructor)
 */
void constructor_test_1() {
    CharArrayList list('c'); 
    assert(not list.isEmpty()); //arraylist shouldn't be empty
    assert(list.size() == 1);
} 

/*
 * constructor test x
 * Make sure third constructor properly constructs an array list
 * (implicit testing of destructor)
 */
void constructor_test_array() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharArrayList list(arr, 4); 
    assert(not list.isEmpty()); //arraylist shouldn't be empty
    assert(list.size() == 4); //arraylist should have four elements in it
} 

/*
 * constructor test deep
 * Make sure copy constructor constructs a copy of some array
 * (implicit testing of destructor)
 */
void constructor_test_deep() {
    char arr[5] = {'s', 't', 'u', 'f', 'f'};
    CharArrayList list(arr, 5);
    CharArrayList copy(list);
    assert(copy.size() == 5);
}

/*
 * destructor test 0
 * Make sure there are no fatal errors/memory leaks in the destructor
 */
void destructor_test_0() {
    CharArrayList list; //delete empty array list
}

/*
 * destructor test 1
 * Make sure no fatal errors/memory leaks in the destructor when an array lists
 * with character(s) are deleted
 * 
 * all following tests implicitly test some constructor, as some character
 * array list must be constructed in order to run tests on it.
 * 
 * all following tests implicitly test the destructor, as it is called as soon
 * as void function call ends, and the instance goes out of scope. 
 */
void destructor_test_1() {
    CharArrayList list('a');
    char arr[5] = {'s', 't', 'u', 'f', 'f'};
    CharArrayList list1(arr, 7);
}

/*
 * isEmpty_test
 * ensure newly created array list appears to be empty when isEmpty is called
 */
void isEmpty_test() {
    CharArrayList list; 
    assert(list.isEmpty()); //newly created array list should be empty
}

/*
 * sizeIs_0_test
 * ensure newly created array list appears to have zero elements
 */
void sizeIs_0_test() {
    CharArrayList list; 
    assert(list.size() == 0); //newly created array list should have zero chars
}

/*
 * clear test
 * makes sure clearing a list yields a list with size of zero and that's empty
 */
void clear_test() {
    char arr[5] = {'h', 'e', 'l', 'l', 'o'};
    CharArrayList list(arr, 5);
    assert(list.size() == 5);
    list.clear();
    assert(list.size() == 0);
    assert(list.isEmpty());
}

/*
 * deep copy edits test
 * ensures editing an arraylist's deep copy doesn't change length of original
 */
void deep_copy_edits_test() {
    char arr[5] = {'h', 'e', 'l', 'l', 'o'};
    CharArrayList list(arr, 5);
    CharArrayList deep(list);
    deep.clear();
    assert(deep.isEmpty());
    assert(not list.isEmpty());
    assert(list.size() == 5);
}

/*
 * first test
 * verifies for a basic example that the first method does return the character
 * at the start of character array list
 */
void first_test() {
    char arr[5] = {'h', 'e', 'l', 'l', 'o'};
    CharArrayList list(arr, 5);
    assert(list.first() == 'h');
}

/*
 * first test empty
 * confirms that when first method is called on an empty array list, the 
 * appropriate error is thrown along with the correct error message
 */
void first_test_empty() {
    CharArrayList empty;
    try {
        char c;
        c = empty.first();
    } catch (runtime_error &error) {
        assert((string) error.what() == "cannot get first of empty ArrayList");
    }
}

/*
 * last test
 * verifies that calling last in a basic character array list does return the 
 * last character of a given array list
 */
void last_test() {
    char arr[5] = {'h', 'e', 'l', 'l', 'o'};
    CharArrayList list(arr, 5);
    assert(list.last() == 'o');
}

/*
 * last test empty
 * verifies that calling last on an empty array list throw the correct error and
 * error message
 */
void last_test_empty() {
    CharArrayList empty;
    try{
        char c;
        c = empty.last();
    } catch (runtime_error &error) {
        assert((string) error.what() == "cannot get last of empty ArrayList");
    }
}

//below is a test for a private helper function that was temporarily made public
//for testing purposes. Commented out as it no longer passes due to the
//function being made private.

// void just_String_test(){ 
//     //temporary test for private helper function for toString()
//     char arr[5] = {'h', 'e', 'l', 'l', 'o'};
//     CharArrayList list(arr, 5);
//     // CharArrayList test("string", 6);
//     assert(list.justString() == "hello");
// }

/*
 * element at test
 * tests elementAt method's accuracy in return correct character for each 
 * corresponding index of a given character arraylist
 */
void element_at_test() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharArrayList list(arr, 4);
    cout << list.elementAt(1) << endl;
    assert(list.elementAt(0) == 't');
    assert(list.elementAt(1) == 'e');
    assert(list.elementAt(2) == 's');
    assert(list.elementAt(3) == 't');
}

/*
 * element at empty test
 * confirms that calling elementAt on an empty character array list throws the 
 * correct error and error message
 */
void element_at_empty_test() { 
    CharArrayList empty;
    try{
        char test = empty.elementAt(1);
    } catch(range_error &error) {
        assert((string) error.what() == "index (1) not in range [0..0)");
    }
}

//make simple out of range test

/*
 * copyconst test
 * verifies the copy constructor creates a deep copy of another character array
 * list
 */
void copyconst_test(){ 
    char arr[6] = {'s', 't', 'r', 'i', 'n', 'g'};
    CharArrayList test(arr, 6);
    CharArrayList copy = test;
    assert(copy.elementAt(0) == 's');
    assert(copy.elementAt(1) == 't');
    assert(copy.elementAt(2) == 'r');
    assert(copy.elementAt(3) == 'i');
    assert(copy.elementAt(4) == 'n');
    assert(copy.elementAt(5) == 'g');
}

/*
 * operator_basic_test
 * test a basic case of creating a deep copy of one char array list into another
 * through the overloaded operator
 */
void operator_basic_test() {
    char arr1[3] = {'c', 'a', 't'};
    char arr2[5] = {'h', 'e', 'l', 'l', 'o'};
    
    CharArrayList cat(arr1, 3);
    CharArrayList hello(arr2, 5);
    
    cat = hello;
    
    assert(cat.size() == 5);
    assert(cat.toString() == "[CharArrayList of size 5 <<hello>>]");
    assert(hello.toString() == "[CharArrayList of size 5 <<hello>>]");
}

//below is a private helper function test

// void just_Reverse_String_test(){ //private helper function test
//     char arr[6] = {'s', 't', 'r', 'i', 'n', 'g'};
//     CharArrayList test(arr, 6); 
//     assert(test.justReverseString() == "gnirts");
// }

/*
 * toString test
 * ensures toString generates the correct message
 */
void toString_test() {
    char arr[6] = {'s', 't', 'r', 'i', 'n', 'g'};
    CharArrayList test(arr, 6); 
    assert(test.toString() == "[CharArrayList of size 6 <<string>>]");
}

/*
 * toString empty test
 * confirms toString still functions properly on an empty character array list
 */
void toString_empty_test() {
    CharArrayList empty;
    assert(empty.toString() == "[CharArrayList of size 0 <<>>]");
}

/*
 * toReverseString empty test
 * validates accuracy of the message generated by toReverseString on an empty
 * character array list
 */
void toReverseString_empty_test() {
    CharArrayList empty;
    assert(empty.toReverseString() == "[CharArrayList of size 0 <<>>]");
}

/*
 * toReverseString test
 * checks that toReverseString returns the proper message for some arbitrary
 * character array list
 */
void toReverseString_test() {
    char arr[6] = {'s', 't', 'r', 'i', 'n', 'g'};
    CharArrayList test(arr, 6); 
    cout << test.toReverseString() << endl;
    assert(test.toReverseString() == "[CharArrayList of size 6 <<gnirts>>]");
}

/*
 * pushAtBack_test
 * ensures pushAtBack functions when pushed into an empty character array list
 */
void pushAtBack_test() {
    CharArrayList push;
    assert(push.size() == 0);
    assert(push.isEmpty());
    push.pushAtBack('h');
    assert(push.size() == 1);
    assert(not push.isEmpty());
    assert(push.elementAt(0) == 'h');
    assert(push.toString() == "[CharArrayList of size 1 <<h>>]");
    assert(push.toReverseString() == "[CharArrayList of size 1 <<h>>]");
}

/*
 * pushAtBack_longer_test
 * confirms pushAtBack functions properly when used consecutively 
 */
void pushAtBack_longer_test() {
    CharArrayList longer;
    assert(longer.isEmpty());
    longer.pushAtBack('t');
    assert(longer.elementAt(0) == 't');
    longer.pushAtBack('e');
    assert(longer.elementAt(1) == 'e');
    longer.pushAtBack('s');
    assert(longer.elementAt(2) == 's');
    longer.pushAtBack('t');
    assert(longer.elementAt(3) == 't');
    assert(longer.toString() == "[CharArrayList of size 4 <<test>>]");
    try{
        char test = longer.elementAt(4);
    } catch(range_error &error) {
        cout << error.what() << endl;
        assert((string) error.what() == "index (4) not in range [0..4)");
    }  
}

//below is a test for a private helper function that was temporarily made public
//for testing purposes. Commented out as it no longer passes due to the
//function being made private.

/*
 * shift_operations_combined_test 
 * tests using both shift operations in sequence to verify they work correctly
 * together (simulating what happens in insertAt followed by removeAt)
 */
// void shift_operations_combined_test() {
//     char arr[4] = {'a', 'b', 'c', 'd'};
//     CharArrayList test(arr, 4);
    
//     test.shiftforward(1);
    
//     test.replaceAt('x', 1);
    
//     assert(test.elementAt(0) == 'a');
//     assert(test.elementAt(1) == 'x');
//     assert(test.elementAt(2) == 'b');
//     assert(test.elementAt(3) == 'c');
    
//     test.shiftbackward(1);
    
//     assert(test.elementAt(0) == 'a');
//     assert(test.elementAt(1) == 'b');
//     assert(test.elementAt(2) == 'c');
//     assert(test.elementAt(3) == 'd');
// }

/*
 * pushAtFronts_test
 * confirms pushAtFront functions properly on an already existing array list 
 * with nonzero length
 */
void pushAtFronts_test() { 
    char arr[4] = {'t', 'e', 's', 't'};
    CharArrayList test(arr, 4);
    test.pushAtFront('a');
    cout << test.toString() << endl;
    cout << test.size() << endl;
    assert(test.size() == 5);
    assert(test.toString() == "[CharArrayList of size 5 <<atest>>]");
}

/*
 * pushAtFront_test_space
 * validates pushAtFront's functionality when the space character is pushed
 */
void pushAtFront_test_space() {
    CharArrayList empty;
    empty.pushAtFront(' ');
    assert(empty.size() == 1);
    assert(empty.elementAt(0) == ' ');
}

/*
 * operator test
 * verifies that calling last in a basic character array list does return the 
 * last character of a given array list
 */
void insertAt_test() {
    char str[2] = {'a', 't'};
    CharArrayList test(str, 2);
    assert(test.size() == 2);
    test.insertAt('r', 1);
    cout << test.size() << endl;
    assert(test.size() == 3);
    assert(test.toString() == "[CharArrayList of size 3 <<art>>]");
}

/*
 * push insert
 * interleaves pushAtFront, pushAtBack, and insertAt calls to ensure each one's
 * behavior remains as expected
 */
void push_insert() {
    CharArrayList test;
    assert(test.isEmpty());
    test.pushAtFront('a');
    test.pushAtBack('t');
    test.insertAt('c', 0);
    test.insertAt('r', 2);
    assert(test.size() == 4);
    assert(test.toString() == "[CharArrayList of size 4 <<cart>>]");
}

/*
 * inOrder test
 * confirms inOrder method functions on a basic test case
 */
void inOrder_test() {
    char abcs[3] = {'a', 'b', 'd'};
    CharArrayList alpha(abcs, 3);
    assert(alpha.size() == 3);
    alpha.insertInOrder('c');
    assert(alpha.size() == 4);
    assert(alpha.toString() == "[CharArrayList of size 4 <<abcd>>]");
}

/*
 * inOrder empty
 * validates behavior of inOrder on an empty character array list
 */
void inOrder_empty() {
    CharArrayList empty;
    empty.insertInOrder('d');
    assert(empty.size() == 1);
    assert(empty.elementAt(0) == 'd');
}

/*
 * insertAt error
 * ensures appropriate error and error message are generated by insertAt when 
 * an out of bounds error is provided
 */
void insertAt_error() {
    CharArrayList empty;
    try{
        empty.insertAt('c', 2);
    }catch(range_error &error){
        assert((string) error.what() == "index (2) not in range [0..0]");
    }  
}

/*
 * insertAt empty
 * verifies that calling last in a basic character array list does return the 
 * last character of a given array list
 */
void insertAt_empty() {
    CharArrayList empty;
    empty.insertAt('a', 0);
    assert(empty.elementAt(0) == 'a');
    empty.insertInOrder('a');
    empty.insertInOrder('z');
    empty.insertInOrder('a');
    assert(empty.size() == 4);
    assert(empty.toString() == "[CharArrayList of size 4 <<aaaz>>]");
}

/*
 * insertInOrder empty
 * verifies that calling last in a basic character array list does return the 
 * last character of a given array list
 */
void insertInOrder_empty() {
    CharArrayList empty;
    empty.insertInOrder('c');
    assert(empty.toString() == "[CharArrayList of size 1 <<c>>]");
}

/*
 * insertinOrder end
 * confirm that insert in order functions properly even when characters must be
 * inserted at the end of the char array list
 */
void insertInOrder_end() {
    char arr[3] = {'a', 'b', 'c'};
    CharArrayList list(arr, 3);
    list.insertInOrder('z');
    assert(list.size() == 4);
    assert(list.elementAt(3) == 'z');
    assert(list.toString() == "[CharArrayList of size 4 <<abcz>>]");
}

/*
 * popFromFront t
 * ensures popFromFront proper behavior, resulting in a decrement of size
 */
void popFromFront_t() {
    CharArrayList small('a');
    assert(small.size() == 1);
    small.popFromFront();
    assert(small.size() == 0);
}

/*
 * remove from word
 * ensures sequential removal of several characters from a character array list
 * functions properly, as well as removal generating the appropriate error when
 * an out of bounds index was provided
 */
void remove_from_word() {
    char arr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    CharArrayList bet(arr, 10);
    assert(bet.size() == 10);
    assert(bet.toString() == "[CharArrayList of size 10 <<abcdefghij>>]");
    bet.popFromFront();
    assert(bet.size() == 9);
    assert(bet.toString() == "[CharArrayList of size 9 <<bcdefghij>>]");
    bet.popFromBack();
    assert(bet.size() == 8);
    assert(bet.toString() == "[CharArrayList of size 8 <<bcdefghi>>]");
    bet.removeAt(1);
    assert(bet.size() == 7);
    assert(bet.toString() == "[CharArrayList of size 7 <<bdefghi>>]");
    try{
        bet.removeAt(bet.size());
    }catch(range_error &error){
        cout << error.what() << endl;
        assert((string) error.what() == "index (7) not in range [0..7)");
    }
}

/*
 * popFrontEmpty
 * confirms popFromFront generaates an accurate error message when called on an
 * empty array list
 */
void popFrontEmpty() {
    CharArrayList empty;
    try{
        empty.popFromFront();
    }catch(runtime_error &error){
        assert((string) error.what() == "cannot pop from empty ArrayList");
    }
}

/*
 * popBackEmpty
 * verifies popBackEmpty generates the correct error message when called on an
 * empty array list
 */
void popBackEmpty() {
    CharArrayList empty;
    try{
        empty.popFromBack();
    }catch(runtime_error &error){
        assert((string) error.what() == "cannot pop from empty ArrayList");
    }
}

/*
 * replaceAt basic
 * replaces one character in an array list and ensures the correct character 
 * array list results from this (test -> tast)
 */
void replaceAt_basic() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharArrayList test(arr, 4);
    test.replaceAt('a', 1);
    cout << test.toString() << endl;
    assert(test.toString() == "[CharArrayList of size 4 <<tast>>]");
}

/*
 * replaceAt error
 * confirms that replacing a character into an out of bounds index generates the
 * appropriate error and error message; index 4 is not in 0, 1, 2, or 3
 */
void replaceAt_error() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharArrayList test(arr, 4);
    try{
        test.replaceAt('a', 4);
    } catch (range_error &error) {
        assert((string) error.what() == "index (4) not in range [0..4)");
    }
}

/*
 * concatenate
 * tests the concatenation function and confirms the expected concatenation 
 * occurs
 */
void concatenate() {
    char arr[3] = {'c', 'a', 't'};
    char arr2[8] = {'c', 'h', 'e', 's', 'h', 'i', 'r', 'e'};
    CharArrayList cat(arr, 3);
    CharArrayList cheshire(arr2, 8);
    CharArrayList *p = &cheshire;
    cat.concatenate(p);
    cout << cat.toString() << endl;
    assert(cat.toString() == "[CharArrayList of size 11 <<catcheshire>>]");
}

/*
 * self_concat
 * ensures a char array list's concatenation with itself yields the expected
 * resulting char array list
 */
void self_concat(){
    char arr[3] = {'c', 'a', 't'};
    CharArrayList cat(arr, 3);
    cat.concatenate(&cat);
    assert(cat.toString() == "[CharArrayList of size 6 <<catcat>>]");
}

/*
 * self_concat_large
 * ensure larger character array lists can also concatenate with themselves
 */
void self_concat_large(){
    CharArrayList cat;
    for(int i = 0; i < 100; i++) {
        cat.pushAtBack('a');
    }
    cat.concatenate(&cat);
    assert(cat.size() == 200);
    for(int i = 0; i < 200; i++) {
        assert(cat.elementAt(i) == 'a');
    }
}

/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

/* To give an example of thorough testing, we are providing
 * the unit tests below which test the insertAt function. Notice: we have
 * tried to consider all of the different cases insertAt may be
 * called in, and we test insertAt in conjunction with other functions!
 *
 * You should emulate this approach for all functions you define.
 */

// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() {
    CharArrayList test_list;
    test_list.insertAt('a', 0);
    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'a');
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
        // insertAt for out-of-range index
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        // if insertAt is correctly implemented, a range_error will be thrown,
        // and we will end up here
        range_error_thrown = true;
        error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
}

// Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
}

// Tests insertion into front of a larger list
void insertAt_front_large_list() {
    char test_arr[9] = {'a', 'b', 'c', 'z', 'd', 'e', 'f', 'g', 'h'};
    CharArrayList test_list(test_arr, 9);

    test_list.insertAt('y', 0);

    assert(test_list.size() == 10);
    assert(test_list.elementAt(0) == 'y');
    assert(test_list.toString() == "[CharArrayList of size 10 <<yabczdefgh>>]");
}

// Tests insertion into the back of a larger list
void insertAt_back_large_list() {
    char test_arr[10] = {'y', 'a', 'b', 'c', 'z', 'd', 'e', 'f', 'g', 'h'};
    CharArrayList test_list(test_arr, 10);

    test_list.insertAt('x', 10);

    assert(test_list.size() == 11);
    assert(test_list.elementAt(10) == 'x');
    assert(test_list.toString() ==
           "[CharArrayList of size 11 <<yabczdefghx>>]");
}

// Tests insertion into the middle of a larger list
void insertAt_middle_large_list() {
    char test_arr[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    CharArrayList test_list(test_arr, 8);

    test_list.insertAt('z', 3);

    assert(test_list.size() == 9);
    assert(test_list.elementAt(3) == 'z');
    assert(test_list.toString() == "[CharArrayList of size 9 <<abczdefgh>>]");
}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {
    char test_arr[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    CharArrayList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    } catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");
}

void inOrder_edgecase(){
    CharArrayList test("abCdefghijklmnopqrStuvwxyz", 26);
    for(int i = 0; i < 26; i++) {
        test.insertInOrder('A' + i);
    }
    cout << test.toString() << endl;
    assert(test.toString() == "[CharArrayList of size 52 <<ABCDEFGHIJKLMNOPQRSTU
    VWXYZabCdefghijklmnopqrStuvwxyz>>]");
}
