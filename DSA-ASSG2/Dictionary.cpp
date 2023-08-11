#include "Dictionary.h"
#include "List.h"
using namespace std;

Dictionary::Dictionary() {
	size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		items[i] = nullptr;
	}
}

Dictionary::~Dictionary() {
	for (int i = 0; i < MAX_SIZE; i++) {
		Node* current = items[i];
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
}

int Dictionary::hash(KeyType key) {
	int hash = 0;
	int index;
	for (int i = 0; i < key.length(); i++) {
		char c = key[i];
		if (isalpha(c))
		{
			if (isupper(c))
				hash += (int)c - (int)'A';


			else
				hash += (int)c - (int)'a' + 26;
		}
		else
		{
			hash += (int)c; 
		}
	}
	index = hash % MAX_SIZE;
	return index;
}


bool Dictionary::add(KeyType newKey, ItemType newItem) {
	int index = hash(newKey);
	Node* newNode = new Node;

	if (items[index] == nullptr) {
		newNode->key = newKey;
		newNode->item = newItem;
		newNode->next = nullptr;
		newNode->linkedNext = nullptr;

		items[index] = newNode;
	}
	else
	{
		Node* current = items[index]; //set current pointer to point to first node at index
		if (current->key == newKey && current->linkedNext == nullptr) 
		{
			newNode->key = newKey;
			newNode->item = newItem;
			newNode->next = nullptr;
			newNode->linkedNext = nullptr;
			current->linkedNext = newNode;
			return true;
		}


		else if (current->key == newKey)
		{
			while (current->linkedNext != nullptr)
			{
				current = current->linkedNext;
			}
			newNode->key = newKey;
			newNode->item = newItem;
			newNode->next = nullptr;
			newNode->linkedNext = nullptr;
			current->linkedNext = newNode;
			return true;

		}
		else 
		{
			while (current != nullptr) 
			{
				current = current->next;
			}
			newNode->key = newKey;
			newNode->item = newItem;
			newNode->next = nullptr;
			current->next = newNode;
		}
	}
	size++;
	return true;
}


void Dictionary::remove(KeyType key) {
	int index = hash(key);
	Node* current = items[index];
	Node* prev = nullptr;

	while (current != nullptr) {
		if (current->key == key) {
			if (prev == nullptr) {
				// If the node to remove is the first node in the chain
				items[index] = current->next;
			}
			else {
				// If the node to remove is in the middle or end of the chain
				prev->next = current->next;
			}
			delete current;
			size--;
			return; // Node found and removed, exit the function
		}
		prev = current;
		current = current->next;
	}
}

ItemType Dictionary::get(KeyType key, ItemType wantedItem) {
	int index = hash(key);
	Node* current = items[0];
	if (current != nullptr)
	{
		if (current->key == key)
		{
			return current->item;
		}
		else
		{
			while (current->next != nullptr) {
				if (current->key == key) {
					if (current->item == wantedItem)
					{
						return current->item;
					}
					while (current->linkedNext != nullptr)
					{
						if (current->item == wantedItem)
						{
							return current->item;
						}
						current = current->linkedNext;
					}
				
				}
				current = current->next;
			}
		}
	}
	return "Account or Key not Found";
}

bool Dictionary::isEmpty() {
	if (size == 0) {
		return true;
	}
	else
		return false;
}

int Dictionary::getLength() {
	return size;
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
