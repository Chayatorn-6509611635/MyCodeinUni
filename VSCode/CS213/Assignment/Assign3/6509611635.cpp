#include <iostream>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

class BST {
    private:
        bool hasChar[26] = {false};

        struct Node {
            string data;
            set<int> line;
            Node* left;
            Node* right;
            Node(string value, int n) {
            	data = value;
                left = NULL;
                right = NULL;
                line.insert(n);
            }
        };

        Node* root;

        Node* insert(Node* root, string value, int line) {
                    if(!root) {
                        return new Node(value, line);
                    }

                    if(value < root->data) {
                        root->left = insert(root->left, value, line);
                    } else if(value > root->data) {
                        root->right = insert(root->right, value, line);
                    } else {
                        root->line.insert(line);
                    }
                    hasChar[root->data[0] - 'a'] = true;
                    return root;
            }

        void printByFirstLetter(Node* root, char firstLetter) {
            if(root != NULL) {
            
                printByFirstLetter(root->left, firstLetter);
                char first = root->data.empty() ? '\0' : root->data[0];
                if(tolower(firstLetter) == tolower(first)) {
                	cout << '\t';
                    cout << left << setw(15) << root->data << '\t';
                    for(int i : root->line){
                        cout << right << setw(3) << i << ' ';
                    }
                    cout << endl;
                }

                printByFirstLetter(root->right, firstLetter);
            }
        }

    public:
        BST() {
            root = NULL;
        }
        
        void insertNode(string value, int line) {
        	for(int i = 0; i < value.length(); i++){
				value[i] = (char)tolower(value[i]);
			}
            root = insert(root, value, line);
        }

        void printTree() {
            cout << "====================INDEX.TXT=======================" << endl;
            for(char c = 'a'; c <= 'z'; c++) {
            	if(hasChar[c - 'a']){
					cout << (char)toupper(c) << endl;
					printByFirstLetter(root, c);
				}
            }
        }
};

int main() {
    BST* bst = new BST();
    string fname = "document.txt";
    ifstream fin(fname);
    if(!fin) {
        cerr << "ERROR: Cannot open file of output file falied.";
        abort();
    }
    string delimiters = " .,;()\"-_1234567890\t\n\r";
    string str;
    int i = 1;
    string skipWords[] = {"a", "an", "the"};
	while(getline(fin, str)) {
		if(str.empty()) {continue;}
        size_t start = str.find_first_not_of(delimiters);
		while (start != string::npos) {
			size_t end = str.find_first_of(delimiters, start);
			string token = str.substr(start, end - start);
			bool skipInsert = false;
            for (const string& skipWord : skipWords) {
                if (token == skipWord) {
                    skipInsert = true;
                    break;
                }
            }

            if (!skipInsert) {
                bst->insertNode(token, i);
            }
			start = str.find_first_not_of(delimiters, end);
		}
		i++;
    }
    bst->printTree();
    return 0;
}
