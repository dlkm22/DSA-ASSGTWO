#include "Order.h"
#include "List.h"
#include <iostream>
using namespace std;

//how to add items to order? do I need a add method? do I use a queue?

Order::Order() {
	//List newOrder;
}

bool Order::add(ItemType item) {
	List newOrder;
	newOrder.add(item);
	return true;
}

string Order::updateStatus(Order& order) {
	bool ready;
	string status = "Order Received";

	string option;
	cout << "What would you like to update status to? [P/COM/CAN]: ";
	cin >> option;

	if (option == "P" || option == "p") {
		status = "Preparing";
		ready = false;
	}

	else if (option == "COM" || option == "com") {
		status = "Completed";
		ready = true;
	}

	else if (option == "CAN" || option == "Cancelled") {
		status = "Cancelled";
		ready = false;
	}

	return status;
}

void Order::displayAllItems() {
	List newOrder;
	newOrder.print();
}

