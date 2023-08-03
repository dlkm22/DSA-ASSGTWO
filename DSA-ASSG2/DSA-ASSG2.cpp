#include <iostream>
#include "Queue.h"
#include "List.h"
using namespace std;

List populateFoodList(List foodList) {
    foodList.add("WcChicken");
    foodList.add("WcSpicy");
    foodList.add("BigWac");
    foodList.add("Woke Zero");
    return foodList;
}

int main()
{
    int option = 1;
    Queue orderQueue; //for admin
    Queue customerQueue; //for customer

    List foodList;
    foodList.add("WcChicken");
    foodList.add("WcSpicy");
    foodList.add("BigWac");
    foodList.add("Woke Zero");
    //foodList = populateFoodList(foodList);


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
        
        else if (option == 4) { //changes
            cout << "Create New Order" << endl;
            for (int i = 0; i < foodList.getLength(); i++) {
                cout << foodList.get(i) << endl;
            }
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

