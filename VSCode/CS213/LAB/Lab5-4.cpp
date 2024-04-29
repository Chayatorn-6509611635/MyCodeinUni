#include<iostream>

using namespace std;

struct Node {
    double data;
    Node* next;
    Node(double value) {
        data = value; next = NULL;
    }
};

int main(int argc, char **argv){
	Node *a, *tmp;
	a = new Node(10);
	a->next = new Node(20);
	a->next->next = new Node(30);
	for(tmp = a; tmp->next->next != NULL; tmp = tmp->next);
	cout << tmp->data << endl;
	cout << tmp->next << endl;
	cout << tmp->next->data << endl;
	cout << endl;
	delete tmp->next;
	cout << tmp->data << endl;
	cout << tmp->next << endl;
	cout << tmp->next->data << endl;
	cout << endl;
	tmp->next = NULL;
	cout << tmp->data << endl;
	cout << tmp->next << endl;
	cout << tmp->next->data << endl;
	tmp = a;
	/*while(tmp != NULL) {
		cout << tmp->data << " ";
	}*/
	cout << endl;
	return 0;
}
