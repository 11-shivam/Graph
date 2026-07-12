#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(const vector<vector<pair<int,int>>> &graph, vector<vector<int>> &dist) {
    int n = graph.size();
    dist.assign(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[i].size();j++){
            int u = i;
            int v = graph[i][j].first;
            int wt = graph[i][j].second;

            dist[u][v] = wt;// for atmost one directed edge b/w u to v\
            //dist[u][v] = min(dist[u][v],wt) if theres multiple edge from u to v;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k] == INT_MAX) continue;
            for (int j = 0; j < n; j++) {
                if (dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool negativeCycle = false;
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            negativeCycle = true;
            break;
        }
    }
    if (negativeCycle) {
        cout << "Negative Cycle" << endl;
    }
}

int main() {
    int n = 6;
    vector<vector<pair<int,int>>> graph(n);
    vector<vector<int>> dist;

    graph[0].push_back({1, 5});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 6});
    graph[2].push_back({3, 7});
    graph[2].push_back({4, 4});
    graph[2].push_back({5, 2});
    graph[3].push_back({4, -1});
    graph[4].push_back({5, -2});

    floydWarshall(graph, dist);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "*  ";
            } else {
                cout << dist[i][j] << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
