#pragma once
#include "Order.h"
#include "List.h"
#include <string>
#include <iostream>

class Customer
{
private:
	string name;
	//int loyaltyPoints; 
	//Order order;

public:
	int loyaltyPoints;
	bool freeWcChicken; 
	bool freeWokeZero;
	Customer();
	Customer(string n);
	void setName(string n);
	string getName();
	void getLoyaltyPts();
	void addLoyaltyPts(int addedPts);
	void removeLoyaltyPts(int removePts);
};

