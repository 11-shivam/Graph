#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjMat;

public:
    Graph(int size) {
        V = size;
        adjMat.resize(size, vector<int>(size,0));
    }

    void addEdge(int wt , int u,int v){
        //Un-Directed Graph Weighted Graph
        adjMat[u][v] = wt;
        //adjMat[v][u] = wt;
    }

    void addEdges(vector<pair<int,pair<int,int>>> edges){ // {wt,{u,v}}
        for(auto &edge : edges){
            addEdge(edge.first, edge.second.first,edge.second.second);
        }
    }

    void display(){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cout<<adjMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    Graph g(5);
    g.addEdges({{5,{0,1}},{7,{1,2}},{3,{2,3}},{6,{3,4}},{2,{4,1}},{10,{1,3}}});

    g.display();

    return 0;
}