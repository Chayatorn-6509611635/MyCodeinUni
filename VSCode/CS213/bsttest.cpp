#include <iostream>
#include <string>
#include <set>

class Node {
public:
    std::string key;    // String key
    std::set<int> values;  // Set of integers
    Node* left;
    Node* right;

    Node(const std::string& k, const std::set<int>& v) : key(k), values(v), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, const std::string& key, const std::set<int>& values) {
        if (root == nullptr) {
            return new Node(key, values);
        }

        if (key < root->key) {
            root->left = insert(root->left, key, values);
        } else if (key > root->key) {
            root->right = insert(root->right, key, values);
        }

        return root;
    }

    // Recursive helper function for in-order traversal by first letter
    void inOrderTraversalByFirstLetter(Node* root, char targetFirstLetter) {
        if (root != nullptr) {
            inOrderTraversalByFirstLetter(root->left, targetFirstLetter);

            // Extract the first letter of the key
            char firstLetter = root->key.empty() ? '\0' : root->key[0];

            // If the first letter matches the target, print the key and set elements
            if (firstLetter == targetFirstLetter) {
                std::cout << root->key << " - Values: { ";
                for (int value : root->values) {
                    std::cout << value << " ";
                }
                std::cout << "}\n";
            }

            inOrderTraversalByFirstLetter(root->right, targetFirstLetter);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(const std::string& key, const std::set<int>& values) {
        root = insert(root, key, values);
    }

    // Public function to display the BST in in-order traversal by first letter
    void displayInOrderByFirstLetter(char targetFirstLetter) {
        inOrderTraversalByFirstLetter(root, targetFirstLetter);
    }
};

int main() {
    BST bst;

    // Inserting key-value pairs into the BST
    bst.insert("apple", {1, 2, 3});
    bst.insert("banana", {4, 5});
    bst.insert("blueberry", {6, 7});
    bst.insert("mango", {8, 9});

    // Displaying the BST nodes for a specific first letter
    std::cout << "In-order traversal of BST nodes for 'b': \n";
    bst.displayInOrderByFirstLetter('b');

    return 0;
}