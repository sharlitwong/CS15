#ifndef __PHASEONE_H
#define __PHASEONE_H

#include <istream>
#include <string>

#include "ZapUtil.h"

void count_freqs(std::istream &text);
std::string serialize_tree(HuffmanTreeNode *root);
void deleteTree(HuffmanTreeNode *root);
HuffmanTreeNode *deserialize_tree(const std::string &s);
HuffmanTreeNode *deserialize_helper(const string &s, int &index);

#endif