#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int n;
    vector<vector<int> > edge;
    vector<bool> visited;
    vector<vector<int> > connectedComponents;

public:
    Graph(int v);
    void addEdge(int s, int e);
    void dfs(int v);
    void bfs(int v);
    void printVector(vector<int> data);
    void resizeVisited();
    vector<bool> getVisited();
    vector<vector<int> > getConnectedComponents();
    void resizeConnectedComponents();
    int idx = 0;
};

Graph::Graph(int n) {
    this->n = n;
    edge.resize(n);
}

vector<bool> Graph::getVisited() {
    return visited;
}

vector<vector<int> > Graph::getConnectedComponents() {
    return connectedComponents;
}

void Graph::addEdge(int s, int e) {
    edge[s].push_back(e);
    edge[e].push_back(s);
}

void Graph::resizeVisited() {
    visited.resize(n, false);
}

void Graph::resizeConnectedComponents() {
    connectedComponents.resize(n);
}

void Graph::printVector(vector<int> data) {
    for (auto el : data)
        cout << el << " ";
    cout << endl;
}

void Graph::bfs(int start) {
    queue<int> q;
    int cur;

    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        //cout << cur << endl;
        //connectedComponents[idx].push_back(cur);
        q.pop();
        for (int edge_iter : edge[cur]) {
            if (!visited[edge_iter]) {
                visited[edge_iter] = true;
                q.push(edge_iter);
            }
        }
    }
}

void Graph::dfs(int start) {
    visited[start] = true;
    connectedComponents[idx].push_back(start);
    for (int el : edge[start]) {
        //printVector(visited);
        if (!visited[el])
            dfs(el);
    }
}

int main() {
    int size = 10;
    Graph graph(size);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 8);
    graph.addEdge(1, 4);
    graph.addEdge(6, 3);
    graph.addEdge(3, 7);
    graph.addEdge(7, 9);

    graph.resizeVisited();
    graph.resizeConnectedComponents();
    
    for (int i = 0; i < size; ++i) {
        if (!graph.getVisited()[i]) {
            graph.dfs(i);
        }
        ++graph.idx;
    }
    for (int i = 0; i < graph.getConnectedComponents().size(); ++i) {
        graph.printVector(graph.getConnectedComponents()[i]);
    }
}