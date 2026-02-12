/*
 *  CharLinkedList.h
 *  Charlotte Wong (cwong22)
 *  January 28, 2026
 *
 *  CS 15 HW 2 Cheshire ConCATenation
 *
 *  This program implements a character linked list (CharLinkedList) class. 
 *  Creating a character linked list using this class yields a collection of 
 *  ordered characters that can be modified in numerous ways. After creation, 
 *  new characters can be added to the linked list at any location, conversely
 *  elements can be taken away from any location as well. Further flexibility
 *  is provided in that character linked lists can be concatenated without
 *  individually inserting each character, and character linked lists can be
 *  emptied without individually removing each character. Character linked lists
 *  can be printed (in default or reverse order) along with a basic message 
 *  regarding its length (number of characters), or simply accessing the length 
 *  without the object's contents is also possible with this class. Any 
 *  unintended uses of the methods in the class are mitigated through errors 
 *  with informative messages to inhibit undesirable behavior and help users 
 *  better use the program.
 *
 */

#include <stdexcept>
#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

class CharLinkedList {
    public:
        CharLinkedList();
        CharLinkedList(char c);
        CharLinkedList(char arr[], int size);
        CharLinkedList(const CharLinkedList &other);
        ~CharLinkedList();

        CharLinkedList &operator=(const CharLinkedList &other);

        bool isEmpty() const;
        void clear();
        int size() const;
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
        void concatenate(CharLinkedList *other);
    private:
        struct Node {
            char info;
            Node *next;
            Node *prev;
        };
        Node *front;
        Node *back;
        int numItems;
        Node *newNode(char c, Node *prev, Node *next);
        void recycleRecursive(Node *curr);
        void getStr(Node *start, std::string *str_p) const;
        void getRevStr(Node *start, std::string *str_p) const;
        Node *findElement(int index, Node *curr) const;
};

#endif
