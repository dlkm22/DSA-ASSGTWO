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
Customer customer;

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
                customer.setName(retrievedUsername);
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
        else if (option == 0)
        {
            cout << "Thank you for choosing WcDonalds" << endl; 
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }

    }
    return 0; // 0 Terminates the Program

}


int customerMenu(List foodList, List priceList)
{
    int option = -1;
    int ptsOption = -1;
    int loyaltyPts = 0;
    Order order;

    while (option != 0)
    {
        cout << "---Customer Menu---\n[1] Browse Food List \n[2] Create New Order\n[3] Cancel Order\n[4] Redeem Loyalty Points\n[0] Exit\n----------------------" << endl;
        cin >> option;
        if (option == 1)
        {
            cout << "----Food List----" << endl;
            foodList.print(); 
            cout << "------------" << endl;
        }

        else if (option == 2)
        {
            int RedemptionWcChicken;
            int RedemptionWoke;
            //Loyalty Pts are 1 to 1 
            loyaltyPts, RedemptionWcChicken, RedemptionWoke = order.createNewOrder(foodList, priceList, order, orderQueue, customer.freeWcChicken, customer.freeWokeZero);
            customer.addLoyaltyPts(loyaltyPts);
            if (RedemptionWcChicken == 0)
            {
                customer.freeWcChicken = 0;
            }
            if (RedemptionWoke == 0)
            {
                customer.freeWokeZero = 0;
            }

        }
        
        else if (option == 3)
        {
            order.cancelOrder(orderQueue);
        }

        else if (option == 4)
        {
            while (ptsOption != 0)
            {
                cout << "---Loyalty Point Redemption---" << endl;
                cout << "[1] Free WcChicken\n[2] Free Woke Zero\n[0] Exit Redemption Menu\nAll Rewards Cost 12 pts To Redeem\n You Have " << customer.loyaltyPoints << " loyalty points" << endl;
        
                cin >> ptsOption;
                if (ptsOption == 1 && (customer.loyaltyPoints >= 12))
                {
                    customer.removeLoyaltyPts(12);
                    cout << "Free WcChicken redeemed" << endl;
                    customer.freeWcChicken = true;
                }

                else if (ptsOption == 2 && (customer.loyaltyPoints >= 12))
                {
                    customer.removeLoyaltyPts(12);
                    cout << "Free Woke Zero redeemed" << endl;
                    customer.freeWokeZero = true;
                }

                else if (ptsOption == 0)
                {
                    break;
                }
                
                else 
                {
                    cout << "Invalid Input" << endl;
                }


            }
          

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
            cout << "Customer Name: " << customer.getName() << endl;
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

    List priceList;
    priceList.add("2");
    priceList.add("4");
    priceList.add("6");
    priceList.add("1");



    //foodList = populateFoodList(foodList);
    
  
    while (menu != 0)
    {
        menu = LoginMenu();
        if (menu == 1)
        {
            menu = staffMenu();
        }
        else if (menu == -1)
        {
            menu = customerMenu(foodList, priceList);
        }
    }
}

