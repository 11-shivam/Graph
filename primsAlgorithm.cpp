#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class graph {
    int V;
    vector<vector<pair<int, int>>> adj;  // Dynamic adjacency list: (neighbor, weight)

public:
    graph(int vertices) {
        V = vertices;
        adj.resize(V);  // Resize to have V empty vectors
    }

    // Method to add a weighted edge (undirected graph)
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // For undirected graph
    }

    // Method to add multiple weighted edges at once
    void addEdges(const vector<tuple<int, int, int>>& edges) {
        for (const auto& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            addEdge(u, v, w);
        }
    }

    void printAdjList() const {
        for (int u = 0; u < V; ++u) {
            cout << u << ": ";
            for (const auto& [v, w] : adj[u]) {
                cout << "(" << v << ", " << w << ") ";
            }
            cout << "\n";
        }
    }
};

void PrimsAlgorithm(int src,graph g){
    vector<bool>vis(8,0);
    int parent[8];
    vis[src] = 1;
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
    int cost =0;
    pq.push({0,{0,-1}});
    parent[0] = -1;

    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();

        if(!vis[node]){
            cost += wt;
            vis[node] = 1;
            parent[node] = par;

            for(int j=0; j<g[node].size();j++)
        }
    }
}

int main() {
    graph g(9);
    vector<tuple<int, int, int>> edges = {
        {0, 1,4},
        {0,7,8},
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 8, 2},
        {2, 5, 4},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 3},
        {7, 8, 7}
    };

    g.addEdges(edges);
    g.printAdjList();

    return 0;
}