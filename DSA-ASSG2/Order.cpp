#include "Order.h"
#include "List.h"
#include <iostream>
using namespace std;

//how to add items to order? do I need a add method? do I use a queue?

Order::Order() {
	sizeOfOrderList = 0;
}

bool Order::add(ItemType item) {
	newOrder.add(item);
	sizeOfOrderList++;
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
		cout << "Not a valid option, please try again. If you want to cancel, enter 0." << endl;
	}

	return status;
}

string Order::getStatus() {
	return status;
}

void Order::displayAllItems() {
	newOrder.print();
}

bool Order::isEmpty() {
	if (sizeOfOrderList > 0) {
		return false;
	}
	else
		return true;
}

void Order::createNewOrder(List foodList, Order& order) {
	for (int i = 0; i < foodList.getLength(); i++) {
		cout << foodList.get(i) << endl;
	}
	int foodOption;
	cout << "Select food choice: ";
	cin >> foodOption;
	for (int i = 0; i < foodList.getLength(); i++) {
		if (i == (foodOption - 1)) {
			order.add(foodList.get(i));
			//orderQueue.enqueue(foodList.get(i));
		}
	}
	string choice;
	cout << "Order More? [Y/N]: ";
	cin >> choice;
	while (choice == "Y" || choice == "y") {
		cout << "--Add More Items--" << endl;
		for (int i = 0; i < foodList.getLength(); i++) {
			cout << foodList.get(i) << endl;
		}
		cout << "Select food choice: ";
		cin >> foodOption;
		for (int i = 0; i < foodList.getLength(); i++) {
			if (i == (foodOption - 1)) {
				order.add(foodList.get(i));
				//orderQueue.enqueue(foodList.get(i));
			}
		}
		cout << "Order More? [Y/N]: ";
		cin >> choice;
	}

	cout << "Thank you for ordering, your order will be ready soon!" << endl;
}

