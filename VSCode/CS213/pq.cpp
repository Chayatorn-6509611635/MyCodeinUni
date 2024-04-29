#include <iostream>
#include <queue>

class Vertex {
public:
    int distance;

    bool operator>(const Vertex& other) const {
        return distance > other.distance;
    }
};
sturct c
int main() {
    std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex>> pq;

    Vertex v1{3};
    Vertex v2{1};
    Vertex v3{5};

    pq.push(v1);
    pq.push(v2);
    pq.push(v3);

    while (!pq.empty()) {
        Vertex top = pq.top();
        pq.pop();
        std::cout << "Vertex with distance " << top.distance << " dequeued.\n";
    }

    return 0;
}