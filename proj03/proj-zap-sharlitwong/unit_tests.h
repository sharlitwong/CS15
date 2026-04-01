/*
 *  unit_tests.h
 *  Charlotte Wong (cwong22)
 *  March 20, 2026
 *
 *  CS 15 Project 3 zap
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
#include <sstream>
#include <fstream>

using namespace std;
//#include "phaseOne.h" (used when testing phase one)
#include "HuffmanCoder.h"
#include <iostream>

/******************************PHASE 1 TESTS********************************* */

// /*
//  * dummy
//  * a dummy test that does nothing
//  */
// void dummy(){}

// /* 
//  * count_freqs_a
//  * counts the frequencies of an easily verifiable test to ensure basic 
//  * functionalities are intact
//  */
// void count_freqs_a() {
//     istringstream ss("a");
//     count_freqs(ss);
// }

// /* 
//  * count_freqs_apple_banana
//  * counts character frequencies of text in provided text file 
//  * banana_apple.txt, only verifiable through visually matching up with 
//  * spec provided printout as function is a void function (assert statements 
//  * are hard to use)
//  */
// void count_freqs_apple_banana() {
//     ifstream file("banana_apple.txt");
//     count_freqs(file);
// }

// /* 
//  * test_serialize_figure1
//  * serialize tree provided by starter code and in spec to verify 
//  * serialize_tree function works accurately, as well as that there are no 
//  * memory leaks
//  */
// void test_serialize_figure1() {
//     HuffmanTreeNode *tree = makeFigure1Tree('\0');
//     string result = serialize_tree(tree);
//     assert(result == "IIILaLbILeLfILcLd");
//     deleteTree(tree);
// }

// /* 
//  * serial_deserial
//  * serialize and deserialize a tree provided in starter code and spec, 
//  * asserting that both directions function as expected
//  */
// void serial_deserial() {
//     HuffmanTreeNode *tree = makeFigure1Tree('\0');
//     string result = serialize_tree(tree);
//     assert(result == "IIILaLbILeLfILcLd");
//     HuffmanTreeNode *new_tree = deserialize_tree(result);
//     assert(treeEquals(tree, new_tree, false, false));
//     string new_result = serialize_tree(new_tree);
//     assert(new_result == "IIILaLbILeLfILcLd");
//     deleteTree(tree);
//     deleteTree(new_tree);
// }

/***************redoing Phase 1 tests with HuffmanCoder objects****************/

// /*
//  * count_freqs_a
//  * mimics corresponding function above, using a huffman coder object rather 
//  * than classless function
//  */
// void count_freqs_a() {
//     HuffmanCoder hc;
//     istringstream ss("a");
//     hc.count_freqs(ss);
// }

// /*
//  * count_freqs_apple_banana
//  * mimics corresponding function above, using a huffman coder object rather 
//  * than classless function
//  */
// void count_freqs_apple_banana() {
//     HuffmanCoder hc;
//     ifstream file("banana_apple.txt");
//     hc.count_freqs(file);
// }

// /*
//  * test_serialize_figure1
//  * mimics corresponding function above, using a huffman coder object rather 
//  * than classless function
//  */
// void test_serialize_figure1() {
//     HuffmanCoder hc;
//     HuffmanTreeNode *tree = makeFigure1Tree('\0');
//     string result = hc.serialize_tree(tree);
//     assert(result == "IIILaLbILeLfILcLd");
//     hc.deleteTree(tree);
// }

// /*
//  * serial_deserial
//  * mimics corresponding function above, using a huffman coder object rather 
//  * than classless function
//  */
// void serial_deserial() {
//     HuffmanCoder hc;
//     HuffmanTreeNode *tree = makeFigure1Tree('\0');
//     string result = hc.serialize_tree(tree);
//     assert(result == "IIILaLbILeLfILcLd");
//     HuffmanTreeNode *new_tree = hc.deserialize_tree(result);
//     assert(treeEquals(tree, new_tree, false, false));
//     string new_result = hc.serialize_tree(new_tree);
//     assert(new_result == "IIILaLbILeLfILcLd");
//     hc.deleteTree(tree);
//     hc.deleteTree(new_tree);
// }

// //new function unit tests

// /*
//  * build_tree_single
//  * tests edge case where only one unique character exists
//  * tree should have a root with one real leaf and one dummy leaf
//  */
// void build_tree_single() {
//     HuffmanCoder hc;
//     map<char, int> freqs = {{'a', 5}};
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     assert(not tree->is_leaf());          // root should be internal
//     assert(tree->get_left()->is_leaf());  // children should be leaves
//     assert(tree->get_right()->is_leaf());
//     hc.deleteTree(tree);
// }

