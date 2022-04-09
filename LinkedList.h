#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include "composer.h"
using namespace std;

template<class T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList();
	~LinkedList();
	void printList() const;
	void append(const T data);
	void prepend(const T data);
	bool removeFront();
	void insert(const T data);
	bool remove(const T data);
	bool find(const T data);
	bool isEmpty() const;
	T getFirst() const;
	T getLast() const;

};

//Default Constructor 
template<class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

//Deconstructor 
template<class T>
LinkedList<T>::~LinkedList() {
	while (head) {
		Node<T>* next = head->next;
		delete head;
		head = next;
	}
}

//Function: print all node in the LinkedList
template<class T>
void LinkedList<T>::printList() const {
	Node<T>* curNode = head;
	while (curNode) {
		cout << curNode->data.name << ", " << curNode->data.dateOfDeath << endl;
		curNode = curNode->next;
	}
	cout << endl;
}

//Receives Composer data object which contains  
//its name and date of death
//Function: add the new node to the back of the linked list
template<class T>
void LinkedList<T>::append(const T data) {
	Node<T>* newNode = new Node<T>;
	newNode->name = data.name;
	newNode->year = data.dateOfDeath;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

//Receives Composer data object which contains  
//its name and date of death
//Function: add the new node to the front of the linked list
template<class T>
void LinkedList<T>::prepend(const T data) {
	Node<T>* newNode = new Node<T>;
	if (head == nullptr) {
		newNode->data.name = data.name;
		newNode->data.dateOfDeath = data.dateOfDeath;
		newNode->next = nullptr;
		head = newNode;

		return;
	}
	else {
		newNode->data.dateOfDeath = data.dateOfDeath;
		newNode->data.name = data.name;
		newNode->next = head;
		head = newNode;
	}
}

//Return bool data type indicate true or false
//Function: remove the first node of the linked list
template<class T>
bool LinkedList<T>::removeFront() {
	if (head == nullptr) {
		return false;
	}
	else {
		Node<T>* newNode = head;
		head = head->next;
		delete newNode;
		return true;
	}
}

//Receives Composer data object which 
//contains its name and date of death
//Function: add new node to the linked list by the earlier
//to the later years of death
template<class T>
void LinkedList<T>::insert(const T data) {
	Node<T>* newNode = new Node<T>;
	Node<T>* curNode = nullptr;
	newNode->data.name = data.name;
	newNode->data.dateOfDeath = data.dateOfDeath;
	Node<T>* list = head;

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}
	else if (head->data.dateOfDeath > data.dateOfDeath) {
		prepend(data);
	}
	else {
		while (list != nullptr && list->data.dateOfDeath < data.dateOfDeath) {
			curNode = list;
			list = list->next;
		}

		newNode->next = list;
		curNode->next = newNode;
	}
}

//Receives Composer data object which 
//contains its name 
// Return true or false based on the condition
//Function: remove the node from the list
//based on the user input and whether it's part of the list
template<class T>
bool LinkedList<T>::remove(const T data) {
	if (head == nullptr) {
		return false;
	}
	else if (head->data.name == data.name) {
		Node<T>* curNode = head;
		head = head->next;
		delete curNode;
		return true;
	}
	else {
		Node<T>* curNode = head;
		Node<T>* placeHolder = nullptr;
		while (curNode != nullptr && curNode->data.name != data.name) {
			placeHolder = curNode;
			curNode = curNode->next;
		}
		if (curNode != nullptr) {
			placeHolder->next = curNode->next;
			delete curNode;
			return true;
		}
	}
	return false;
}

//Receives Composer data object which 
//contains its name 
// Return true or false based on the condition
//Function: check whether the user input is part of the
//name of the composers
template<class T>
bool LinkedList<T>::find(const T data) {
	if (head == nullptr) {
		return false;
	}
	else if (head->data.name == data.name) {
		return true;
	}
	else {
		Node<T>* curNode = head;
		Node<T>* placeHolder = nullptr;
		while (curNode != nullptr && curNode->data.name != data.name) {
			placeHolder = curNode;
			curNode = curNode->next;
		}

		if (curNode != nullptr) {
			return true;
		}
	}
	return false;
}

//Return true or false based on whether 
//the linked list is empty
//Function: check to see whether the linked list
//is empty
template<class T>
bool LinkedList<T>::isEmpty() const {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//Return the first node of the linked list
template<class T>
T LinkedList<T>::getFirst() const {
	return head;
}

//return the last node of the linked list
template<class T>
T LinkedList<T>::getLast() const {
	Node<T>* curNode = head;
	Node<T>* placeHolder = curNode->next;

	while (placeHolder != nullptr) {
		curNode = placeHolder;
		placeHolder = curNode->next;
	}
	tail->data = curNode->data;
	return tail;
}