// Slip 2-B
// Implement a class for a Complex Number, overload the +, -, and * operators, and manage memory using dynamic allocation.

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

// Class to represent and manipulate complex numbers (a + bi)
class Complex 
{
private:
    float real; // Stores the real part
    float imag; // Stores the imaginary part

public:
    // Constructor: Runs automatically when an object is created.
    // It uses default arguments (0) if no values are provided.
    Complex(float r = 0, float i = 0) 
   {
        real = r;
        imag = i;
    }

    // OPERATOR OVERLOADING: This allows us to use the '+' symbol between objects.
    // Syntax: return_type operator symbol (arguments)
    Complex operator+(Complex c)
   {
        // Logic: Add real parts together and imaginary parts together
        return Complex(real + c.real, imag + c.imag);
    }

    // Overloading '-' operator
    Complex operator-(Complex c)
   {
        // Logic: Subtract real from real and imaginary from imaginary
        return Complex(real - c.real, imag - c.imag);
    }

    // Overloading '*' operator
    Complex operator*(Complex c) 
  {
        /* Math logic for multiplication:
           (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
        */
        float r = (real * c.real) - (imag * c.imag);
        float i = (real * c.imag) + (imag * c.real);
        return Complex(r, i);
    }

    // Function to print the number in standard format (e.g., 5 + 2i)
    void display()
  {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            // If imaginary is negative, it prints as 'a - bi'
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main()
{
    clrscr(); 

    // DYNAMIC MEMORY ALLOCATION:
    // Creating pointers to Complex objects
    Complex *c1, *c2, *c3;

    // 'new' allocates memory in the Heap at runtime
    c1 = new Complex(3, 2); // 3 + 2i
    c2 = new Complex(1, 7); // 1 + 7i

    cout << "First Complex Number: ";
    c1->display(); // Use '->' to call methods when using pointers

    cout << "Second Complex Number: ";
    c2->display();

    // Addition
    // We use '*' to dereference the pointers (get the actual values)
    c3 = new Complex(*c1 + *c2);
    cout << "\nAddition: ";
    c3->display();
    delete c3; // Freeing memory to avoid memory leaks

    // Subtraction
    c3 = new Complex(*c1 - *c2);
    cout << "Subtraction: ";
    c3->display();
    delete c3;

    // Multiplication
    c3 = new Complex(*c1 * *c2);
    cout << "Multiplication: ";
    c3->display();
    delete c3;

    // Final clean up for c1 and c2
    delete c1;
    delete c2;

    getch(); 
    return 0;
}