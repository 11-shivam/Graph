#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adjlist; // u -> v ,wt

public:
    Graph(int size) {
        V = size;
        adjlist.resize(size);
    }

    void addEdge(int wt,int u, int v){
        //undirected  weighted graph
        adjlist[u].push_back({v,wt});
        adjlist[v].push_back({u,wt});
    }

    void addEdges(vector<pair<int,pair<int,int>>> edges){ //{wt,{u,v}}
        for(auto &edge : edges){
            addEdge(edge.first,edge.second.first,edge.second.second);
        }
    }

    void display(){
        for(int i=0;i<adjlist.size();i++){
            cout<<i<<"->";
            for(int j=0;j<adjlist[i].size();j++){
                cout<<"{"<<adjlist[i][j].first<<","<<adjlist[i][j].second<<"}"<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    Graph g(3);
    g.addEdges({{3,{0,1}},{4,{0,2}},{5,{1,2}}});

    g.display();

    return 0;
}