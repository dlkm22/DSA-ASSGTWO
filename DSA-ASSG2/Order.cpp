#include "Order.h"
#include "List.h"
#include <iostream>
using namespace std;

//how to add items to order? do I need a add method? do I use a queue?

Order::Order() {

}

bool Order::add(ItemType item) {
	newOrder.add(item);
	return true;
}

string Order::updateStatus() {
	bool ready;

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

	else if (option == "0") {
		cout << "Cancelled operation." << endl;
	}

	else {
		cout << "Not a valid option, please try again. If you want to cancel, enter 0.";
	}

	return status;
}

string Order::getStatus() {
	return status;
}

void Order::displayAllItems() {
	newOrder.print();
}

