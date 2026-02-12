/*
 *  CharArrayList.h
 *  Charlotte Wong
 *  January 20, 2026
 *
 *  COMP 15 HW 1 Cheshire ConCATenation 
 *
 *  File purpose:
 * 
 *  This program implements a character array list (CharArrayList) class. 
 *  Creating a character array list using this class yields a collection of 
 *  ordered characters that can be modified in numerous ways. After creation, 
 *  new characters can be added to the array last at any location, conversely
 *  elements can be taken away from any location as well. Further flexibility
 *  is provided in that character array lists can be concatenated without
 *  individually inserting each character, and character array lists can be
 *  emptied without individually removing each character. Character array lists 
 *  can be printed (in default or reverse order) along with a basic message 
 *  regarding its length (number of characters), or simply accessing the length 
 *  without the object's contents is also possible with this class. Any 
 *  unintended uses of the methods in the class are mitigated through errors 
 *  with informative messages to inhibit undesireable behavior and help users 
 *  better use the program.
 *
 */
#ifndef CHAR_ARRAY_LIST_H
#define CHAR_ARRAY_LIST_H
#include <stdexcept>

class CharArrayList {
    public:
        CharArrayList();
        CharArrayList(char c);
        CharArrayList(char arr[], int size);
        CharArrayList(const CharArrayList &other); 
        ~CharArrayList();

        CharArrayList &operator=(const CharArrayList &other);

        bool isEmpty() const;
        int size() const;
        void clear();
        char first() const;
        char last() const;
        char elementAt(int index) const;
        std::string toString() const;
        std::string toReverseString() const;
        void pushAtBack(char c);
        void pushAtFront(char c);
        void insertAt(char c, int index);
        void insertInOrder(char c);
        void popFromFront();
        void popFromBack();
        void removeAt(int index);
        void replaceAt(char c, int index);
        void concatenate(CharArrayList *other);

    private:
        int numItems; 
        int capacity; 
        char *buffer; 
        void expand();
        std::string justString() const;
        std::string intToString(int num) const;
        std::string justReverseString() const;
        void shiftforward(int start);
        void shiftbackward(int start);
};

#endif