// /*
//  * build_tree_two_chars
//  * tests simplest non-trivial case: two characters
//  * root should have exactly two leaf children
//  */
// void build_tree_two_chars() {
//     HuffmanCoder hc;
//     map<char, int> freqs = {{'a', 1}, {'b', 2}};
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     assert(not tree->is_leaf());
//     assert(tree->get_left()->is_leaf());
//     assert(tree->get_right()->is_leaf());
//     assert(tree->get_freq() == 3);
//     hc.deleteTree(tree);
// }

// /*
//  * build_tree_serialize
//  * builds a tree then serializes it to verify structure is intact
//  * uses known frequencies so the tree structure is predictable
//  */
// void build_tree_serialize() {
//     HuffmanCoder hc;
//     map<char, int> freqs = {{'a', 1}, {'b', 1}};
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     string result = hc.serialize_tree(tree);
//     //should be an internal node with two leaves
//     assert(result[0] == 'I');
//     assert(result[1] == 'L');
//     assert(result[3] == 'L');
//     hc.deleteTree(tree);
// }

// /*
//  * build_tree_serial_deserial
//  * builds a tree, serializes it, deserializes it, and checks
//  * that the result matches the original via treeEquals
//  */
// void build_tree_serial_deserial() {
//     HuffmanCoder hc;
//     map<char, int> freqs = {{'a', 1}, {'b', 2}, {'c', 4}, {'d', 8}};
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     string serialized = hc.serialize_tree(tree);
//     HuffmanTreeNode *rebuilt = hc.deserialize_tree(serialized);
//     assert(treeEquals(tree, rebuilt, false, false));
//     hc.deleteTree(tree);
//     hc.deleteTree(rebuilt);
// }

// /*
//  * build_codes_two_chars
//  * verifies that with two characters, each gets a single bit code
//  * and that the codes are distinct
//  */
// void build_codes_two_chars() {
//     HuffmanCoder hc;
//     map<char, int> freqs = {{'a', 1}, {'b', 2}};
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     map<char, string> codes;
//     hc.buildCodes(tree, "", codes);
//     assert(codes['a'] != codes['b']); //codes must be distinct
//     assert(codes['a'].length() == 1); //with two chars, each code is 1 bit
//     assert(codes['b'].length() == 1);
//     hc.deleteTree(tree);
// }

// /*
//  * build_codes_freq_comp
//  * verifies the core Huffman property: more frequent characters
//  * get shorter codes
//  */
// void build_codes_freq_comp() {
//     HuffmanCoder hc;
//     //'d' has by far highest frequency, should get shortest code
//     map<char, int> freqs = {{'a', 1}, {'b', 1}, {'c', 1}, {'d', 100}};
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     map<char, string> codes;
//     hc.buildCodes(tree, "", codes);
//     assert(codes['d'].length() < codes['a'].length());
//     assert(codes['d'].length() < codes['b'].length());
//     assert(codes['d'].length() < codes['c'].length());
//     hc.deleteTree(tree);
// }

// /*
//  * encode_text_single_char
//  * encodes a single character and verifies the result matches
//  * that character's code exactly
//  */
// void encode_text_single_char() {
//     HuffmanCoder hc;
//     map<char, string> codes = {{'a', "0"}, {'b', "1"}};
//     istringstream ss("a");
//     string result = hc.encodeText(ss, codes);
//     assert(result == "0");
// }

// /*
//  * encode_text_length
//  * verifies that the length of the encoded output matches the sum of the
//  * code lengths for each character in the input string
//  */
// void encode_text_length() {
//     HuffmanCoder hc;
    
//     //use count_freqs to build the frequency map
//     istringstream ss("abc");
//     map<char, int> freqs = hc.count_freqs(ss);
    
//     //build tree and codes from that map
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     map<char, string> codes;
//     hc.buildCodes(tree, "", codes);
    
//     //need a fresh stream since count_freqs consumed the first one
//     istringstream ss2("abc");
//     string result = hc.encodeText(ss2, codes);
    
//     int expected_len = codes['a'].length() + codes['b'].length() 
//                      + codes['c'].length();
//     assert((int)result.length() == expected_len);
//     hc.deleteTree(tree);
// }

/*
 * encoder_basic
 * encodes a simple known string and verifies the output file exists
 * and that the encoded size is nonzero
 */
