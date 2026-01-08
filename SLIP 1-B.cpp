// Slip 1-B
// Create a C++ program to simulate a basic calculator supporting expression parsing using function overloading and inline functions.

#include <iostream.h> // Standard input-output header for Turbo C++
#include <conio.h>    
#include <stdlib.h> 

// --- INLINE FUNCTIONS ---
// The 'inline' keyword suggests the compiler replace the function call 
// with the actual code to save time during execution.

// Function Overloading (Integer versions)
// The compiler chooses these when both arguments are 'int'.
inline int add(int a, int b) { return a + b; }
inline int subtract(int a, int b) { return a - b; }
inline int multiply(int a, int b) { return a * b; }
inline int divide(int a, int b) { return a / b; }

// Function Overloading (Float versions)
// The compiler chooses these when arguments are 'float'. 
// This is "Function Overloading" because the names are the same but types differ.
inline float add(float a, float b) { return a + b; }
inline float subtract(float a, float b) { return a - b; }
inline float multiply(float a, float b) { return a * b; }
inline float divide(float a, float b) { return a / b; }

// Logic to parse the user input and decide which overloaded function to call
void evaluateExpression()
 {
    float num1, num2;
    char op;

    cout << "Enter an expression (e.g., 3 + 4 or 3.5 * 2): ";
    // This reads a float, then a character (operator), then another float
    cin >> num1 >> op >> num2;

    // Check if the numbers are actually integers (no decimal part)
    if(num1 == (int)num1 && num2 == (int)num2)
  {
        // Typecasting floats to integers to trigger the 'int' version of functions
        int n1 = (int)num1;
        int n2 = (int)num2;
        
        switch(op) 
    {
            case '+': cout << "Result = " << add(n1, n2); break;
            case '-': cout << "Result = " << subtract(n1, n2); break;
            case '*': cout << "Result = " << multiply(n1, n2); break;
            case '/':
                if(n2 != 0) cout << "Result = " << divide(n1, n2);
                else cout << "Error: Division by zero!";
                break;
            default: cout << "Invalid operator!";
        }
    } 
    else 
  {
        // If decimals are present, the 'float' overloaded versions are called
        switch(op)
    {
            case '+': cout << "Result = " << add(num1, num2); break;
            case '-': cout << "Result = " << subtract(num1, num2); break;
            case '*': cout << "Result = " << multiply(num1, num2); break;
            case '/':
                if(num2 != 0) cout << "Result = " << divide(num1, num2);
                else cout << "Error: Division by zero!";
                break;
            default: cout << "Invalid operator!";
        }
    }
    cout << "\n";
}

void main() 
{
    clrscr(); 
    char choice;
    
    // Do-While loop to allow multiple calculations
    do
  {
        evaluateExpression();
        cout << "Do you want to calculate again? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    getch(); 
}