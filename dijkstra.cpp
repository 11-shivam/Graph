#include<iostream>
#include<queue>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>>graph;

    public:
    Graph(int size){
        V = size;
        graph.resize(size);
    }

    void addEdge(int u,int v,int wt){
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }

    void addedges(vector<pair<int,pair<int,int>>> edges){ // {u,{v,wt}}; 
        for(auto edge : edges){
            addEdge(edge.first,edge.second.first,edge.second.second);
        }
    }

    void display(){

        for(int i=0;i<V;i++){
            cout<< i <<"-->"<<" ";
            for(int j=0;j<graph[i].size();j++){
                int u = i;
                int v = graph[i][j].first;
                int wt = graph[i][j].second;

                cout<<'{'<<v<<','<<wt<<'}';
            }
            cout<<endl;
        }
    }

    void dijkstra(int src,vector<int> &dist){
        vector<bool> vis(V,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {shortest dis, node}
        
        pq.push({0,src});
        dist[src] = 0;
        

        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            if(vis[node]) continue;
            vis[node] = true; // marking true here coz now I am sure that this node will have shortest distance
            

            for(int j=0;j<graph[node].size();j++){
                int next = graph[node][j].first;
                int wt = graph[node][j].second;

                if(dist[node] == INT_MAX) continue;

                if(dist[next] > dist[node] + wt){
                    dist[next] =  dist[node] + wt;
                    pq.push({dist[next],next});
                }
                
            }
        }
    }
};

int main () {

    Graph g(6);
    g.addedges({{0,{1,6}} , {0,{2,2}} , {1,{3,7}}, {1,{2,3}} , {2,{4,4}} , {3,{5,2}} , {3,{4,5}}, {4,{5,9}}});
    //g.display();

    vector<int> dist(6,INT_MAX);
    g.dijkstra(0,dist);

    for(int i=0;i<6;i++ ) cout<<dist[i] <<" ";
    cout<<endl;

    return 0;
}