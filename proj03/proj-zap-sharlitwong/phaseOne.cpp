#include <iostream>
#include "HuffmanTreeNode.h"
#include <map>
#include "phaseOne.h"
using namespace std;

/*
 * name:      count_freqs(std::istream &text)
 * purpose:   reads an input of text and records frequency counts of all unique
 *            characters
 * arguments: input stream from whuch function reads text
 * returns:   none
 * effects:   frequencies of all characters present are printed in the format:
 *            c: x
 *            where c is some character, and x is the corresponding count
 * other:     none
 */
void count_freqs(istream &text) {
    char c;
    map<char, int> freqs;
    while(text.get(c)) {
        freqs[c]++;
    }
    for(auto &pair: freqs) {
        cout << pair.first << ": " << pair.second << "\n";
    } 
}

/*
 * name:      string serialize_tree(HuffmanTreeNode *root)
 * purpose:   create a serial representation of a HuffmanTree
 * arguments: pointer to a node at which to start serializing
 * returns:   string serialization of the tree
 * effects:   string representing serialized tree returned
 * other:     none
 */
string serialize_tree(HuffmanTreeNode *root) {
    string str = "";
    if(root == nullptr) {
        return str;
    } 
    //process
    if (root -> is_leaf()) {
        str += "L";
        str += root -> get_val();
    } else {
        str += "I";
        //left
        str += serialize_tree(root -> get_left());
        //right
        str += serialize_tree(root -> get_right());
    }
    return str;
}

/*
 * name:      void deleteTree(HuffmanTreeNode *root) 
 * purpose:   delete tree starting at a given node
 * arguments: node pointer to node at which to start deleting 
 * returns:   none
 * effects:   memory associated with tree starting at given pointer recycled
 * other:     none
 */
void deleteTree(HuffmanTreeNode *root) {
    if(root == nullptr) return;
    //left
    deleteTree(root -> get_left());
    //right
    deleteTree(root -> get_right());
    //current
    delete root;
}

/*
 * name:      HuffmanTreeNode *deserialize_tree(const std::string &s) 
 * purpose:   create a tree from its serialized representation
 * arguments: string representation of some Huffman Tree
 * returns:   pointer to root node of created tree
 * effects:   Huffman tree created from serialized representation
 * other:     none
 */
HuffmanTreeNode *deserialize_tree(const string &s) {
    int i = 0;
    return deserialize_helper(s, i);
}

/*
 * name:      HuffmanTreeNode *deserialize_helper(const string &s, int &index)
 * purpose:   recursively read the string representation of a Huffman Tree &
 *            create corresponding nodes
 * arguments: string representation of Huffman tree, index of string in which 
 *            function is to create a node based off of
 * returns:   node pointer to root of created tree
 * effects:   Huffman Tree created from serial representation
 * other:     none
 */
HuffmanTreeNode *deserialize_helper(const string &s, int &index) {
    char curr = s[index];
    index++;

    if(curr == 'L') {
        char val = s[index];
        index++;
        return new HuffmanTreeNode(val);
    } else { //not leaf
        HuffmanTreeNode *left = deserialize_helper(s, index);
        HuffmanTreeNode *right = deserialize_helper(s, index);
        return new HuffmanTreeNode(left, right);
    }
}