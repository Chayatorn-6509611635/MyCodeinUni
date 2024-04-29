#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

// Ta-b = | Ha - Hb | + 1
struct Graph {
	// Attributes
	int high;
	int x;
	int y;
	
	// Members
	vector<Graph*> adj;
	
	// Constructor
	Graph(int _x, int _y, int h = -1)
		: x(_x),
		y(_y),
		high(h){}
};

struct compare{
	bool operator()( pair<int, Graph*> &a , pair<int, Graph*> &b){
		return ((a.second->high) > (b.second->high));
	}
};

class Arena {
protected:
	Graph*** g;
	Graph *start;
	vector<Graph*> dest;
	int size;
	
public:
	Arena(const int _size) : size(_size) {
		g = new Graph**[size];
		for (int i = 0; i < size; i++) {
			g[i] = new Graph*[size];
			for (int j = 0; j < size; j++) {
				g[i][j] = new Graph(i,j);
			}
		}
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				if (y + 1 < size) g[x][y]->adj.push_back(g[x][y + 1]);     // north
				if (y - 1 >= 0) g[x][y]->adj.push_back(g[x][y - 1]);       // south
				if (x + 1 < size) g[x][y]->adj.push_back(g[x + 1][y]);     // east
				if (x - 1 >= 0) g[x][y]->adj.push_back(g[x - 1][y]);       // west
			}
		}
		
		start = nullptr;
	}
	
	~Arena() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				delete g[i][j];
			}
			delete[] g[i];
		}
		delete[] g;
	}
	
	void setStartposition(const int x, const int y){
		start = g[x][y];
	}
	
	void setDestinationPosition(const vector<Graph*> destarr){
		dest = destarr;
	}
	
	Graph* getGraph(const int x, const int y) {
		return g[x][y];
	}
	
	void setGraphHigh(const int x, const int y, const int h) {
		getGraph(x, y)->high = h;
	}
	
	
	vector<int> findMinTimeToDest() {
		vector<int> minTime;
		if (dest.empty() || start == nullptr) {
			return minTime;
		}
		
		priority_queue<pair<int, Graph*>, vector<pair<int, Graph*>>, compare> pque;
		
		int** dis = new int*[size];
		for (int i = 0; i < size; i++) {
			dis[i] = new int[size];
			for (int j = 0; j < size; j++) {
				dis[i][j] = INT_MAX;
			}
		}
		pque.push({0, start});
		dis[start->x][start->y] = 0;
		
		while (!pque.empty()) {
			pair<int, Graph*> popQueue = pque.top();
			int curDistance = popQueue.first;
			Graph* cur = popQueue.second;
			pque.pop();
			
			for (Graph* c : cur->adj) {
				int weighcalc = abs(cur->high - c->high) + 1;
				int newDistance = curDistance + weighcalc;
				
				if (newDistance < dis[c->x][c->y] && c->high != -1) {
					dis[c->x][c->y] = newDistance;
					pque.push(make_pair(newDistance, c));
				}
			}
            
		}
		
		//Test board
		cout << endl;
		for (int i = 0; i<size; i++) {
			for (int j = 0; j<size; j++) {
				cout << dis[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		
		for (Graph* des : dest) {
			if(dis[des->x][des->y] != INT_MAX){
				minTime.push_back(dis[des->x][des->y]);
			}
		}
		
		for (int i = 0; i < size; i++) {
			delete[] dis[i];
		}
		delete[] dis;
		return minTime;
	}
	
	void print() {
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				cout << "Graph at: ";
				cout << x + 1 << ' ' << y + 1 << ' ' << g[x][y]->high << '\n';
				cout << "neighbor:" << '\n';
				if (y + 1 < size) cout << x + 1 << ' ' << y + 2 << ' ' << g[x][y + 1]->high << '\n';
				if (y - 1 >= 0) cout << x + 1 << ' ' << y << ' ' << g[x][y - 1]->high << '\n';
				if (x + 1 < size) cout << x + 2 << ' ' << y + 2 << ' ' << g[x + 1][y]->high << '\n';
				if (x - 1 >= 0) cout << x << ' ' << y + 2 << ' ' << g[x - 1][y]->high << '\n';
			}
		}
	}
};

int main(int argc, char* argv[]) {
	int n, k, p, Xs, Ys, Hs;
	cin >> n >> k >> p >> Xs >> Ys >> Hs;
	
	// Create arena
	Arena *arena = new Arena(n);
	arena->setGraphHigh(Xs - 1, Ys - 1, Hs); //set start hight
	arena->setStartposition(Xs-1, Ys-1);
	
	// Set dastination
	vector<Graph*> des;
	for (int i = 0; i < k; i++) {
		int x, y, h;
		cin >> x >> y >> h;
		arena->setGraphHigh(x - 1, y - 1, h);
		des.push_back(arena->getGraph(x-1, y-1));
	}
	arena->setDestinationPosition(des);
	
	// Set hight of known graph
	for (int i = 0; i < p; i++) {
		int x, y, h;
		cin >> x >> y >> h;
		arena->setGraphHigh(x - 1, y - 1, h);
	}
	
	vector<int> minToDesTime = arena->findMinTimeToDest();
//	// Test output
	for(int i : minToDesTime){
		cout << i << ' ';
	}
	cout << endl;
	
	if(!minToDesTime.empty() && minToDesTime.size() == k){
		vector<int>::iterator minTime = min_element(minToDesTime.begin(), minToDesTime.end());
		vector<int>::iterator maxTime = max_element(minToDesTime.begin(), minToDesTime.end());
		cout << *maxTime << endl;
		cout << *minTime << endl;
	}else{
		cout << k-minToDesTime.size() << endl;
	}
	delete arena;
	return 0;
}