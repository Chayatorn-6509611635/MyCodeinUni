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
    a->next = b;
    b->next = c;
    c->next = a;
    tmp = c;
    int i = 0;
    while(tmp != NULL && i < 10) {
        cout << tmp->data << " ";
        tmp = tmp->next;
        i++;
    }
    cout << endl;
    return 0;
}