void encoder_basic() {
    //write a temp input file
    ofstream tmp("test_input.txt");
    tmp << "aabbcc";
    tmp.close();

    HuffmanCoder hc;
    hc.encoder("test_input.txt", "test_output.zap");

    //output file should exist and be non-empty
    ifstream out("test_output.zap");
    assert(out.is_open());
    out.seekg(0, ios::end);
    assert(out.tellg() > 0);
    out.close();
}

/*
 * encoder_empty_file
 * verifies that encoding an empty file prints the correct message
 * and does NOT create/write an output file with encoded content
 */
void encoder_empty_file() {
    ofstream tmp("test_empty.txt");
    tmp.close(); //empty file

    HuffmanCoder hc;
    //should print "test_empty.txt is empty and cannot be compressed."
    //and return without throwing
    hc.encoder("test_empty.txt", "empty_out.zap");
}

/*
 * encoder_bad_input_file
 * verifies that a nonexistent input file causes a runtime_error
 * with the correct message
 */
void encoder_bad_input_file() {
    HuffmanCoder hc;
    bool threw = false;
    try {
        hc.encoder("nonexistent_file.txt", "out.zap");
    } catch (const runtime_error &e) {
        threw = true;
        assert(string(e.what()) == 
                      "Unable to open file nonexistent_file.txt");
    }
    assert(threw);
}

/*
 * encoder_single_char
 * encodes a file with only one unique character
 * should succeed without throwing (tests the single-char edge case in 
 * buildTree)
 */
void encoder_single_char() {
    ofstream tmp("test_single.txt");
    tmp << "aaaaa";
    tmp.close();

    HuffmanCoder hc;
    //should not throw
    hc.encoder("test_single.txt", "single_out.zap");

    ifstream out("single_out.zap");
    assert(out.is_open());
    out.close();
}

// /*
//  * decode_text_basic
//  * decodes a simple known encoding and verifies the result
//  */
// void decode_text_basic() {
//     HuffmanCoder hc;
//     map<char, int> freqs = {{'a', 1}, {'b', 1}};
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     map<char, string> codes;
//     hc.buildCodes(tree, "", codes);

//     //encode "ab" then decode it and verify we get "ab" back
//     istringstream ss("ab");
//     string bits = hc.encodeText(ss, codes);
//     string result = hc.decodeText(bits, tree);
//     assert(result == "ab");
//     hc.deleteTree(tree);
// }

// /*
//  * decode_text_single_char
//  * verifies single unique character edge case:
//  * root is a leaf, so each bit maps to one copy of that character
//  */
// void decode_text_single_char() {
//     HuffmanCoder hc;
//     map<char, int> freqs = {{'a', 5}};
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     map<char, string> codes;
//     hc.buildCodes(tree, "", codes);

//     istringstream ss("aaaaa");
//     string bits = hc.encodeText(ss, codes);
//     string result = hc.decodeText(bits, tree);
//     assert(result == "aaaaa");
//     hc.deleteTree(tree);
// }

// /*
//  * decode_text_mid_tree_error
//  * verifies that a bit string ending mid-tree throws the correct 
//  * runtime_error
//  */
// void decode_text_mid_tree_error() {
//     HuffmanCoder hc;
//     //build a tree with at least 3 chars so codes are >1 bit
//     map<char, int> freqs = {{'a', 1}, {'b', 2}, {'c', 4}};
//     HuffmanTreeNode *tree = hc.buildTree(freqs);
//     map<char, string> codes;
//     hc.buildCodes(tree, "", codes);

//     //truncate 'a's code by one bit to land mid-tree
//     string bad_bits = codes['a'].substr(0, codes['a'].length() - 1);

//     bool threw = false;
//     try {
//         hc.decodeText(bad_bits, tree);
//     } catch (const runtime_error &e) {
//         threw = true;
//         assert(string(e.what()) == "Encoding did not match Huffman tree.");
//     }
//     assert(threw);
//     hc.deleteTree(tree);
// }

/*
 * encoder_roundtrip
 * encodes a file then decodes it and verifies the result matches
 * the original
 */
void encoder_roundtrip() {
    string original = "hello world\n";

    ofstream tmp("roundtrip_in.txt");
    tmp << original;
    tmp.close();

    HuffmanCoder hc;
    hc.encoder("roundtrip_in.txt", "roundtrip.zap");
    hc.decoder("roundtrip.zap", "roundtrip_out.txt");

    ifstream result("roundtrip_out.txt");
    ostringstream ss;
    ss << result.rdbuf();
    assert(ss.str() == original);
    result.close();
}