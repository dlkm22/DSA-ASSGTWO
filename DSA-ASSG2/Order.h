#pragma once
#include<string>
#include<iostream>
#include "List.h"
//create new order object which includes ordered food and status
class Order
{
private:
	List orderList;




public:
	Order();
	bool updateStatus(Order& order);
};

