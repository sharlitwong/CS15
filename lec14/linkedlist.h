#include <iostream>

using namespace std;

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

template <typename ElemType>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    // Let's start by implementing the functions below.
    void addAtFront(ElemType elem);
    bool isEmpty();
    // We'll try two approaches to printing.
    void printLoopily();
    void printRecursive();

    // A fun way to print
    void printArtistically();
    
    // Many more to implement! addAtBack, elementAt, size, etc.
    void insertAt(int index, ElemType elem);
    
private:
    struct Node {
        ElemType  data;
        Node     *next;
    };

    Node *front;

    Node *newNode(ElemType newData, Node *next);
    bool isEmpty(Node *first);
    void printRecHelper(Node *curr,
			string separator = " ",
			string terminator = "\n");
    void recycleRecursive(Node *curr);
};


template <typename ElemType>
LinkedList<ElemType>::LinkedList()
{
    front = nullptr;
}

template <typename ElemType>
LinkedList<ElemType>::~LinkedList()
{
    recycleRecursive(front);
}

template <typename ElemType>
bool LinkedList<ElemType>::isEmpty(Node *first)
{
    return first == nullptr;
}

/* Helper function that creates a new node on the heap,
 * with data newData and next node as given next.
 * Notice: The return type needs scope resolution operator "::"
 * to know that Node comes from the LinkedList class.
 * The parameter does not!
 * Interestingly, the compiler insists on our writing "typename"
 * before LinkedList<ElemType>::Node.
 */
template <typename ElemType>
typename
LinkedList<ElemType>::Node *LinkedList<ElemType>::newNode(ElemType  newData,
							  Node     *next)
{
    Node *node = new Node;
    node->data = newData;
    node->next = next;
    return node;
}

template <typename ElemType>
void LinkedList<ElemType>::addAtFront(ElemType elem)
{
    front = newNode(elem, front);
}

template <typename ElemType>
void LinkedList<ElemType>::printLoopily()
{
    for (Node *curr = front; not isEmpty(curr); curr = curr->next) {
        cout << curr->data << " ";
    }
    cout << "\n";
}

template <typename ElemType>
void LinkedList<ElemType>::printRecursive()
{
    printRecHelper(front);
}

template <typename ElemType>
void LinkedList<ElemType>::printArtistically()
{
    printRecHelper(front, "~>", "@\n");
}

/* 
 * Print the list starting at curr with a separator following each
 * data item except the empty list, which is followed by terminator.
 * Note:  The last element still has separator after it, so maybe
 *        it's not really a separator...
 * separator defaults to a space: " "
 * terminator defaults to a newline:  "\n"
 */
template <typename ElemType>
void LinkedList<ElemType>::printRecHelper(Node *curr,
					  string separator,
					  string terminator)
{
    if (not isEmpty(curr)) {
        cout << curr->data << separator;
        printRecHelper(curr->next, separator, terminator);
    }
    else {
        cout << terminator;
    }
}

/* Helper function that recycles each 
 * node in the list beginnning at curr.
 */
template <typename ElemType>
void LinkedList<ElemType>::recycleRecursive(Node *curr)
{
    if (isEmpty(curr))
        return;
    recycleRecursive(curr->next);
    delete curr;
}

template <typename ElemType>
void LinkedList<ElemType>::insertAt(int index, ElemType elem)
{
    if (index == 0) {
        front = newNode(elem, front);
        return;
    }
    Node *curr = front;
    int curr_index = 0;
    while (curr_index < index - 1) {
        curr = curr->next;
        curr_index++;
    }
    curr->next = newNode(elem, curr->next);
}


#endif