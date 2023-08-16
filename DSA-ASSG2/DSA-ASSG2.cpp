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
        cout << "-----Login Menu-------\n[1] Login \n[2] Register New Account\n[0] Exit Program\n----------------------" << endl;
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
    return 0; // 0 Terminates the Program

}


int customerMenu(List foodList)
{
    int option = -1;
    Order order;

    while (option != 0)
    {
        cout << "---Customer Menu---\n[1] Browse Food List \n[2] Create New Order\n[3] Cancel Order\n[0] Exit\n----------------------" << endl;
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

        else if (option == 0)
        {
            cout << "Logout Successful" << endl;
        }

        else 
        {
            cout << "Invalid Input!" << endl;
        }
    }
    return -2; // logout  
}

int staffMenu()
{
    int option = -1;
    Order order;
    while (option != 0)
    {
        cout << "------Staff Menu------\n[1] View Upcoming Orders \n[2] Update Status of Order\n[3] View Customer Information\n[0] Logout\n----------------------" << endl;
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

        else if (option == 0)
        {
            cout << "Logout Successful" << endl;
        }
        
        else
        {
            cout << "Invalid Input" << endl; 
        }

    }
    return -2; 


}

int main()
{
    int option = 1;
    Queue orderQueue; //for admin
    Queue customerQueue; //for customer 
    Order order;
    Customer customer;
    int menu = -1;

    List foodList;
    foodList.add("[1] WcChicken");
    foodList.add("[2] WcSpicy");
    foodList.add("[3] BigWac");
    foodList.add("[4] Woke Zero");
    //foodList = populateFoodList(foodList);
    
  
    while (menu != 0)
    {
        menu = LoginMenu();
        if (menu == 1)
        {
            menu = staffMenu();
        }
        else
        {
            menu = customerMenu(foodList);
        }
    }
}

