#include<iostream>
#include "ModifiedLinkedList.h"

using namespace std;

void ModifiedLinkedList::add(double value){
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
	counter++;
	mid = head;
	if(counter > 1) {
		for(int i = 1; i < (counter+1)/2; i++){
			mid = mid->next;
		}
	}
}

void ModifiedLinkedList::getData(double* &value,int &count){
	if(head == NULL){
		cout << "Empty List." << endl;
		return;
	}
	value = new double[this->counter];
	for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
		*value = tmp->data;
		value++;
	}
	count = this->counter;
	value -= count;
}

ModifiedLinkedList* ModifiedLinkedList::clone(){
	ModifiedLinkedList* mod = new ModifiedLinkedList();
	double* data;
	int size;
	this->getData(data, size);
	for(int i = size-1; i >= 0; i--){
		mod->add(data[i]);
	}
	return mod;
}

ModifiedLinkedList* ModifiedLinkedList::mergeWith(ModifiedLinkedList* List){
	if(List == NULL || List->head == NULL) return this;
	this->counter += List->counter;
	int midpoint = (this->counter + 1)/2;
	Node* curr = List->head;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = this->head;
	this->head = List->head;
	Node* tmp = head;
	
	for(int i = 1; i < midpoint; i++){
		tmp = tmp->next;
	}
	
	this->mid = tmp;
	return this;
}

int ModifiedLinkedList::cut(int index, ModifiedLinkedList* &frontList, ModifiedLinkedList* &backList){
	if(index < 1 || index > counter){
		return -1;
	}
	frontList = new ModifiedLinkedList();
	backList = new ModifiedLinkedList();
	frontList->counter = index;
	backList->counter = this->counter - index;
	Node* tmp = this->head;
	int curPos = 1;
	int frontMid = (index+1)/2;
	int backMid = ((backList->counter + 1)/2) + index;
	frontList->head = this->head;
	Node* cutNode = head;
	while(tmp != NULL){
		if(curPos == index){
			cutNode = tmp;
		}
		if(curPos == index+1){
			backList->head = tmp;
		}
		if(curPos == frontMid){
			frontList->mid = tmp;
		}
		if(curPos == backMid){
			backList->mid = tmp;
		}
		curPos++;
		tmp = tmp->next;
	}
	cutNode->next = NULL;
	return 0;
}

void ModifiedLinkedList::removeAllNodes(){
	while(head != NULL){
		Node* tmp = this->head;
		head = head->next;
		delete tmp;
	}
	counter = 0;
	this->mid = NULL;
}

void ModifiedLinkedList::print(){
	for(Node* tmp = head; tmp != NULL; tmp = tmp->next) {
		if(tmp == mid) {
			cout << '[' << tmp->data << ']' << ' ';
		} else {
			cout << tmp->data << ' ';
		}
	}
	cout << ", Mid = :" << mid->data << endl;
}
