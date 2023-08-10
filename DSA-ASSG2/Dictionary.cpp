#include "Dictionary.h"
#include "List.h"
using namespace std;

Dictionary::Dictionary() {
	size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		items[i] = nullptr;
	}
}

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
	else if (isdigit(c))
	{
		return (int)c; 
	}
	else
		return -1;

}


bool Dictionary::add(KeyType newKey, ItemType newItem) {
	int index = hash(newKey);

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
			else {
				// If the node to remove is in the middle or end of the chain
				prev->next = current->next;
			}
		}
		prev = current;
		current = current->next;
	}
}

ItemType Dictionary::get(KeyType key) {
	int index = hash(key);
	Node* current = items[index];
	while (current->next != nullptr) {
		if (current->key == key) {
			return current->item;
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

void Dictionary::print() {
	for (int i = 0; i < MAX_SIZE; i++) {
		Node* current = items[i];
		while (current != nullptr) {
			cout << current->key << ": " << current->item << endl;
			current = current->next;
		}
	}

}


