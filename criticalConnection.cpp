#include<iostream>
using namespace std;

void dfs(int node ,int parent,vector<int>&disc,vector<int>&low,int&timer,vector<bool>&vis,vector<vector<int>>&graph,vector<vector<int>>&critical_connections){
        
    vis[node] = true;
    disc[node] = timer;
    low[node] = timer;
        
    for(int i=0;i<graph[node].size();i++){
        int next = graph[node][i];
            
        if(next == parent) continue;
        if(vis[next] ){
            low[node] = min (low[node] ,disc[next]);
        }else {
            timer++;
            dfs(next,node,disc,low,timer,vis,graph,critical_connections);
                
            //backtracking
            low[node] = min(low[node] , low[next]);
            if(disc[node] < low[next]){
                critical_connections.push_back({node,next});
            }
        }       
    }     
}

int main(){ 

                        //<-----Problem Statement------>

//There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a         network  where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.


    int n = 4; // number of vertices;
    vector<vector<int>> connections ({{0,1},{1,2},{2,0},{1,3}});
    vector<vector<int>> graph;
    graph.resize(n);
        
    for(int i=0;i<connections.size();i++){
        int u = connections[i][0];
        int v = connections[i][1];
            
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
        
    vector<bool> vis(n,0);
    vector<int>disc(n,-1);
    vector<int> low(n,-1);
    int timer =0;
    int node =0;
    int parent = -1;
        
    vector<vector<int>> critical_connections;
        
    dfs(node ,parent,disc, low, timer ,vis , graph , critical_connections);
        
    return 0;
}