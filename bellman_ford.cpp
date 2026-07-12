#include<iostream>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> graph;

    public:
    Graph(int size){
        V = size;
        graph.resize(size);
    }

    void addEdge(int u,int v, int wt){
        graph[u].push_back({v,wt}); //Directed Weighted Graph
    }

    void addEdges (vector<pair<int,pair<int,int>>> edges){
        for(auto & edge : edges){
            addEdge(edge.first,edge.second.first,edge.second.second);
        }
    }

    void bellMan_ford(int node,vector<int>&dist){
        //Convert graph into edges
        vector<pair<int,pair<int,int>>> edges;

        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int u = i;
                int v = graph[i][j].first;
                int wt = graph[i][j].second;

                edges.push_back({u,{v,wt}});
            }
        }


        //Mark distance of source node to 0
        dist[node] = 0;

        for(int i=0; i<V-1;i++){
            //Optimization
            bool flag = false; // tracks is distance updated or not
            //Edge Relaxation
            for(int j=0 ; j<edges.size();j++){
                int u = edges[j].first;
                int v = edges[j].second.first;
                int wt = edges[j].second.second;

                if(dist[u] == INT_MAX) continue;

                if(dist[v] > dist[u] + wt){
                    dist[v] =  dist[u] + wt;
                    flag = true;
                }
            }

            if(flag == false) break;
            //No change in distances it means all distances are final
        }


        //Negative Cycle Detection Step
        do{
            bool flag = false;
            //Edge Relaxation
            for(int j=0 ; j<edges.size();j++){
                int u = edges[j].first;
                int v = edges[j].second.first;
                int wt = edges[j].second.second;

                if(dist[u] == INT_MAX) continue;

                if(dist[v] > dist[u] + wt){
                    dist[v] =  dist[u] + wt;
                    flag = true;
                }
            }

            if(flag == true) cout<<"Negative Cycle Present"<<endl;
        } while(false);
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

};

int main() {
    Graph g(5);

    g.addEdges({{0,{1,5}} , {1,{3,2}} , {1,{2,1}} , {2,{4,1}} , {4,{3,-1}}});
    g.display();

    vector<int>dist(5,INT_MAX);
    int node  = 0;
    g.bellMan_ford(node,dist);

    for(int i=0;i<5;i++) cout<<dist[i]<<" ";
    cout<<endl;


    return 0;
}