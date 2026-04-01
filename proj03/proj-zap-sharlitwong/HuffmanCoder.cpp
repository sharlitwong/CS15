
/*
 *  HuffmanCoder.cpp
 *  Charlotte Wong (cwong22)
 *  March 20th, 2026
 *
 *  CS 15 Project 3 zap
 *
 *  File purpose:
 *  This file contains the implementation of the Huffman Coder Class
 *
 */
#include "HuffmanCoder.h"
using namespace std;
#include <queue>
#include <vector>
#include <fstream>

/*
 * name:      count_freqs(std::istream &text)
 * purpose:   reads an input of text and records frequency counts of all unique
 *            characters
 * arguments: input stream from whuch function reads text
 * returns:   map holding all characters present and their respective counts in
 *            the given input stream
 * effects:   frequencies of all characters present are recorded in the map
 *            where c is some character, and x is the corresponding count
 * other:     none
 */
map<char, int> HuffmanCoder::count_freqs(istream &text) {
    char c;
    map<char, int> freqs;
    while(text.get(c)) {
        freqs[c]++;
    }
    return freqs;
}

/*
 * name:      serialize_tree(HuffmanTreeNode *root)
 * purpose:   create a serial representation of a HuffmanTree
 * arguments: pointer to a tree node at which to start serializing
 * returns:   string serialization of the tree
 * effects:   string representing serialized tree returned
 * other:     none
 */
string HuffmanCoder::serialize_tree(HuffmanTreeNode *root) {
    string str = "";
    if(root == nullptr) {
        return str;
    } 

    if(root -> is_leaf()) {
        str += "L";
        str += root -> get_val();
    } else { //internal node
        str += "I";
        str += serialize_tree(root -> get_left());
        str += serialize_tree(root -> get_right());
    }
    return str;
}

/*
 * name:      deleteTree(HuffmanTreeNode *root) 
 * purpose:   delete tree starting at a given node
 * arguments: node pointer to node at which to start deleting 
 * returns:   none
 * effects:   memory associated with tree starting at given pointer recycled
 * other:     none
 */
void HuffmanCoder::deleteTree(HuffmanTreeNode *root) {
    if(root == nullptr) return;
    deleteTree(root -> get_left());
    deleteTree(root -> get_right());
    delete root;
}

/*
 * name:      deserialize_tree(const std::string &s) 
 * purpose:   create a tree from its serialized representation
 * arguments: string representation of some Huffman Tree
 * returns:   pointer to root node of created tree
 * effects:   Huffman tree created from serialized representation
 * other:     none
 */
HuffmanTreeNode *HuffmanCoder::deserialize_tree(const string &s) {
    int i = 0;
    return deserialize_helper(s, i);
}

/*
 * name:      deserialize_helper(const string &s, int &index)
 * purpose:   recursively read the string representation of a Huffman Tree &
 *            create corresponding nodes
 * arguments: string representation of Huffman tree, index of string in which 
 *            function is to create a node based off of
 * returns:   node pointer to root of created tree
 * effects:   Huffman Tree created from serial representation
 * other:     none
 */
HuffmanTreeNode *HuffmanCoder::deserialize_helper(const string &s, int &index) {
    char curr = s[index];
    index++;

    if(curr == 'L') {
        char val = s[index];
        index++;
        return new HuffmanTreeNode(val);
    } else { //internal node
        HuffmanTreeNode *left = deserialize_helper(s, index);
        HuffmanTreeNode *right = deserialize_helper(s, index);
        return new HuffmanTreeNode(left, right);
    }
}

/*
 * name:      buildTree(map<char, int> &freqs)
 * purpose:   uses the map of characters and their corresponding frequencies to
 *            create the corresponding Huffman Tree
 * arguments: map filled with characters and their corresponding frequencies
 * returns:   HuffmanTreeNode pointer to the root of the Huffman Tree
 * effects:   HuffmanTree created from the map of characters and their 
 *            frequencies
 * other:     none
 */
HuffmanTreeNode *HuffmanCoder::buildTree(map<char, int> &freqs) {
    priority_queue<HuffmanTreeNode*, 
                   vector<HuffmanTreeNode*>, 
                   NodeComparator> pq;
    for(auto &pair: freqs) { //propagate priority queue with nodes
        pq.push(new HuffmanTreeNode(pair.first, pair.second));
    }

    if(pq.size() == 1) { //only one unique character
        HuffmanTreeNode *only = pq.top(); pq.pop();
        HuffmanTreeNode *dummy = new HuffmanTreeNode('\0', 0);
        return new HuffmanTreeNode(only->get_freq(), only, dummy);
    }

    //combine two lowest frequency nodes until one tree remains
    while (pq.size() > 1) {
        HuffmanTreeNode *left = pq.top(); pq.pop();
        HuffmanTreeNode *right = pq.top(); pq.pop();
        int combined = left->get_freq() + right->get_freq();
        pq.push(new HuffmanTreeNode(combined, left, right));
    }

    return pq.top();
}

