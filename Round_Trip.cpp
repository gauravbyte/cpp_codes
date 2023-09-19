/* Byteland has n
 cities and m
 roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.

Input

The first input line has two integers n
 and m
: the number of cities and roads. The cities are numbered 1,2,…,n
.

Then, there are m
 lines describing the roads. Each line has two integers a
 and b
: there is a road between those cities.

Every road is between two different cities, and there is at most one road between any two cities.

Output

First print an integer k
: the number of cities on the route. Then print k
 cities in the order they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤105

1≤m≤2⋅105

1≤a,b≤n

Example

Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3 */
#include<bits/stdc++.h>

using namespace std;
//!lot of errors in dfs approach because we need to keep track of the route and 
//!doesn't make sure our code is optiomal or nato
//we have to find the cycle and print the cycle
bool dfs_is_cycle(int node, vector<vector<int> > adj, vector<int> &vis, vector<int> &pathvis, vector<int> &parentof)
{
    if(vis[node]==1 ){
        if( pathvis[node]==1)
            //cycle found
            return true;
        else 
            return false;  
    }
    pathvis[node]=1;
    vis[node]=1;
    for(auto it:adj[node]){

        parentof[it]=node;
        if(dfs_is_cycle(it,adj,vis,pathvis,parentof))
            return true;
    }
    pathvis[node]=0;
    return false;

    
}

// }
int main()
{
    int m,n;
    cin>>n>>m;
    vector<vector<int> > adj(n+1);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        vector<int> pathvis(n+1,0);
        vector<int> vis(n+1,0);
        vector<int> parent(n+1,-1);
        if(!vis[i]){
            parent[i] = -1;//remember this
            if(dfs_is_cycle(i,adj,vis,pathvis,parent)){
                vector<int> cycle;
                cycle.push_back(i);
                int x = parent[i];
                while(x!=i){
                    cycle.push_back(x);
                    x = parent[x];
                }
                cycle.push_back(i);
                reverse(cycle.begin(),cycle.end());
                cout<<cycle.size()<<endl;
                for(auto it:cycle)
                    cout<<it<<" ";
                cout<<endl;
                return 0;
            }
            
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    
}