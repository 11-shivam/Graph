#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph {
    int V;
    vector<vector<int>> adj;

public :
    graph(int vertices){
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void addEdges(vector<pair<int,int>> edges){
        for(auto & edge : edges){
            addEdge(edge.first,edge.second);
        }
    }

    bool dfs(int node,vector<bool>&path, vector<bool>&vis){
        vis[node] = true;
        path[node] = 1;

        for(int i=0;i<adj[node].size();i++){
            int next = adj[node][i];

            if(path[next]) return true;

            if(!vis[next]) {
                if(dfs(next , path ,vis)) return true;
            }
        }
        path[node] = 0;
        return false;
    }

    string isCycle(){
        vector<bool>path(V,0);
        vector<bool>vis(V,0);

        return dfs(0,path,vis)? "Cycle found" : "Cyle not found";
    }
};

int main() {
    graph g(9);

    g.addEdges({{0,1},{1,2},{2,7},{7,8},{5,2},{2,3},{3,4},{4,5},{4,6}});

    cout<<g.isCycle()<<endl;
    return 0;
}