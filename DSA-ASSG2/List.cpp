#include "List.h"

List::List() {
	firstNode = nullptr;
	size = 0;
}

List::~List() {
	// Remove all items from the heap space
	Node* temp;
	while (firstNode != NULL) {
		temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
	}
}

bool List::add(ItemType item) {
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (size == 0) {
		firstNode = newNode;
	}
	else {
		Node* temp = firstNode;
		while (temp->next != NULL) {
			temp = temp->next; //traverse through the list
		}
		temp->next = newNode;
	}
	size++;
	return true;
}



bool List::add(int index, ItemType item) {
	bool success = (index >= 0) && (index <= size);
	Node* temp = firstNode;
	if (success) {
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (index == 0) {
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else {
			int currentIndex = 0;
			while (temp->next != NULL && (currentIndex + 1 < index)) {
				temp = temp->next;
				currentIndex++;
			}
			newNode->next = temp->next;
			temp->next = newNode;

		}
		size++;
		return true;
	}

	else {
		return false;
	}
}


void List::remove(int index) {
	bool success = (index >= 0) && (index <= size);
	Node* temp = firstNode;
	if (success) {
		if (index == 0) {
			firstNode = firstNode->next;
			delete temp;
			temp = NULL;
		}
		else {
			int currentIndex = 0;
			while (temp->next != NULL && (currentIndex + 1 < index)) {
				temp = temp->next;
				currentIndex++;
			}
			Node* remove = temp->next;
			temp->next = remove->next;
			delete remove;
			remove = NULL;
		}
		size--;
	}
}


ItemType List::get(int index) {
	bool success = (index >= 0) && (index <= size);
	Node* temp = firstNode;
	if (success) {
		int currentIndex = 0;
		while (temp->next != NULL && (currentIndex < index)) {
			temp = temp->next;
			currentIndex++;
		}
		if (temp != NULL) {
			return temp->item;
		}
	}
	return ItemType();
}

bool List::isEmpty() { return size == 0; }

int List::getLength() { return size; }


void List::print() {
	Node* temp = firstNode;
	while (temp != NULL) {
		cout << temp->item << endl;
		temp = temp->next;
	}

}
