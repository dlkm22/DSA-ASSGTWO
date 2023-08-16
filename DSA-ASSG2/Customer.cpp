#include "Customer.h"
#include "Order.h"
#include <iostream>
#include <string>
using namespace std;

Customer::Customer() {}

Customer::Customer(string n) {
	name = n;
}

void Customer::setName(string n) {
	name = n;
}

string Customer::getName() {
	return name;
}

void Customer::getLoyaltyPts()
{
	cout << "Your current loyalty point total is: " << loyaltyPoints << endl;
}



void Customer::addLoyaltyPts(int addedPts)
{
	loyaltyPoints += addedPts;
}

