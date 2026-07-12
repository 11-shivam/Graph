#include <iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

class graph {
    int V;
    vector<vector<int>> adj;  

public:
    graph(int vertices) {
        V = vertices;
        adj.resize(V);  
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); 
    }


    void addEdges(vector<pair<int, int>> edges) {
        for (auto& edge : edges) {
            addEdge(edge.first, edge.second);
        }
    }

    void dfs(int node , vector<bool>&vis,stack<int>&st){
        vis[node] = true;

        for(int i=0;i<adj[node].size();i++){
            int next = adj[node][i];

            if(!vis[next]){
                dfs(next,vis,st);
            }
        }
        st.push(node);
    }

    void Kahns_algorithm(){
        vector<int>inDegree(V,0);

        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                int next = adj[i][j];
                inDegree[next]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(!inDegree[i]) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(int i=0;i<adj[node].size();i++){
                int next = adj[node][i];
                inDegree[next]--;
                if(!inDegree[next]) q.push(next);
            }
        }

        cout<<"Kahn's Algorithm : ";
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

        cout<<endl;
    }

    void topologicalSort(){
        stack<int>st;
        vector<bool>vis(V,false);

        for(int i=0;i<adj.size();i++){
            if(!vis[i]) dfs(i,vis,st);
        }

        cout<<"Topological sort : ";
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
};

int main() {
    graph g(9);
    g.addEdges({{0,1},{1,2},{2,7},{7,8},{2,5},{2,3},{3,4},{5,4},{4,6}});

    g.topologicalSort();
    g.Kahns_algorithm();
    return 0;
}