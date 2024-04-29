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
    Node *a, *b, *c, *tmp;
    a = new Node(10);
    b = new Node(20);
    c = new Node(30);
    a->next = c;
    b->next = a;
    tmp = c;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
    return 0;
}
