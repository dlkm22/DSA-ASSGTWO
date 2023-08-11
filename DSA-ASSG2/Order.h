#pragma once
#include<string>
#include<iostream>
#include "List.h"
//create new order object which includes ordered food and status
class Order
{
private:


public:
	Order();
	bool add(ItemType item);
	string updateStatus(Order& order);
	void displayAllItems();
};

