#pragma once
#include "Order.h"
#include "List.h"
#include <string>
#include <iostream>

class Customer
{
private:
	string name;
	int loyaltyPoints; 
	//Order order;

public:
	Customer();
	Customer(string n);
	void setName(string n);
	string getName();
};

