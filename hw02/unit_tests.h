/*
 *  unit_tests.h
 *  Charlotte Wong (cwong22)
 *  January 28, 2026
 *
 *  CS 15 HW 2 Cheshire ConCATenation
 *
 *  File purpose:
 *  This file's purpose is to implement several independent tests that run using
 *  the "unit_test" terminal command. Testing through the unit_tests system 
 *  allows for easier pinpointing of bugs targetting specific functions with
 *  certain tests, so that failed tests immediately reveal the origin of the 
 *  errors.
 *
 */

#include <cassert>
#include <stdexcept>
#include "CharLinkedList.h"
using namespace std;

/*
 * dummy test
 * test to ensure no syntax errors with class definition
 */
void dummy_test() {}

/* 
 * constructor test1
 * tests whether a linked list is created and destroyed correctly
 */
void constructor_test1() {
    CharLinkedList list;
}

/*
 * constructor2
 * basic test to ensure second constructor creates a new linked list and 
 * destructor deletes the memory once it's out of scope
 */
void constructor2() {
    CharLinkedList list('c');
}

/*
 * constructor 3
 * basic test to confirm the third constructor creates a linked list with the 
 * provided array, and destructor deletes it
 */
void constructor3() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr, 4);
    assert(test.size() == 4);
}

/*
 * copy constructor
 * tests that the copy constructor creates a list with the same contents of 
 * the linked list it made a deep copy of
 */
void copy_constructor() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr, 4); 
    CharLinkedList copy(test);
    assert(copy.toString() == test.toString());
}

/*
 * copy constr change
 * ensures the copy created by the copy constructor is deep, by changing the 
 * deep copy, the original should remain unchanged
 */
void copy_constr_change() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr, 4); 
    CharLinkedList copy(test);
    copy.popFromBack();
    assert(copy.size() == test.size() - 1);
    assert(copy.toString() == "[CharLinkedList of size 3 <<tes>>]");
    assert(test.toString() == "[CharLinkedList of size 4 <<test>>]");
}

/*
 * operator test
 * tests overloaded assignment operator behavior by setting two existing linked
 * lists equal; the one on the right should remain intact, while the one on the
 * left should become a deep copy of the right instance
 */
void operator_test() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr, 4);
    assert(test.size() == 4);  
    char arr2[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr2, 4);
    abcs = test;
    assert(abcs.size() == 4);
    abcs.popFromBack();
    assert(abcs.size() + 1 == test.size());
     
}

/*
 * empty test
 * test to ensure a newly created linked list with no characters accurately 
 * appears to be empty
 */
void empty_test() {
    CharLinkedList empty;
    assert(empty.isEmpty());
}

/*
 * clear test
 * confirms that clearing a one character linked list yields a list that appears
 * to be empty
 */
void clear_test() {
    CharLinkedList one('a');
    one.clear();
    assert(one.isEmpty());
}

/*
 * clear full
 * confirms that calling clear on a previously non-empty linked list results in
 * an empty linked list
 */
