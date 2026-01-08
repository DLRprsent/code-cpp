// Slip 1-A
// Design a mini ATM interface that simulates balance inquiry, deposit, and withdrawalusing encapsulation and basic C++ constructs.


#include<iostream.h>
#include<conio.h>

//(Encapsulation: wrapping data and functions together)
class ATM
{
public:
    int bal; // Data Member: Stores the account balance

    // Constructor: Initializes the balance when the object is created
    ATM(float initialbal)
    {
        bal = initialbal;
    }

    // Member Function: Displays the current balance
    void inquiry()
    {
        cout << "current balance:" << bal << endl;
    }

    // Member Function: Adds money to the balance if amount is valid
    void deposite(float amt)
    {
        if(amt > 0)
        {
            bal += amt;
            cout << "amount deposited:" << amt << endl;
            cout << "Current Balance:" << bal << endl;
        }
        else
        {
            cout << "invalid amount\n";
        }
    }

    // Member Function: Subtracts money from balance after checking funds
    void withdraw(float amt)
    {
        if(amt > bal)
        {
            cout << "Insufficient Balance" << endl;
        }
        else
        {
            bal -= amt;
            cout << "Amount Withdraw:" << amt << endl;
            cout << "Current Balance:" << bal << endl;
        }
    }
};

void main()
{
    int ch, b;     // Variables for choice and transaction amount
    float inbal;   // Variable for the very first balance input
    
    clrscr();     

    cout << "Enter initial bal." << endl;
    cin >> inbal;

    // Creating an Object 'a' of class ATM (Instance of the class)
    ATM a(inbal);

    // Infinite loop to keep the ATM menu running until Exit is chosen
    while(1)
    {
        cout << "\n1.Balance Enquiry." << endl;
        cout << "2.Deposite Balance." << endl;
        cout << "3.Withdraw Balance." << endl;
        cout << "4.Exit" << endl;
        cout << "Enter Your Choice:";
        cin >> ch;

        switch(ch)
        {
            case 1:
                a.inquiry(); // Call inquiry function
                break;
            case 2:
                cout << "Enter Ammont to Deposite:";
                cin >> b;
                a.deposite(b); // Call deposit function
                break;
            case 3:
                cout << "Enter Amount to Withdrawal:";
                cin >> b;
                a.withdraw(b); // Call withdraw function
                break;
            case 4:
                cout << "Exiting";
                return;
                break;
            default:
                cout << "Invalid Choice";
                break;
        }
    }
    getch(); 
}