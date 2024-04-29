#include <iostream>

using namespace std;

class DoublyLinkedList {
public:
   DoublyLinkedList() {head = tail = NULL;}
   DoublyLinkedList(double value){
        Node* node = new Node(value);
   }
   void   addToHead(double);
   void   addToTail(double);
   double removeFromHead();
   double removeFromTail();
protected:
   struct Node {
     double data;
     Node* next;
     Node* prev;
     Node(): data(0), next(NULL), prev(NULL) {}
     Node(double value) {data = value; next = NULL; prev = NULL;}
   };
   Node* head;
   Node* tail;
};

void DoublyLinkedList::addToHead(double value){
    Node* tmp = new Node(value);
        tmp->next = head;
        head = tmp;
    if (tail == NULL){
        tail = tmp;
    }
    else{
        head->next->prev = head;
    }
}

void DoublyLinkedList::addToTail(double value){
    Node *tmp = new Node(value);
    if(tail != NULL){
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
    else{
        tail = head = tmp;
    }
}

double DoublyLinkedList::removeFromHead(){
    if(head != NULL){
        double result = head->data;
        Node* tmp = head;
        if(head == tail){
            head = tail = NULL;
        }
        else{
            head = tmp->next;
            head->prev = NULL;
        }
            delete tmp;
            return result;
    }
    else {
        cout << "Nothing to remove" << endl;
        return 0;
    }
}

double DoublyLinkedList::removeFromTail(){
    if(head != NULL){
        double result = tail->data;
        Node* tmp = tail;
        if(head == tail){
            head = tail = NULL;
        }
        else{
            tail = tmp->prev;
            delete tmp;
            tail->next = NULL;
        }
        return result;
    }
    else{
        cout << "Nothing to remove" << endl;
        return 0;
    }
}

int main(){
    return 0;
}