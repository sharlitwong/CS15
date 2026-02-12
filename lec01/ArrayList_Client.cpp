#include <iostream>
#include "IntArrayList.h"
using namespace std;

int main(){
    IntArrayList list1;
    IntArrayList list2(10, 175);

    cout << "List size should be 10 "  << list2.size() << endl;

    for(int i = 0; i < 100; i++) {
        list1.addAtBack(i*i);
    }

    cout << list1.size() << endl;
    return 0;

}