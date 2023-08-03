#include "Queue.h"
#include<string>
#include<iostream>
using namespace std;

Queue::Queue() {
	frontNode = nullptr;
	backNode = nullptr;
}

Queue::~Queue() {
	Node* temp;
	while (frontNode != nullptr) {
		temp = frontNode;
		frontNode = frontNode->next;
		temp->next = nullptr;
		delete temp;
	}
}

bool Queue::enqueue(ItemType item) {
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = nullptr;

	if (isEmpty() == true) {
		frontNode = newNode;
		backNode = newNode;
	}
	else {
		backNode->next = newNode;
		backNode = newNode;
	}

	return true;
}

bool Queue::dequeue() {
	if (isEmpty() == true) {
		return false;
	}
	else if (frontNode == backNode) {
		delete frontNode;
		frontNode = nullptr;
		backNode = nullptr;
	}
	else {
		Node* temp = new Node;
		temp = frontNode;
		frontNode = frontNode->next;
		delete temp;
	}
	return true;
}

bool Queue::dequeue(ItemType& item) {
	if (isEmpty() == true) {
		return false;
	}
	else if (frontNode == backNode) {
		Node* temp = new Node;
		temp = frontNode;
		frontNode = nullptr;
		backNode = nullptr;
		item = temp->item;
	}
	else {
		Node* temp = new Node;
		temp = frontNode;
		frontNode = frontNode->next;
		item = temp->item;
		delete temp;
	}
	return true;
}

void Queue::getFront(ItemType& item) {
	if (isEmpty() == false) {
		item = frontNode->item;
	}
	else {
		cout << "Nothing in queue to return" << endl;
	}
}

bool Queue::isEmpty() {
	if (frontNode == nullptr) {
		return true;
	}
	else
		return false;
}

void Queue::displayItems() {
	if (isEmpty() == false) {
		Node* temp = new Node;
		temp = frontNode;
		while (temp != nullptr) {
			cout << temp->item << ",";
			temp = temp->next;
		}
		cout << endl;
	}
	else {
		cout << "Nothing in queue to return" << endl;
	}
}
