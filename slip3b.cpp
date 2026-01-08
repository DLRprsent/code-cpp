// Slip 3-B
// Create a pointer-based implementation of a class where objects are dynamically created and manipulated using the this pointer and constructors/destructors.

#include <iostream.h>
#include <conio.h>

class Student
{
private:
    int roll;
    float marks;

public:
    // PARAMETERIZED CONSTRUCTOR
    // This is called automatically when an object is created using 'new'
    Student(int roll, float marks)
  {
        // 'this' pointer refers to the current object's address.
        // It is used here to distinguish between class members (this->roll) 
        // and function parameters (roll).
        this->roll = roll;
        this->marks = marks;
        cout << "Object Created\n";
    }

    // Member function to display data
    void show()
  {
        cout << "Roll: " << roll << endl;
        cout << "Marks: " << marks << endl;
    }

    // DESTRUCTOR
    // This is called automatically when an object is destroyed using 'delete'
    // It starts with a tilde (~) symbol and has no return type.
    ~Student() 
  {
        cout << "Object Destroyed\n";
    }
};

int main() 
{
    clrscr();

    // Create a pointer to the Student class
    Student *s;

    // DYNAMIC MEMORY ALLOCATION
    // 'new' allocates memory on the Heap and calls the Constructor
    s = new Student(101, 85.5);

    // Calling the show function using the arrow operator (->)
    // Arrows are used instead of dots (.) for pointers
    s->show();

    // DYNAMIC DEALLOCATION
    // 'delete' frees the memory and calls the Destructor
    delete s;

    getch(); 
    return 0;
}