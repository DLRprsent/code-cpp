// Slip 3-A
// Design a class for a Student Database that allows the addition, deletion, and search of student records using static members and friend functions.

#include <iostream.h>
#include <conio.h>
#include <string.h>

// Forward Declaration: Tells the compiler these functions exist before they are defined
class Student;
void searchStudent(Student *s, int n, int r);
void deleteStudent(Student *s, int &n, int r);

class Student 
{
private:
    int roll;      // Private data: only accessible by class members or friends
    char name[30];

public:
    // STATIC MEMBER: Shared by all objects of the class to keep a global count
    static int count;

    // Member function to take input
    void getData()
  {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        count++; // Increment static counter whenever a new student is added
    }

    // Member function to output data
    void showData()
   {
        cout << roll << "\t" << name << endl;
    }

    // FRIEND FUNCTIONS: Declared inside but defined outside. 
    // They can access 'roll' and 'name' even though those are private.
    friend void searchStudent(Student *s, int n, int r);
    friend void deleteStudent(Student *s, int &n, int r);
};

// Definition of static member (required to allocate memory outside the class)
int Student::count = 0;

// Search Logic: Iterates through the array to find a matching roll number
void searchStudent(Student *s, int n, int r)
 {
    for (int i = 0; i < n; i++)
   {
        if (s[i].roll == r)
      { // Accessing private member 'roll' via friend status
            cout << "Record Found\n";
            cout << "Roll\tName\n";
            s[i].showData();
            return;
        }
    }
    cout << "Record Not Found\n";
}

// Delete Logic: Finds the record and shifts all subsequent records to the left
void deleteStudent(Student *s, int &n, int r)
  {
    for (int i = 0; i < n; i++) 
   {
        if (s[i].roll == r)
      {
            // LOOP FOR SHIFTING: Overwrites the current index with the next one
            for (int j = i; j < n - 1; j++)
         {
                s[j] = s[j + 1];
           }
            n--;              // Reduce the current index count
            Student::count--; // Reduce the total static count
            cout << "Record Deleted\n";
            return;
        }
    }
    cout << "Record Not Found\n";
}

int main()
{
    clrscr(); 
    Student s[20]; // Array of objects
    int n = 0, choice, roll;

    do 
  {
        cout << "\n1.Add \n2.Display \n3.Search \n4.Delete \n5.Exit\n";
        cout << "Current Students: " << Student::count << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) 
     {
            case 1:
                if (n < 20)
          {
                    s[n].getData();
                    n++;
                } else
            {
                    cout << "Array Full!";
             }
                break;
            case 2:
                cout << "Roll\tName\n";
                for (int i = 0; i < n; i++)
                    s[i].showData();
                break;
            case 3:
                cout << "\nEnter Roll to Search: ";
                cin >> roll;
                searchStudent(s, n, roll);
                break;
            case 4:
                cout << "\nEnter Roll to Delete: ";
                cin >> roll;
                deleteStudent(s, n, roll);
                break;
        }
    } while (choice != 5);

    getch();
    return 0;
}