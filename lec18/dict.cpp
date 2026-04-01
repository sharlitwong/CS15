#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <stdexcept>

using namespace std;

const int LETTERS = 26;

// For Brevity, we'll keep everything in one file.
class Dictionary {
public:
    Dictionary() { // constructor
        hashTable = new string[LETTERS * LETTERS];
    }
    ~Dictionary() { // destructor
        delete [] hashTable;
    }
    void insert(string word, string def) {
        hashTable[hashCode(word)] = def;
    }

    string find(string word) {
        return hashTable[hashCode(word)];
    }
private:
    string *hashTable;

    int hashCode(string word) {
        if (word.length() != 2) {
            throw runtime_error("Expected 2-letter word, received: " + word);
        }

        /* Under the hood in C++, chars are really just ints corresponding to
         * the char's ASCII code. The first char in the ASCII table is 'a'.
         * So by subtracting a lower-case letter by 'a', we translate all
         * letters to the range 0-25. 
         */
        return LETTERS * (tolower(word[0]) - 'a') + (tolower(word[1]) - 'a');
        //tolower makes it lower case i'm guessing
    }
};


int main()
{
    Dictionary dict;

    dict.insert("hi", "a greeting");
    dict.insert("ox", "a bovine creature");
    dict.insert("go", "leave");

    cout << "The definition of \"ox\" is \"" << dict.find("ox") << ".\"\n";

    return 0;
}