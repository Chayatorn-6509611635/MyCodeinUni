#include <iostream>

using namespace std;

struct Node {
    double data;
    Node* next;
    Node(double value) {
        data = value; next = NULL;
    }
};

int main(int argc, char **argv){
    Node *a, *b, *tmp;
    a = new Node(10);
    a->next = new Node(20);
    a->next->next = new Node(30);
    b = new Node(25);
	b->next = a->next->next;
    a->next->next = b;
    tmp = a;
    while(tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    return 0;
}
