#include "Order.h"
#include "List.h"
#include "Customer.h"
#include "Queue.h"
#include <iostream>
#include<string>
using namespace std;

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
	cout << "What would you like to update status to? [P/COM/CAN] (0 to exit): ";
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

	if (status == "Completed") { //added
		for (int i = 0; i < newOrder.getLength(); i++) {
			newOrder.remove(i);
		}
	}

	return status;
}

string Order::getStatus() {
	return status;
}

bool Order::cancelOrder(Queue& orderQueue) {
	if (status != "Preparing") {
		for (int i = 0; i < orderQueue.getLength(); i++) {
			orderQueue.dequeue();
		}
		cout << "Order cancelled successfully" << endl;
		return true;
	}
	else {
		cout << "Unable to cancel order as it is currently being/has been prepared." << endl;
		return false;
	}
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


void Order::createNewOrder(List& foodList, Order& order, Queue& orderQueue) {
	for (int i = 0; i < foodList.getLength(); i++) {
		cout << foodList.get(i) << endl;
	}
	int foodOption;
	cout << "Select food choice: ";
	cin >> foodOption;
	for (int i = 0; i < foodList.getLength(); i++) {
		if (i == (foodOption - 1)) {
			string food;
			food = foodList.get(i);
			order.add(food);
			orderQueue.enqueue(foodList.get(i));
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
				orderQueue.enqueue(foodList.get(i));
			}
		}
		cout << "Order More? [Y/N]: ";
		cin >> choice;
	}
	

	cout << "Thank you for ordering, your order will be ready soon!" << endl;
}