void clear_full(){
    char arr[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    CharLinkedList full(arr, 7);
    full.clear();
    assert(full.isEmpty());
}

/*
 * negative numItems
 * ensures that calling clear multiple times has expected behavior; the second
 * call has no effect and the linked list ends up being empty
 */
void negative_numItems() {
    char arr[3] = {'a', 'b', 'c'};
    CharLinkedList list(arr, 3);

    list.clear();
    list.clear();
    assert(list.isEmpty());
}


/*
 * size test
 * ensures size function returns expected size for easily countable arrays 
 * with size of one, and zero
 */
void size_test() {
    CharLinkedList test('a');
    assert(test.size() == 1);
    test.clear();
    assert(test.size() == 0);
}

/*
 * first test
 * confirms that the first function correctly returns the only 
 * character in a linked list
 */
void first_test() {
    CharLinkedList one('z');
    assert(one.size() == 1);
    assert(one.first() == 'z');
}

/*
 * first on Empty
 * ensures the trying to call the first method on an empty linked list throws 
 * the appropriate error type and correct error message
 */
void first_onEmpty() {
    CharLinkedList empty;
    try {
        char c;
        c = empty.first();
    } catch (runtime_error &error) {
        assert((string)error.what() == "cannot get first of empty LinkedList");
    }
}

/*
 * last test
 * confirms that using first method on one character linked list returns the 
 * correct character
 */
void last_test() {
    CharLinkedList one('g');
    assert(one.size() == 1);
    assert(one.first() == 'g');
}

/*
 * last on empty
 * verifies that calling last on an empty linked list throws the appropriate 
 * error and correct error message
 */
void last_on_empty(){
    CharLinkedList empty;
    try {
        char c;
        c = empty.last();
    } catch (runtime_error &error) {
        assert((string)error.what() == "cannot get last of empty LinkedList");
    }
}

/*
 * push at front
 * confirms that pushAtFront method correctly pushes new characters to the front
 * of an initially empty linked list
 */
void push_at_front(){
    CharLinkedList test;
    test.pushAtFront('t');
    assert(test.size() == 1);
    test.pushAtFront('s');
    assert(test.size() == 2);
    test.pushAtFront('e');
    assert(test.size() == 3);
    test.pushAtFront('t');
    assert(test.size() == 4);
    assert(test.toString() == "[CharLinkedList of size 4 <<test>>]");
}

/*
 * to str
 * ensures that toString returns the expected output when called on a nonempty
 * linked list
 */
void to_str() {
    char arr[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    CharLinkedList test(arr, 7);
    assert(test.toString() == "[CharLinkedList of size 7 <<abcdefg>>]");
}

/*
 * push at back
 * test whether calling pushAtBack multiple times functions as expected, 
 * addending to the end of a linked list sequentially
 */
void push_at_back(){
    CharLinkedList test;
    test.pushAtBack('t');
    test.pushAtBack('e');
    test.pushAtBack('s');
    test.pushAtBack('t');
    assert(test.toString() == "[CharLinkedList of size 4 <<test>>]");
}

/* 
 * constructor 3
 * a basic test to confirm constructing a linked list in accordance with an 
 * existing character linked list creates a linked list with same characters and
 * order as the array
 */
void constructor_3(){
    char arr[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr, 4);
    assert(test.size() == 4);
    cout << test.toString() << endl;
    assert(test.toString() == "[CharLinkedList of size 4 <<test>>]");
}

/*
 * clear then add
 * test that adding characters to a linked list after calling clear on it still 
 * behaves as expected
 */
void clear_then_add(){
    char arr[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr, 4);
    assert(test.toString() == "[CharLinkedList of size 4 <<test>>]");
    test.clear();
    assert(test.size() == 0);
    test.pushAtBack('a');
    assert(test.size() == 1);
}

/*
 * element At
 * stress tests pushAtBack and accuracy tests elementAt by inserting alternating
 * characters into a linked list, and ensuring they are pushed in the correct 
 * order
 */
void element_at(){
    char arr[5] = {'a', 'e', '1', '!', ' '};
    CharLinkedList test;
    for (int i = 0; i < 100; i++){
        test.pushAtBack(arr[i%5]);
    }
    for (int i = 0; i < test.size(); i++){
        assert(test.elementAt(i) == arr[i%5]);
    }
}

/*
 * element error
 * confirms that calling elementAt with a provided index that exceeds the 
 * existing list's size throws the appropriate error and correct error message
 */
void element_error() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr, 4);
    try {
        char c;
        c = test.elementAt(test.size());
    } catch (range_error &error) {
        cout << error.what() << endl;
        assert((string)error.what() == "index (4) not in range [0..4)");
    }
}

/*
 * toString
 * tests whether toString method returns expected output containing accurate 
 * size and string contents for a one character linked list
 */
void toString() {
    CharLinkedList one('a');
    cout << one.toString() << endl;
    assert(one.toString() == "[CharLinkedList of size 1 <<a>>]");
}

/*
 * toString both
 * tests accuracy of functions toString and toReverseString and ensures that 
 * they yield the accurate message output
 */
void toString_both() {
    char arr[5] = {'a', 'e', '1', '!', ' '};
    CharLinkedList test(arr, 5);
    assert(test.toString() == "[CharLinkedList of size 5 <<ae1! >>]");
    cout << test.toReverseString() << endl;
    assert(test.toReverseString() == "[CharLinkedList of size 5 << !1ea>>]");
}

/*
 * toString empty
 * ensures calling toString on an empty list yields the expected output
 */
void toString_empty() {
    CharLinkedList empty;
    assert(empty.toString() == "[CharLinkedList of size 0 <<>>]");
}

/*
 * insert
 * confirms that inserting characters occurs properly through insertAt method
 */
void insert() {
    char arr[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr, 4);
    test.insertAt('a', 0);
    cout << test.toString() << endl;
    assert(test.toString() == "[CharLinkedList of size 5 <<atest>>]");
    test.insertAt('t', 1);
    cout << test.toString() << endl;
    assert(test.toString() == "[CharLinkedList of size 6 <<attest>>]");
}

/*
 * insert error
 * verifies that attempting to use insertAt on an empty linked list on a nonzero
 * index throws the appropriate error type and correct error message
 */
