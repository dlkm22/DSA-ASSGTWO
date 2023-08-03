#include "Dictionary.h"
#include <string>
#include<iostream>
using namespace std;


Dictionary::Dictionary() { size = 0, lastNode; }

Dictionary::~Dictionary() {}



int Dictionary::hash(KeyType key)
{
	int keyValue = 0;
	for (int i = 0; i <= key.length(); i++)
	{
		keyValue += charValue(key[i]);
	}
	return keyValue;
}


int Dictionary::charValue(char c)
{
	if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int)'A';
		else
			return (int)c - (int)'a' + 26;
	}
	else
		return -1;

}


bool Dictionary::add(KeyType newKey, ItemType newItem)
{
	Node newNode;
	newNode.key = hash(newKey);
	newNode.item = newItem;
	newNode.next = NULL;
	Node* temp = &newNode;

	if (size == 0)
	{
		items[0] = temp;
		lastNode.next = temp;
		size++;
		return true;
	}
	else
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (items[i]->key == newKey)
			{
				return false;
			}
			else if (items[i]->next == NULL && items[i]->key != newKey)
			{
				items[i]->next = temp;
				items[i + 1] = temp;
				lastNode.next = temp;
				size++;
				return true;
			}
		}
	}
}


void Dictionary::remove(KeyType key)
{
	key = hash(key);
	for (int i = 0; i < size; i++)
	{
		if (items[i]->key == key)
		{
			items[i] = nullptr;
		}
	}
}