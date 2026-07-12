#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjlist; 

public:
    Graph(int size) {
        V = size;
        adjlist.resize(size);
    }

    void addEdge(int u, int v){
        //undirected  graph
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    void addEdges(vector<pair<int,int>> edges){ //{u,v}
        for(auto &edge : edges){
            addEdge(edge.first,edge.second);
        }
    }

    void bfs(int src,vector<bool>&vis){
        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while(!q.empty()){
            int node = q.front();
            cout<< node <<" ";
            q.pop();

            for(int i=0;i<adjlist[node].size();i++){
                int next = adjlist[node][i];

                if(!vis[next]){
                    q.push(next);
                    vis[next] = 1;
                }
            }
        }
        cout<<endl;
    }

    void dfs(int src , vector<bool>&vis){
        cout<<src<<" ";
        vis[src] = true;

        for(int i=0; i<adjlist[src].size();i++){
            int next = adjlist[src][i];
            if(!vis[next]){
                dfs(next,vis);
            }
        }
    }

    void display(){
        for(int i=0;i<adjlist.size();i++){
            cout<<i<<"->";
            for(int j=0;j<adjlist[i].size();j++){
                cout<<adjlist[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    Graph g(5);
    g.addEdges({{0,1},{0,4},{1,2},{1,3},{1,4},{2,3},{3,4}});

    vector<bool>vis(5,0);
    //g.bfs(0,vis);
    g.dfs(0,vis);
    cout<<endl;

    return 0;
}