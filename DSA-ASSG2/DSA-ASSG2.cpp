#include <iostream>
#include "Queue.h"
using namespace std;


int main()
{
    int option = 1;

    while (option != 0) {
        cout << "Select operation: ";
        cin >> option;

        if (option == 1) {
            cout << "View Incoming Orders" << endl;
        }

        else if (option == 2) {
            cout << "Update status of order" << endl;
        }

        else if (option == 3) {
            cout << "View customer information for an order" << endl;
        }

        else if (option == 0) {
            cout << "Goodbye" << endl;
            break;
        }

        else {
            cout << "Not a valid option! Please try again" << endl;
            continue;
        }


    }
}

