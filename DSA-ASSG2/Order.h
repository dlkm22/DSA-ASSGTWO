#pragma once
#include<string>
#include<iostream>
#include "List.h"
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

	//display all items in order
	void displayAllItems();

	//checks if order list is empty
	bool isEmpty();

	//create new order 
	void createNewOrder(List foodList, Order& order);
};

