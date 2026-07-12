#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph {
    int V;
    vector<vector<int>> adj;

public:
    graph(int vertices){
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void addEdges(vector<pair<int,int>> edges){
        for(auto &edge : edges){
            addEdge(edge.first,edge.second);
        }
    }


    bool isCycleBFS(int node,int parent){
        vector<bool>vis(V,false);
        queue<pair<int,int>>q; // node : parent;
        q.push({node,parent});
        vis[node] = true;

        while(!q.empty()){
            node = q.front().first;
            parent = q.front().second;
            q.pop();

            for(int i=0;i<adj[node].size();i++){
                int next = adj[node][i];
                if(!vis[next]){
                    vis[next] = true;
                    q.push({next,node});
                } else if(next != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCylceDFS(int node , int parent,vector<bool>&vis){
        vis[node] = true;

        for(int i=0;i<adj[node].size();i++){
            int next = adj[node][i];

            if(!vis[next]){
                if(isCylceDFS(next,node,vis)) return true;
            }else if(next != parent) return true;
        }
        return false;
    }

    string isCycle(){
        vector<bool>vis(V,false);
        return isCycleBFS(0,-1)? "Cycle found" : "Cycle not found";
    }
};

int main(){
    graph g(9);

    g.addEdges({{0,1},{1,2},{2,3},{3,4},{4,6},{4,5},{2,7},{7,8},{2,5}});

    cout<<g.isCycle()<<endl;

    return 0;
}