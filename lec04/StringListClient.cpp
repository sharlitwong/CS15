#include <iostream>
#include "stringlinkedlist.h"

using namespace std;

//i don't have makefile :( so i can't run this... 
int main(){
    StringLinkedList("alice");
    list.addAtFront("bob");
    list.addAtFront("sofia");

    list.insetrAt(0, "alex");
    list.insertAt(2, "joe");
    list.insertAt(list.size(), "stewart");

    list.printLoopily(); //should be sofia bob alice
    list.printRecursive(); //same

    return 0;
}