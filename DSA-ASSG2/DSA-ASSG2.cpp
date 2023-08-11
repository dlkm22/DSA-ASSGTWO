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


static void createNewOrder(List foodList, Queue& customerQueue) {
    cout << "--Create New Order--" << endl;
    for (int i = 0; i < foodList.getLength(); i++) {
        cout << foodList.get(i) << endl;
    }
    int foodOption;
    cout << "Select food choice: ";
    cin >> foodOption;
    for (int i = 0; i < foodList.getLength(); i++) {
        if (i == (foodOption - 1)) {
            customerQueue.enqueue(foodList.get(i));
        }
    }
    string choice;
    cout << "Order More? [Y/N]: ";
    cin >> choice;
    if (choice == "Y" || choice == "y") {
        //createNewOrder(foodList, customerQueue);
        //add item to the same queue, how to call?

    }
    else {
        cout << "Thank you for ordering, your order will be ready soon!" << endl;
    }
}

bool updateStatus() {
    //parameter should have order to update
    //statuses - preparing, done
    return true;
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
        cout << "---------Menu---------\n[1] View incoming orders\n[2] Update Status of an order\n[3] View Customer information for an order\n[4] Create New Order\n[5] Cancel Order\n[6] Register New Account\n[7] Log Into Account\n[0] Exit\n----------------------" << endl;
        cout << "Select operation: ";
        cin >> option;

        if (option == 1) {
            cout << "--View Incoming Orders--" << endl;
            // if user is admin, allow to view incoming orders
            orderQueue.displayItems();
        }

        else if (option == 2) {
            cout << "--Update status of order--" << endl;
        }

        else if (option == 3) {
            cout << "--View customer information for an order--" << endl;
            string order;
            cout << "Which order would you like to view? : ";
            cin >> order;


        }
        
        else if (option == 4) { //changes
            cout << "--Create New Order--" << endl;
            for (int i = 0; i < foodList.getLength(); i++) {
                cout << foodList.get(i) << endl;
            }
            int foodOption;
            cout << "Select food choice: ";
            cin >> foodOption;
            for (int i = 0; i < foodList.getLength(); i++) {
                if (i == (foodOption - 1)) {
                    customerQueue.enqueue(foodList.get(i));
                    orderQueue.enqueue(foodList.get(i));
                }
            }
            
            
            //createNewOrder(foodList, customerQueue);
        }

        else if (option == 5) {
            cout << "--Cancel Order--" << endl;
            if (!customerQueue.isEmpty()) {
                cout << "Order cancelled successfully." << endl;
                customerQueue.dequeue();
            }
            else {
                cout << "No orders to cancel." << endl;
            }
        }

        else if (option == 6)
        {
            string newUsername;
            string newPassword;

            cout << "Input New Username:" << endl;
            cin >> newUsername;
            cout << "Input New Password:" << endl;
            cin >> newPassword; 

            accountDictionary.add(newPassword, newUsername);
        }

        else if (option == 7)
        {
            string username;
            string password;
            string retrievedUsername;

            cout << "Input your username:" << endl;
            cin >> username;
            cout << "Input your password:" << endl;
            cin >> password;

            retrievedUsername = accountDictionary.get(password);
            if (retrievedUsername == username)
            {
                cout << "Successfully Logged In" << endl;
            }
            else
            {
                cout << "Wrong password inputed." << endl;
            }
        }

        else if (option == 0) {
            cout << "Goodbye" << endl;
            break;
        }

        else if (option == 9) {
            accountDictionary.print();

        }

        else {
            cout << "Not a valid option! Please try again" << endl;
            continue;
        }


    }
}

