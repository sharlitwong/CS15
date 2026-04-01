/*
 *  HuffmanCoder.h
 *  Charlotte Wong (cwong22)
 *  March 20th, 2026
 *
 *  CS 15 Project 3 zap
 *
 *  This program implements a HuffmanCoder class. A HuffmanCoder object
 *  created with this class provides Huffman coding functionality for
 *  compressing and decompressing ASCII text files. The encoder reads a
 *  text file, builds a Huffman tree from character frequencies, and writes
 *  a compressed binary file. The decoder reads a compressed binary file,
 *  reconstructs the Huffman tree, and writes the original text to an
 *  output file.
 */

#ifndef _HUFFMAN_CODER
#define _HUFFMAN_CODER
#include "ZapUtil.h"
#include "HuffmanTreeNode.h"
#include <iostream>
#include <map>

#include <string>

class HuffmanCoder {
    public:
    void encoder(const std::string &inputFile, const std::string &outputFile);
    void decoder(const std::string &inputFile, const std::string &outputFile);

    private:
    std::map<char, int> count_freqs(std::istream &text);
    std::string serialize_tree(HuffmanTreeNode *root);
    void deleteTree(HuffmanTreeNode *root);
    HuffmanTreeNode *deserialize_tree(const std::string &s);
    HuffmanTreeNode *deserialize_helper(const std::string &s, int &index);

    HuffmanTreeNode *buildTree(map<char, int> &freqs);
    void buildCodes(HuffmanTreeNode *root, string code, 
                                        map<char, string> &codes);
    std::string encodeText(std::istream &text,
                           std::map<char, std::string> &codes);

    std::string decodeText(const string &bits, HuffmanTreeNode *root);
    void saveToFile(const string &text, const string &output_file);
};

#endif