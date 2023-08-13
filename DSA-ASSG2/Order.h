#pragma once
#include<string>
#include<iostream>
#include "List.h"
#include "Customer.h"
#include "Queue.h"
//create new order object which includes ordered food and status
class Order
{
private:
	List newOrder;
	string status = "Order Received";
	int sizeOfOrderList;
	string n;
	//Customer customer(n);

public:
	//constructor
	Order();

	//add item to order list
	bool add(ItemType item);

	//void addCustomerInfo(Customer c);

	//string getCustomerInfo(Order& order);

	//update status of order
	string updateStatus();

	//get status of order
	string getStatus();

	//cancel order if status != preparing
	bool cancelOrder();

	//display all items in order
	void displayAllItems();

	//checks if order list is empty
	bool isEmpty();

	//create new order 
	void createNewOrder(List& foodList, Order& order, Queue& orderQueue);
};