void insert_error(){
    CharLinkedList empty;
    try {
        empty.insertAt('t', 1);
    } catch (range_error &error) {
        assert((string)error.what() == "index (1) not in range [0..0]");
    }
}

/*
 * empty ins nonerror
 * confirms that inserting into an empty linked list functions as expected when
 * inserting to index 0
 */
void empty_ins_nonerror(){
    CharLinkedList empty;
    empty.insertAt('a', 0);
    assert(empty.toString() == "[CharLinkedList of size 1 <<a>>]");
}

/*
 * insert error 2
 * tests that insertAt throws appropriate error type when called on nonempty
 * linked list with index that is out of bounds with correct error message
 */
void insert_error_2(){
    char arr[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr, 4);
    try {
        test.insertAt('8', 5);
    } catch (range_error &error) {
        assert((string)error.what() == "index (5) not in range [0..4]");
    }
}

/*
 * in order
 * confirms that inserting a character into an already sorted list yields a list
 * that is still correctly sorted
 */
void in_order() {
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4);
    abcs.insertInOrder('d');
    cout << abcs.toString() << endl;
    assert(abcs.toString() == "[CharLinkedList of size 5 <<abcde>>]");
}

/*
 * order empty
 * validates behavior of insertInOrder when called upon a previously empty 
 * linked list
 */
void order_empty() {
    CharLinkedList empty;
    empty.insertInOrder('m');
    assert(empty.toString() == "[CharLinkedList of size 1 <<m>>]");
}

/*
 * inOrder edgecase
 * attempted replication of a failed test from character array lists homework
 * implementation, where provided list isn't not in order (despite spec stating
 * that we may assume it is in order)
 */
void inOrder_edgecase() {
    CharLinkedList test("abCdefghijklmnopqrStuvwxyz", 26);
    for (int i = 0; i < 26; i++) {
        test.insertInOrder('A' + i);
    }
    string s = "[CharLinkedList of size 52 <<ABCDEFGHIJKLMNOPQRSTUVWXYZabC";
    s += "defghijklmnopqrStuvwxyz>>]";
    cout << test.toString() << endl;
    assert(test.toString() == s);
}

/*
 * pop front
 * ensures that popping a character off the front of a one character linked list
 * yields the expected outcome
 */
void pop_front(){
    CharLinkedList test('a');
    test.popFromFront();
    assert(test.toString() == "[CharLinkedList of size 0 <<>>]");
}

/* 
 * pop front empty
 * confirms that calling popFromFront on an already empty linked list throws the
 * appropriate error type and correct error message
 */
void pop_front_empty() {
    CharLinkedList empty;
    try {
        empty.popFromFront();
    } catch (runtime_error &error) {
        assert((string)error.what() == "cannot pop from empty LinkedList");
    }
}

/*
 * pop front long
 * validates behavior of popFromFront on a linked list containing multiple 
 * nodes/characters
 */
void pop_front_long() {
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4);
    abcs.popFromFront();
    assert(abcs.toString() == "[CharLinkedList of size 3 <<bce>>]");
}

/*
 * pop back
 * confirms that calling popFromBack on a linked list containing one character
 * yields an empty linked list, outputting the expected string message
 */
void pop_back() {
    CharLinkedList nine('9');
    nine.popFromBack();
    assert(nine.toString() == "[CharLinkedList of size 0 <<>>]");
}

/*
 * pop back long
 * verifies behavior of popFromBack when called on a linked list with multiple 
 * elements
 */
void pop_back_long() {
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4);
    abcs.popFromBack();
    assert(abcs.toString() == "[CharLinkedList of size 3 <<abc>>]");
}

/*
 * pop back empty
 * ensures that calling popFromback on an already empty linked list throws 
 * appropriate error type and correct error message
 */
void pop_back_empty() {
    CharLinkedList empty;
    try {
        empty.popFromBack();
    } catch (runtime_error &error) {
        assert((string)error.what() == "cannot pop from empty LinkedList");
    }
}

/*
 * remove
 * confirms that removeAt function behaves as expected in a generic test
 */
void remove() {
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4);
    abcs.removeAt(2);
    assert(abcs.size() == 3);
    assert(abcs.toString() == "[CharLinkedList of size 3 <<abe>>]");
}

/*
 * remove front
 * verifies that removing from index zero behaves the same way as popFromFront
 */
void remove_front() {
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4);
    abcs.removeAt(0);
    assert(abcs.size() == 3);
    assert(abcs.toString() == "[CharLinkedList of size 3 <<bce>>]");
}

