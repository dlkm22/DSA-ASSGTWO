#include <iostream>
#include "Queue.h"
#include "List.h"
#include "Dictionary.h"

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
    Dictionary accountDictionary;

    List foodList;
    foodList.add("[1] WcChicken");
    foodList.add("[2] WcSpicy");
    foodList.add("[3] BigWac");
    foodList.add("[4] Woke Zero");
    //foodList = populateFoodList(foodList);


    while (option != 0) {
        cout << "---------Menu---------\n[1] View incoming orders\n[2] Update Status of an order\n[3] View Customer information for an order\n[4] Create New Order\n[5] Register New Account\n[0] Exit\n----------------------" << endl;
        cout << "Select operation: ";
        cin >> option;

        if (option == 1) {
            cout << "--View Incoming Orders--" << endl;
            customerQueue.displayItems();
        }

        else if (option == 2) {
            cout << "--Update status of order--" << endl;
        }

        else if (option == 3) {
            cout << "--View customer information for an order--" << endl;
        }
        
        else if (option == 4) { //changes
            cout << "--Create New Order--" << endl;
            for (int i = 0; i < foodList.getLength(); i++) {
                cout << foodList.get(i) << endl;
            }
            int foodOption;
            cout << "Select food choice: ";
            cin >> foodOption;
            if (foodOption == 1) {
                customerQueue.enqueue(foodList.get(0));
            }

            if (foodOption == 2) {
                customerQueue.enqueue(foodList.get(1));
            }

            if (foodOption == 3) {
                customerQueue.enqueue(foodList.get(2));
            }

            if (foodOption == 4) {
                customerQueue.enqueue(foodList.get(3));
            }
        }
        else if (option == 5)
        {
            string newUsername;
            string newPassword;

            cout << "Input New Username:" << endl;
            cin >> newUsername;
            cout << "Input New Password:" << endl;
            cin >> newPassword; 

            accountDictionary.add(newPassword, newUsername); 




         

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

