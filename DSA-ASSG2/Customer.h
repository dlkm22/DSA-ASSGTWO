#pragma once
#include "Order.h"
#include "List.h"

class Customer
{
private:
	string name;
	Order order;

public:
	Customer();
	Customer(string n);
	void setName(string n);
	//bool addOrder(Order& order);
};

