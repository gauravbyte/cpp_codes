#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int par, vector<int>adj[],vector<int> &visited,vector<int> &parent){
    visited[node]=1;
    parent[node]=par;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(it,node,adj,visited,parent)) return true;
        }
        else if(it != par){
            stack<int> cycle;
            cycle.push(node);
        }
    }
}
int main(){
    int m,n;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>visited(n+1,0);
    vector<int>parent(n+1,0);
    for(int i=0; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
    if(!visited[i] && dfs(i,-1,adj,visited,)
  
}  }