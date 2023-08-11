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

/*
bool Customer::addOrder(Order& order) {

}
*/


