#include <iostream>
#include "Queue.h"
#include "List.h"
#include "Dictionary.h"
#include "Order.h"
#include "Customer.h"

using namespace std;
Dictionary accountDictionary;
List staffList;
List orderList;
Queue orderQueue;

int LoginMenu()
{
    int option = -1;



    while (option != 0)
    {
        cout << "---------Menu---------\n[1] Login \n[2] Register New Account[0] Exit\n----------------------" << endl;
        cin >> option;

        if (option == 1)
        {
            string username;
            string password;
            string retrievedUsername;

            cout << "Input your username:" << endl;
            cin >> username;
            cout << "Input your password:" << endl;
            cin >> password;



            retrievedUsername = accountDictionary.get(password, username);
            if (retrievedUsername == username)
            {
                cout << "Successfully Logged In" << endl;
                for (int i = 0; i < staffList.getLength(); i++)
                {
                    if (retrievedUsername == staffList.get(i))
                        return 1; // Returns 1 if staff account
                }
                return -1;  //Returns -1 if customer account
            }
            else
            {
                cout << retrievedUsername << endl;
            }
        }
        else if (option == 2)
        {
            string newUsername;
            string newPassword;
            string accountType;

            cout << "Input New Username:" << endl;
            cin >> newUsername;
            cout << "Input New Password:" << endl;
            cin >> newPassword;

            cout << "Input account type (Staff/Customer)" << endl;
            cin >> accountType;

            if (accountType == "Staff") //If the account is for a staff adds it to the stafflist
            {
                staffList.add(newUsername);
            }


            accountDictionary.add(newPassword, newUsername);
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }

    }
}


int customerMenu(List foodList)
{
    int option = -1;
    Order order;

    while (option != 0)
    {
        cout << "---------Menu---------\n[1] Browse Food List \n[2] Create New Order\n[3] Cancel Order\n[0] Exit\n----------------------" << endl;
        cin >> option;
        if (option == 1)
        {
            foodList.print(); 
        }

        else if (option == 2)
        {
            order.createNewOrder(foodList, order, orderQueue);
        }
        
        else if (option == 3)
        {
            order.cancelOrder(); 
        }

        else 
        {
            cout << "Invalid Input!" << endl;
        }
    }
    return -2; // logout  
}

void staffMenu()
{
    int option = -1;
    Order order;
    while (option != 0)
    {
        cout << "---------Menu---------\n[1] View Upcoming Orders \n[2] Update Status of Order\n[3] View Customer Information\n[0] Exit\n----------------------" << endl;
        cin >> option;

        if (option == 1)
        {
            cout << "--View Incoming Orders--" << endl;
            // if user is admin, allow to view incoming orders
            orderQueue.displayItems();
        }

        else if (option == 2)
        {
            cout << "--Update status of order--" << endl;
            order.displayAllItems();
            cout << "Current status: " << order.getStatus() << endl;
            order.updateStatus();
        }
        
        else if (option == 3)
        {
            cout << "--View customer information for an order--" << endl;
            orderQueue.displayItems(); // This is probably wrong
        }

    }

}

int main()
{
    int option = 1;
    Queue orderQueue; //for admin
    Queue customerQueue; //for customer 
    Order order;
    Customer customer;

    List foodList;
    foodList.add("[1] WcChicken");
    foodList.add("[2] WcSpicy");
    foodList.add("[3] BigWac");
    foodList.add("[4] Woke Zero");
    //foodList = populateFoodList(foodList);

    int staff = LoginMenu();
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
            order.displayAllItems();
            cout << "Current status: " << order.getStatus() << endl;
            order.updateStatus();
        }

        else if (option == 3) {
            cout << "--View customer information for an order--" << endl;
            orderQueue.displayItems();
           
        }
        
        else if (option == 4) { //havent implemented adding it to orderqueue for admin to see
            order.createNewOrder(foodList, order, orderQueue);
        }

        else if (option == 5) {
            order.cancelOrder();
        }

        else if (option == 6)
        {
            string newUsername;
            string newPassword;
            string accountType;

            cout << "Input New Username:" << endl;
            cin >> newUsername;
            cout << "Input New Password:" << endl;
            cin >> newPassword; 

            cout << "Input account type (Staff/Customer)" << endl;
            cin >> accountType; 

            if (accountType == "Staff")
            {
                staffList.add(newUsername);
            }


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

         

            retrievedUsername = accountDictionary.get(password, username);
            if (retrievedUsername == username)
            {
                cout << "Successfully Logged In" << endl;
            }
            else
            {
                cout <<  retrievedUsername  << endl;
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

