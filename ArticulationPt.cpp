#include <iostream>
using namespace std;

void Articulation(int node, int parent, vector<bool> &vis, vector<int> &disc,
                  vector<int> &low, int &timer,  vector<vector<int>> &graph,
                  vector<int> &articulation_points) {
    vis[node] = true;
    disc[node] = timer;
    low[node] = timer;
    int child = 0; // counts number of child of current node

    for(int j=0;j<graph[node].size();j++){
        int next = graph[node][j];

        if(next == parent) continue;

        if(vis[next]) {
            low[node] = min (low[node] , disc[next]);
        }else {
            timer++;
            child++;
            Articulation(next, node, vis, disc, low, timer, graph, articulation_points);

            low[node] = min(low[node], low[next]);

            // Non-root articulation-point condition
            if (parent != -1 && disc[node] <= low[next]) {
                articulation_points.push_back(node);
            }
        }
    }

    // Root node special case: it is an articulation point if it has more than one DFS child
    if (parent == -1 && child > 1) {
        articulation_points.push_back(node);
    }
}

int main() {
    int n = 5;
    vector<vector<int>> graph(n);

    // Undirected unweighted graph: 0-1, 0-2, 1-3, 2-3, 2-4
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}};
    for (auto [u, v] : edges) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> vis(n, false);
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<int> articulation_points;
    int timer = 0;

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            Articulation(i, -1, vis, disc, low, timer, graph, articulation_points);
        }
    }


    cout << "Articulation points: ";
    if (articulation_points.empty()) {
        cout << "None\n";
    } else {
        for (int node : articulation_points) {
            cout << node << ' ';
        }
        cout << '\n';
    }

    return 0;
}