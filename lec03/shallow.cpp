#include <iostream>

using namespace std;

class Person {
public:
    Person()
    {
        name = "";
        age  = new int;
        *age = -1;
    }

    Person(string newName, int newAge)
    {
        name = newName;
        age  = new int;
        *age = newAge;
    }

    void print()
    {
	cout << name << " is " << *age << " years old." << endl;
    }
    void setName(string newName)
    {
	name = newName;
    }
    void setAge(int newAge)
    { *age = newAge;
    }

private:
    // Just to see the different behavior,
    // let's let age be a pointer,
    // while name is a non-pointer.
    string  name;
    int    *age;
};


int main()
{
    Person p1("Alice", 30);
    p1.print();

    // let's play with assignment
    Person p2;
    p2 = p1;
    p2.setName("Carol");
    p2.setAge(40);

    // what prints now?
    cout << "After assignment: " << endl;
    p1.print();
    p2.print();
    
    return 0;
}