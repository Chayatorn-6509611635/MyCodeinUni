#include <iostream>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

class BST {
	private:
		struct Node {
			string data;
			Node* left;
			Node* right;
			set<int> line;
   			Node(string value, int line): data(value), right(NULL), left(NULL) {
				this->line.insert(line);
			}
   		};
		Node* root;

		Node* insert(Node* root, string value, int line) {
			if(root == NULL) {
				return new Node(value, line);
			}
			//recursion (visit child and set it to root)
			if(value < root->data) {
				root->left = insert(root->left, value, line);
			} else if(value > root->data) {
				root->right = insert(root->right, value, line);
			} else {
				root->line.insert(line);
			}
			return root;
		}

		void printInOrder(Node* root, char firstLetter) {
    	if (root != NULL) {
        	printInOrder(root->left, firstLetter);
        	char c = root->data.empty() ? '\0' : root->data[0];
        	if (c == firstLetter) {
            	cout << left << setw(15) << root->data;
            	for (int i : root->line) {
                	cout << setw(3) << i;
            	}
            cout << endl; // Add this line to print each node on a new line
        }
        printInOrder(root->right, firstLetter);
    }
}



	public:
		BST(): root(NULL){}

		void insertNode(string value, int line) {
			root = insert (root, value, line);
		}

		void printTree() {
			for(char c = 'a'; c <= 'z'; c++){
				printInOrder(root, c);
			}
		}
};

int main() {
	BST* bst = new BST();
	string filename = "document.txt";
	ifstream fin(filename, ios::in);
	if(!fin){
		cerr << "Error: Cannot open file or output failed!";
		abort();
	}
	int i = 1;
	while(!fin.eof()){
		string str;
		getline(fin, str);
		
		stringstream ss(str);
		string s;
		while(ss >> s){
			if(s.length() == 1 && s == "a")
			bst->insertNode(s, i);
		}
		i++;
	}
	bst->printTree();
	delete bst;
	return 0;
}
