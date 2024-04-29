#include<iostream>

using namespace std;

class SinglyLinkedList {
public:
	SinglyLinkedList() {head = tail = NULL;}
    SinglyLinkedList(double value){
        Node* node = new Node(value);
        head->next = node;
        tail->next = node;
    }
	void   addToHead(double);
	void   addToTail(double);
	double removeFromHead();
	double removeFromTail();
	void   displayList();
    int    findIndex(double);
    void insert(double, int);
    int size();

protected:
	struct Node {
      double data;
      Node* next;
      Node(double value) { data = value; next = NULL; }
	};
   Node* head;
   Node* tail;
};

void SinglyLinkedList::addToHead(double value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if(tail == NULL){
        tail = newNode;
    } 
}

void SinglyLinkedList::addToTail(double value){
    Node* newNode = new Node(value);
    if(tail != NULL){
        tail->next = newNode;
        tail = newNode;
    } else{
        tail = newNode;
        head = newNode;
    }
}

double SinglyLinkedList::removeFromHead(){
    if(head != NULL){
        double result = head->data;
        Node* tmp = head;
        if(tail == head){
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;   
        }
        delete tmp;
        return result;
    }
    else {
        cout << "Nothing to remove" << endl;
        return 0;
    }
}

double SinglyLinkedList::removeFromTail(){
    if(head != NULL){
        double result = tail->data;
        if(tail == head){
            delete head;

            head = NULL;
            tail = NULL;
        }
        else{
            Node* tmp;
            for(tmp = head; tmp->next != tail; tmp = tmp->next); //find before tail
            tail = tmp;
            delete tail->next;
            tail->next = NULL;
        }
        return result;
    }
    else{
        cout << "Nothing to remove" << endl;
        return 0;
    }

}

void SinglyLinkedList::displayList(){
    if(head != NULL){
        int count = 0;
        for(Node* tmp = head; tmp != tail->next; tmp = tmp->next){
            cout << tmp->data << ' ';
            count++;
        }
        cout << endl;
        cout << "This Linked List contains " << count << " nodes" << endl;
    }
    else{
        cout << "This Link List is empty" << endl;
    }
}

int SinglyLinkedList::findIndex(double value){
    if(head != NULL){
        int count = 0;
        bool found = 0;
        Node* tmp = head;
        while(tmp != tail->next){
            if(tmp->data == value){
                found = 1;
                break;
            }
            else{
                count++;
                tmp = tmp->next;
            }
        }
        return found ? count : 0;
    }
    else{

    }
}

int SinglyLinkedList::size(){
    if(head!=NULL){
        int count = 0;
        for(Node* tmp=head; tmp != tail->next; tmp = tmp->next){
            count++;
        }
        return count;
    }else{
        return 0;
    }
}

void SinglyLinkedList::insert(double value, int index){
    if(index == 0){
        addToHead(value);
    }else if(index >=size()){
        cout << "Error: Index out of Bound" << endl;
    }
    else if(head!=NULL){
        Node* cur = new Node(value);
        Node* tmp = head;
        for(int i = 0; i < index - 1; i++){
            tmp = tmp->next;
        }
        cout << tmp->data << endl;
        cur->next = tmp->next;
        tmp->next = cur;
    }
}

int main(){
    SinglyLinkedList* o1 = new SinglyLinkedList();
    o1->insert(2, 0);
    o1->displayList();
}