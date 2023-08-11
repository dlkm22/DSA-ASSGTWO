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

public:
	Order();
	bool add(ItemType item);
	string updateStatus();
	string getStatus();
	void displayAllItems();
};

