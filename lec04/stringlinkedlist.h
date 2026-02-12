#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

class StringLinkedList
{
public:
    StringLinkedList();
    ~StringLinkedList();

    void addAtFront(std::string elem);

    // Two approaches to printing:  
    void printLoopily();
    void printRecursive();

    // Many more to implement! addAtBack, elementAt, size, etc.
    void insertAt(int index, std::string data);
    void insertAt(int index, std::string elem);
    
private:
    struct Node {
        std::string  data;
        Node        *next;
    };

    Node *front;
    /* 
     * Could have other member variables if we wanted,
     * e.g., `int size` and a `Node *back` variables.
     * For today, we'll just use `front`. 
     */
    

    Node *newNode(std::string newData, Node *next);
    void printRecHelper(Node *curr);
    void recycleRecursive(Node *curr);
    Node *insertAtRecHelper(Node *curr, int index, std::string elem);
};

#endif