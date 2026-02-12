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

    // Destructor
    ~Person()
    {
        // cerr statement just for our own understanding
        cerr << "Destructor called." << endl;
        delete age;
    }

    // Overloaded assignment operator
    Person &operator=(const Person &rhs)
    {
        // cerr statement just for our own understanding
        cerr << "Assignment operator called." << endl;
        if (this == &rhs) {
            return *this;
        }

        *age = *rhs.age;
        name = rhs.name;
        return *this;        
    }

    Person(const Person &other)
    {
        // cerr statement just for our own understanding
        cerr << "Copy constructor called." << endl;
        age  = new int;
        *age = *other.age;
        name = other.name;
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
    {
	*age = newAge;
    }
    
private:
    // Just to see the different behavior,
    // let's let age be a pointer,
    // while name is a non-pointer.
    string  name;
    int    *age;
};

/* Example function to demonstrate the copy constructor.
 * As a result of calling this function, the copy constructor
 * will be called four times:
 * 1) To copy the given argument.
 * 2) To initialize coped_person1.
 * 3) To initialize copied_person2.
 * 4) To copy the returned value back to the caller.
 * Additionally, the destructor will be called 3 times,
 * for each of the Persons created in 1-3. 
 */
Person example_fun(Person input) //1
{
    Person copied_person1(input); //copy constructor called 2 (destructor)
    Person copied_person2 = input; //copy constructor called 3 (destructor)
    return input; //4 (destructor)
}

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

    // let's test out the copy constructor
    Person p3 = example_fun(p1);
    return 0;
}