#include "Operators.h"
#include "ModifiedLinkedList.h"
#include <iostream>

using namespace std;

void Operators::makeList(double value[], int size){
	if(topList < maxTopLists - 1){
		topList++;
		lists[topList] = new ModifiedLinkedList();
		for(int i = 0; i < size; i++){
			lists[topList]->add(value[i]);
		}
	}
	else{
		cout << "List stack is full. Cannot add a new list." << endl;
	}
}

void Operators::cutList(int index){
 if(topOp < maxTopOps - 1 && topList < maxTopLists - 1){
	if(topList >= 0){
		ModifiedLinkedList* firstList;
		ModifiedLinkedList* secondList;
		int result = lists[topList]->cut(index, firstList, secondList);
		if(result == 0){
			delete lists[topList--];
			lists[++topList] = firstList;
			lists[++topList] = secondList;
			ops[++topOp] = new Op(index);
			cout << "CUT Operation has been done." << endl;
		} else {
			cout << "CUT Operation failed. Index out of bound." << endl;
		}
	} else {
		cout << "List stack is empty. Cannot perform cut Operation." << endl;
	}
} else {
	cout << "Cannot do more Operations." << endl;
}
}

void Operators::cloneList(){
	if(topOp < maxTopOps - 1 && topList < maxTopLists - 1){
	if(topList >= 0){
  		ModifiedLinkedList* clonedList = lists[topList]->clone();
	if(clonedList != NULL){
			topList++;
			lists[topList] = clonedList;
			ops[++topOp] = new Op(-1);
			cout << "CLONE Operation has been done." << endl;
		} else {
			cout << "CLONE Operation failed. Index out of bound." << endl;
		}
	} else {
		cout << "List stack is empty. Cannot perform cut operation." << endl;
	}
} else {
	cout << "Cannot do more Operators." << endl;
}
}

void Operators::printCurrentList(){
	if(topList >= 0){
		lists[topList]->print();
	} else {
		cout << "List stack is empty. Nothing to print." << endl;
	}
}

void Operators::printHistory(){
	cout << "===The lists in the history stack: ===" << endl;
	if(topList < 0){
		cout << "[X] Nothing in this stack ..." << endl;
	} else {
		for(int i = topList; i >= 0; i--){
			cout << "Index in the stack: " << i << endl;
			lists[i]->print();
		}
	}
	
	cout << "============================================" << endl;
	cout << "===The operators in the history stack: ===" << endl;
	if(topOp < 0){
		cout << "[X] Nothing in this stack ..." << endl;
	}else{
		for(int i = topOp; i >= 0; i--){
			cout << "Index in the stack: " << i << endl;
			cout << "Operator: " << ops[i]->op;
			if(ops[i]->pos != -1){
				cout << " at position : " << ops[i]->pos;
			}
			cout << endl;
		}
	}
	cout << "============================================" << endl;
}

void Operators::undo(){
	if(topOp >= 0){
		Op* operationUndo = ops[topOp];
		ops[topOp] = NULL;
		topOp--;
		if(operationUndo->op == "CUT"){
			if(topList >= 1){
				ModifiedLinkedList* firstList = lists[topList];
				ModifiedLinkedList* secondList = lists[topList - 1];
				
				firstList->mergeWith(secondList);
				
				lists[--topList] = firstList;
				
				delete secondList;
				lists[topList+1] = NULL;
				cout << "Undone [CUT] Operator ...." << endl;
			} else {
				cout << "Insufficient lists to undo a \"CUT\" operation." << endl;
			}
		} else if(operationUndo->op == "CLONE"){
			if(topList >= 0){
				ModifiedLinkedList* clonedList = lists[topList];
				lists[topList] = NULL;
				topList--;
				delete clonedList;
				cout << "Undone [CLONE] Operator ...." << endl;
			} else {
				cout << "No list to undo a \"CLONE\" operation." << endl;
			}
		}
		delete operationUndo;
	} else {
			cout << "No operations to undo." << endl;
	}
}
