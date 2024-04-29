#include <iostream>

using namespace std;

// Node structure for the B-tree
struct Node {
    int keys[2];        // Array to hold keys
    Node* children[3];  // Array to hold child pointers
    int numKeys;        // Number of keys currently in the node
    bool isLeaf;        // Flag to indicate if the node is a leaf

    Node() {
        numKeys = 0;
        isLeaf = true;
        for (int i = 0; i < 3; ++i) {
            children[i] = nullptr;
        }
    }
};

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->keys[0] = key;
    newNode->numKeys = 1;
    return newNode;
}

// Function to split a node
void splitChild(Node* parent, int index) {
    Node* newNode = new Node();
    Node* child = parent->children[index];
    newNode->isLeaf = child->isLeaf;
    newNode->numKeys = 1;
    newNode->keys[0] = child->keys[1];
    if (!child->isLeaf) {
        newNode->children[0] = child->children[2];
        child->children[2] = nullptr;
    }
    child->numKeys = 1;
    parent->children[index + 1] = newNode;
    parent->keys[index] = child->keys[0];
}

// Function to insert a key into the B-tree
void insert(Node* root, int key) {
    if (root == nullptr) {
        root = createNode(key);
        return;
    }

    if (root->numKeys == 2) {
        Node* newRoot = new Node();
        newRoot->isLeaf = false;
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        root = newRoot;
    }

    Node* curr = root;
    while (!curr->isLeaf) {
        int i = 0;
        while (i < curr->numKeys && key > curr->keys[i]) {
            ++i;
        }
        if (curr->children[i]->numKeys == 2) {
            splitChild(curr, i);
            if (key > curr->keys[i]) {
                ++i;
            }
        }
        curr = curr->children[i];
    }

    int i = 0;
    while (i < curr->numKeys && key > curr->keys[i]) {
        ++i;
    }
    for (int j = curr->numKeys; j > i; --j) {
        curr->keys[j] = curr->keys[j - 1];
    }
    curr->keys[i] = key;
    ++curr->numKeys;
}

// Function to print the B-tree
void print(Node* root) {
    if (root == nullptr) return;

    for (int i = 0; i < root->numKeys; ++i) {
        cout << root->keys[i] << " ";
    }
    cout << endl;

    if (!root->isLeaf) {
        for (int i = 0; i <= root->numKeys; ++i) {
            print(root->children[i]);
        }
    }
}

int main() {
    Node* root = nullptr;

    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 6);
    insert(root, 12);

    print(root);

    return 0;
}