/*
 * remove back
 * ensures that removeAt behaves the same way as popFromBack when used at 
 * backmost index
 */
void remove_back() {
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4);   
    abcs.removeAt(3);
    assert(abcs.toString() == "[CharLinkedList of size 3 <<abc>>]");
    assert(abcs.size() == 3);
}

/*
 * replace
 * confirms that replaceAt functions as expected in a basic test scenario
 */
void replace(){
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4);  
    abcs.replaceAt('d', 3);
    assert(abcs.toString() == "[CharLinkedList of size 4 <<abcd>>]");
    assert(abcs.size() == 4);
}

/*
 * replace error
 * ensures that calling replaceAt with an out of bounds index throws the 
 * appropriate error and correct error message
 */
void replace_error(){
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4); 
    try {
        abcs.replaceAt('d', 4);
    } catch (range_error &error) {
        assert((string)error.what() == "index (4) not in range [0..4)");
    }
}

/*
 * replace error empty
 * ensures that attempting to replace at index zero of an empty linked list
 * throws the expected error type and message
 */
void replace_error_empty() {
    CharLinkedList empty;
    try {
        empty.replaceAt('a', 0);
    } catch (range_error &error) {
        assert((string)error.what() == "index (0) not in range [0..0)");
    }
}

/*
 * concat
 * a basic test for concatenation function to ensure it produces the expected
 * output
 */
void concat() {
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4); 
    char arr2[4] = {'t', 'e', 's', 't'};
    CharLinkedList test(arr2, 4);
    abcs.concatenate(&test);
    cout << abcs.toString() << endl;
    assert(abcs.size() == 8);
    assert(abcs.toString() == "[CharLinkedList of size 8 <<abcetest>>]");
}

/*
 * self concat
 * test whether concatenating a linked list with itself yields the expected
 * resulting linked list
 */
void self_concat() {
    char arr[4] = {'a', 'b', 'c', 'e'};
    CharLinkedList abcs(arr, 4); 
    abcs.concatenate(&abcs);
    assert(abcs.size() == 8);
    assert(abcs.toString() == "[CharLinkedList of size 8 <<abceabce>>]");
}

/*
 * self concat then remove
 * ensures that removeAt function still functions as expected after self 
 * concatenation
 */
void self_concat_then_remove() {
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('c');
    list.concatenate(&list);
    list.removeAt(2);
    cout << list.toString() << endl;
    assert(list.toString() == "[CharLinkedList of size 5 <<ababc>>]");
}

/* 
 * interleave
 * interleaves multiple methods to ensure that even when interacting, each 
 * function behaves as expected. 
 * explicit testing of pushAtBack, size, isEmpty, toString, pushAtFront
 * implicit testing of constructor and destructor
 */
void interleave() {
    CharLinkedList test;
    test.pushAtBack('a');
    test.pushAtBack('b');
    assert(test.size() == 2);
    test.concatenate(&test);
    assert(test.size() == 4);
    assert(not test.isEmpty());
    assert(test.toString() == "[CharLinkedList of size 4 <<abab>>]");
    test.insertAt('c', 2);
    assert(test.size() == 5);
    assert(test.toString() == "[CharLinkedList of size 5 <<abcab>>]");
    test.clear();
    assert(test.size() == 0);
    assert(test.isEmpty());
    test.pushAtFront('a');
    assert(test.size() == 1);
}

/* interleave 1
 * testing interleaved functions including third constructor, size, 
 * insertInOrder, elementAt explicitly.
 * implicit testing of destructor, constructors
 */
void interleave_1(){
    char arr[10] = {'a', 'a', 'b', 'c', 'e', 'f', 'k', 'l', 'y', 'y'};
    CharLinkedList mylist(arr, 10);
    assert(mylist.size() == 10);
    char arr2[24] = {'b', 'd', 'i', 'm', 'n', 'o', '4', '%', 'z', 'g', 'h', 
                    'p', 'q', 'r', 's', 't', '2', '5', '}', '2', '^', '~',
                    ' ', '?'};
    CharLinkedList rand(arr2, 24);
    for (int i = 0; i < 100; i++) {
        mylist.insertInOrder(rand.elementAt(i%14));
    }
    assert(mylist.size() == 110);
    for (int i = 0; i < mylist.size() - 1; i++) {
        cout << mylist.elementAt(i) << " < " << mylist.elementAt(i+1) << endl;
        assert(mylist.elementAt(i) <= mylist.elementAt(i+1));
    }

    try {
        mylist.replaceAt('x', 110);
    } catch (range_error &error) {
        assert((string)error.what() == "index (110) not in range [0..110)");
    }
}

