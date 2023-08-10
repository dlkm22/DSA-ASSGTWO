// Dictionary.h - - Specification of Dictionary ADT
#pragma once 
#include<string>
#include<iostream>
using namespace std;

const int MAX_SIZE = 101;
typedef string ItemType;
typedef string KeyType;

struct Node
{
	KeyType  key;   // search key
	ItemType item;	// data item
	Node* next;	// pointer pointing to next item
};

class Dictionary
{
private:
	Node* items[MAX_SIZE];
	int  size;			// number of items in the Dictionary
	Node lastNode;

public:
	// constructor
	Dictionary();

	// destructor
	~Dictionary();

	int hash(KeyType key);

	int charValue(char c);

	// add a new item with the specified key to the Dictionary
	bool add(KeyType newKey, ItemType newItem);

	// remove an item with the specified key in the Dictionary
	void remove(KeyType key);

	// get an item with the specified key in the Dictionary (retrieve)
	ItemType get(KeyType key);

	// check if the Dictionary is empty
	bool isEmpty();

	// check the size of the Dictionary
	int getLength();

	//------------------- Other useful functions -----------------
	// display the items in the Dictionary
	void print();
};