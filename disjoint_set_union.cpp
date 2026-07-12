#include<iostream>
using namespace std;

class DisjointSet {

    int size;
    vector<int> parent,rank;

    DisjointSet(int size){
        this->size = size;

        for(int i=0; i<size;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    
    int findParent(int u){
        if(u == parent[u]) return u; 
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u,int v){
        int par_u = findParent(u);
        int par_v = findParent(v);

        if(rank[par_u] == rank[par_v]){
            parent[par_u] = parent[par_v];
            rank[par_v] ++;
        }else if( rank[par_u] < rank[par_v]){
            parent[par_u] = parent[par_v];
        } else {
            parent[par_v] = parent[par_u];
        }
    }
    
};

int main (){
    return 0;
}