#include<iostream>
#include<queue>

using namespace std;

struct Node{
    double value;
    Node* left;
    Node* right;
    Node (double data): value(data), left(NULL), right(NULL) {}
};

class Tree{
    private:
        Node* root;
    public:
        Tree() {
            root = NULL;
        }

        Tree(double data) {
            root = new Node(data);
        }

        Node* findMin(Node* root){
            if(root->left != NULL){
                root = root->left;
            }
            return root;
        }

        Node* insert(Node* n, double data){
            if(n == NULL){
                return new Node(data);
            }
            if(data < n->value){
                n->left = insert(n->left, data);
            } else if(data > n->value){
                n->right = insert(n->left, data);
            } else return n;
        }

        Node* deleteNode(Node* n, double data){
            if(n == NULL) {
                return n;
            }
            if(data < n->value){
                n->left = deleteNode(n->left, data);
            } else if(data > n->value){
                n->right = deleteNode(n->right, data);
            } else {
                if(root->left == nullptr){
                    Node* curr = n->right;
                    delete n;
                    return curr;
                } else if(n->right == nullptr){
                    Node* curr = n->left;
                    delete n;
                    return curr;
                }
                Node* tmp = findMin(n->right);
                n->value = tmp->value;
                n->right = deleteNode(n->right, tmp->value);
            }
        }

        void inOrder(Node* n){
            if(n == NULL){
                return;
            }

            inOrder(n->left);
            cout << n->value << ' ';
            inOrder(n->right);
        }

        void levelOrder(Node* n){
            if(n == NULL){
                return; 
            }

            queue<Node*> q;
            q.push(n);

            while(!q.empty()){
                n = q.front();
                q.pop();
                if(n != NULL){
                    cout << n->value << ' ';
                }
                if(n->left != NULL){
                    q.push(n->left);
                }
                if(n->right != NULL){
                    q.push(n->right);
                }
                
            }
        }

        void insert(double data){
            root = insert(root, data);
        }

        void preOrder(Node* n){
            if(n != NULL){
                cout << n->value << ' ';
                preOrder(n->left);
                preOrder(n->right);
            }
        }

        void postOrder(Node* n){
            if(n != NULL){
                postOrder(n->left);
                postOrder(n->right);
                cout << n->value << ' ';
            }
        }

        void deleteNode(double data){
            deleteNode(root, data);
        }
        void printPost(){
            postOrder(root);
            cout << endl;
        }
        void printLevel(){
            levelOrder(root);
            cout << endl;
        }
        void printIn(){
            inOrder(root);
            cout << endl;
        }
        void printPre(){
            preOrder(root);
            cout << endl;
        }
};

int main(){
    Tree* bst = new Tree();
    bst->insert(9);
    bst->insert(4);
    bst->insert(7);
    bst->insert(2);
    bst->insert(1);
    bst->deleteNode(1);
    cout << "Level : ";
    bst->printLevel();
    cout << "In : ";
    bst->printIn();
    cout << "Post : ";
    bst->printPost();
    cout << "Pre : ";
    bst->printPre();
    return 0;
}