/*
 * name:      buildCodes(HuffmanTreeNode *root, string code,
 *                        map<char, string> &codes)
 * purpose:   recursively traverse the Huffman tree, building the binary
 *            string code for each character at each leaf
 * arguments: pointer to current node, code string built so far,
 *            map to store each character's final code
 * returns:   none
 * effects:   codes map populated with a binary string for each character
 * other:     none
 */
void HuffmanCoder::buildCodes(HuffmanTreeNode *root, string code,
                                map<char, string> &codes) {
    if (root == nullptr) return;

    //at leaf, record the character's code
    if (root->is_leaf()) {
        codes[root->get_val()] = code;
        return;
    }

    //go left, append "0"
    buildCodes(root->get_left(),  code + "0", codes);
    //go right, append "1"
    buildCodes(root->get_right(), code + "1", codes);
}

/*
 * name:      encodeText(istream &text, map<char, string> &codes)
 * purpose:   encode input text into a binary string using the provided
 *            character codes
 * arguments: input stream to read from, map of characters to binary codes
 * returns:   string of 0s and 1s representing the encoded text
 * effects:   none
 * other:     none
 */
string HuffmanCoder::encodeText(istream &text, map<char, string> &codes) {
    string encoded = "";
    char c;
    while (text.get(c)) {
        encoded += codes[c];
    }
    return encoded;
}

/*
 * name:      encoder(const string &input_file, const string &output_file)
 * purpose:   compress a text file using Huffman coding and save to output file
 * arguments: input_file - name of the text file to compress
 *            output_file - name of the file to write compressed output to
 * returns:   none
 * effects:   creates a compressed binary file at output_file, prints success
 *            message with bit count to cout
 * other:     throws runtime_error if input_file cannot be opened
 *            prints message to cout and returns if input_file is empty
 */
void HuffmanCoder::encoder(const string &input_file, 
                           const string &output_file) {
    ifstream input(input_file); //open input file
    if (not input.is_open()) {
        throw runtime_error("Unable to open file " + input_file);
    }

    map<char, int> freqs = count_freqs(input); //count char frequencies
    if (freqs.empty()) {
        cout << input_file << " is empty and cannot be compressed." << endl;
        return;
    }

    //build tree, generate codes
    HuffmanTreeNode *root = buildTree(freqs);
    map<char, string> codes;
    buildCodes(root, "", codes);

    //reopen to encode text (stream was exhausted)
    input.clear();
    input.seekg(0);
    string encoded = encodeText(input, codes);
    input.close();

    //serialize tree and write zap file
    string serialized = serialize_tree(root);
    writeZapFile(output_file, serialized, encoded);

    cout << "Success! Encoded given text using " << encoded.size() 
         << " bits." << endl;

    deleteTree(root);
}

/*
 * name:      decodeText(const string &bits, HuffmanTreeNode *root)
 * purpose:   decode a binary string back into ASCII text using the Huffman tree
 * arguments: binary string of 0s and 1s, pointer to root of Huffman tree
 * returns:   decoded ASCII string
 * effects:   none
 * other:     throws runtime_error if bits end mid-tree (not at a leaf)
 */
string HuffmanCoder::decodeText(const string &bits, HuffmanTreeNode *root) {
    string decoded = "";
    HuffmanTreeNode *curr = root;

    //single unique character edge case: root is a leaf
    if (root->is_leaf()) {
        for (size_t i = 0; i < bits.size(); i++) {
            decoded += root->get_val();
        }
        return decoded;
    }

    for (size_t i = 0; i < bits.size(); i++) {
        if (bits[i] == '0') {
            curr = curr->get_left();
        } else {
            curr = curr->get_right();
        }

        if (curr->is_leaf()) {
            decoded += curr->get_val();
            curr = root; //go back to root for next character
        }
    }

    //if we're not back at root, bits ended mid-tree
    if (curr != root) {
        throw runtime_error("Encoding did not match Huffman tree.");
    }

    return decoded;
}

/*
 * name:      saveToFile(const string &text, const string &output_file)
 * purpose:   write decoded text to an output file
 * arguments: decoded text string, output filename
 * returns:   none
 * effects:   creates/overwrites output file with decoded text
 * other:     none
 */
void HuffmanCoder::saveToFile(const string &text, const string &output_file) {
    ofstream out(output_file);
    if (not out.is_open()) {
        throw runtime_error("Unable to open file " + output_file);
    }
    out << text;
    out.close();
}

/*
 * name:      decoder(const string &input_file, const string &output_file)
 * purpose:   decompress a zapped file and save the resulting text to output 
 *            file
 * arguments: input_file (name of the compressed binary file to decompress)
 *            output_file (name of the file to write decompressed text to)
 * returns:   none
 * effects:   creates a text file at output_file containing the original text
 * other:     throws runtime_error if encoding did not match Huffman tree
 */
void HuffmanCoder::decoder(const string &input_file, 
                           const string &output_file) {
    pair<string, string> zap_contents = readZapFile(input_file);
    string serialized = zap_contents.first;
    string bits = zap_contents.second;

    HuffmanTreeNode *root = deserialize_tree(serialized);
    string decoded = decodeText(bits, root);
    saveToFile(decoded, output_file);

    deleteTree(root);
}
