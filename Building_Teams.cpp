#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, int color, vector<int>adj[],vector<int> &team){
    if(team[node] != -1){
        if(team[node] != color){
            return false;
        }
        else{
            return true;
        }
    }
    team[node] = color;
    int ncolor = (color==1)?2:1;
    for(auto n: adj[node]){
        if(!dfs(n,ncolor,adj, team))return false;
    } 
    return true;  
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> team(n+1,-1);
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(team[i]!=-1) continue;
        int is_possible = dfs(i,1,adj,team);
        if(!is_possible){
            //! for(auto a: team) cout<<a<<" "; start with 1 for 1 based indexing    
            cout<<"IMPOSSIBLE"<<endl;
        }

    }
    for(int j=1; j<=n; j++){
        cout<<team[j]<<" ";
    }
    return 0;
}