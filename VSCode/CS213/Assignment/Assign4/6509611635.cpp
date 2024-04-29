/*
	STDID: 6509611635
	NAME: CHAYATORN PRUKRATTANANAPA
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Node {
	int x, y, h;
	vector<Node*> adj;
	Node(int x, int y) : x(x), y(y), h(-1) {}
};

struct Compare {
	bool operator()(Node* &a, Node* &b){
		return ((a->h) > (b->h));
	}
};


class Graph {
	private:
		int size;
		Node ***node;
		Node *start;
		vector<Node*> end;
	public:
		Graph(int size) : start(NULL){
   			this->size = size;
    		node = new Node**[size];
    		for (int i = 0; i < size; i++) {
        		node[i] = new Node*[size];
        		for (int j = 0; j < size; j++) {
            		node[i][j] = new Node(i, j); //construct empty node and set adjacent
    			}
			}
			for (int i = 0; i < size; i++) {
        		for (int j = 0; j < size; j++) {
        			if (j > 0) node[i][j]->adj.push_back(node[i][j - 1]);
            		if (j < size - 1) node[i][j]->adj.push_back(node[i][j + 1]);
            		if (i < size - 1) node[i][j]->adj.push_back(node[i + 1][j]);
            		if (i > 0) node[i][j]->adj.push_back(node[i - 1][j]);

        		}
    		}
		}

		void setCell(int x, int y, int h = -1){
			node[x-1][y-1]->x = x;
			node[x-1][y-1]->y = y;
			node[x-1][y-1]->h = h;
		}

		~Graph() {
			for(int i = 0; i < size; i++){
				for(int j = 0; j < size; j++){
					delete node[i][j];
				}
				delete[] node[i];
			}
			delete[] node;
		}

		void setStart(int x, int y, int h) {
			setCell(x, y, h);
			start = node[x-1][y-1];
		}

		void setEnd(int x, int y, int h) {
			setCell(x, y, h);
			end.push_back(node[x-1][y-1]);
		}

		vector<Node*> getEnd(){
			return end;
		}

		void printBoard(){
			cout << "Boards size " << size << "x" << size << ':' << endl;
			for(int i = 0; i < size; i++){
				for(int j = 0; j < size; j++){
					cout << '(' << node[i][j]->x << ", " << node[i][j]->y << "): " << node[i][j]->h << endl;
					for(Node* c : node[i][j]->adj){
						cout << c->x << ',' << c->y << '\t';
					}
					cout << endl;
				}
				cout << endl;
			}
		}

		vector<int> findShortestTime(){
			vector<int> t;
			if(!start || end.empty()){
				return t;
			}

			priority_queue<Node*, vector<Node*>, Compare> pq;

			//Dijkstra's Algorithm

			//Fixed-size vector initialized to infinity (2D vector)
			vector<vector<int>> distance(size, vector<int>(size, INF));

			pq.push(start);
			distance[start->x-1][start->y-1] = 0; //set start distance to 0

			while(!pq.empty()){
				Node* n = pq.top(); // n is current node
				pq.pop();

				// c is current node adjacents
				for(Node* c : n->adj){
					//int we = abs(n->h - c->h) + 1; //weight edge
					//int cd = we + distance[n->x-1][n->y-1]; //current distance
					if(distance[n->x-1][n->y-1] + abs(n->h - c->h) + 1 < distance[c->x-1][c->y-1] && c->h != -1){
						distance[c->x-1][c->y-1] = distance[n->x-1][n->y-1] + abs(n->h - c->h) + 1;
						pq.push(c);
					}
				}
			}
			
			//Test print distance board
			/*for(int i = 0; i < size; i++){
				for(int j = 0; j < size; j++){
					cout << distance[i][j] << '\t';
				}
				cout << endl;
			}*/
			
			for(Node* e: end) {
				if(distance[e->x-1][e->y-1] != INF){
					t.push_back(distance[e->x-1][e->y-1]);
				}
			}

			return t;
		}
};

int main(){
	int N, K, P, Xs, Ys, Hs;
	cin >> N >> K >> P >> Xs >> Ys >> Hs;
	Graph *g = new Graph(N);
	g->setStart(Xs, Ys, Hs);

	for(int i = 0; i < K; i++){
		int x, y, h;
		cin >> x >> y >> h;
		g->setEnd(x, y, h);
	}

	//Test end
	/*
	vector<Node*> end = g->getEnd();
	cout << endl;
	for(Node* x : end){
		cout << x->x << ',' << x->y << ':' << x->h << endl;
	}
	cout << endl;
	*/

	for(int i = 0; i < P; i++){
		int x, y, h;
		cin >> x >> y >> h;
		g->setCell(x, y, h);
	}

	//Test print board
	//g->printBoard();

	vector<int> time = g->findShortestTime();

	//Test print all result
	/*for(int i : time){
		cout << i << endl;
	}
	cout << endl;
	*/

	if(!time.empty() && time.size() == K){
		vector<int>::iterator mint = min_element(time.begin(), time.end());
		vector<int>::iterator maxt = max_element(time.begin(), time.end());
		cout << *maxt << endl;
		cout << *mint << endl;
	} else {
		cout << K - time.size() << endl;
	}

	return 0;
}
