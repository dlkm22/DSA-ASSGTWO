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

public:
	//constructor
	Order();

	//add item to order list
	bool add(ItemType item);

	//update status of order
	string updateStatus();

	//get status of order
	string getStatus();

	//cancel order if status != preparing
	bool cancelOrder(Queue& orderQueue);

	//display all items in order
	void displayAllItems();

	//checks if order list is empty
	bool isEmpty();

	//create new order 
	int createNewOrder(List& foodList, List& priceList, Order& order, Queue& orderQueue, bool freeWcChicken, bool freeWokeZero);
};

