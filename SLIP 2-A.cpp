// Slip 2-A
// Write a menu-driven program using control structures to simulate a student grading system with support for conditional and looping constructs.

#include <iostream.h>
#include <conio.h>  

// Function to determine the grade based on marks
char calculateGrade(float marks)
 {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else if (marks >= 50) return 'E';
    else return 'F';
}

void main() 
{
    int choice;
    int numStudents;
    float marks;
    clrscr(); 

    do
  {       
        cout << "\n===== STUDENT GRADING SYSTEM =====";
        cout << "\n1.Enter Marks for Single Student";
        cout << "\n2.Enter Marks for Multiple Students";
        cout << "\n3.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) 
    {
            case 1:
                // Logic for one student
                cout << "Enter marks (0-100): ";
                cin >> marks;
                
                if (marks < 0 || marks > 100) {
                    cout << "Invalid marks!" << endl;
                } else {
                    cout << "Grade: " << calculateGrade(marks) << endl;
                }
                break;

            case 2:
                // Logic for a group of students using a loop
                cout << "How many students? ";
                cin >> numStudents;
                
                for (int i = 1; i <= numStudents; i++)
               {
                    cout << "Marks for student " << i << ": ";
                    cin >> marks;
                    
                    if (marks < 0 || marks > 100)
                 {
                        cout << "Invalid marks!" << endl;
                    } else
                       {
                        cout << "Grade: " << calculateGrade(marks) << endl;
                    }
               }
                break;

            case 3:
                cout << "Exiting system..." << endl;
                break;

            default:
                cout << "Wrong choice! Try again." << endl;
        }
   } 
     while(choice != 3); 

    getch();
}