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
bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathvis, vector<int> &storeDfs)
{
    storeDfs.push_back(node);
    vis[node]=1;
    pathvis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            // storeDfs.push_back(it);
            dfs(it,adj,vis,pathvis,storeDfs);
            //!full of errors in this approach
            //why storedfs not correct way to solve problem

        }
        else if(pathvis[it]==1)
        {
            storeDfs.push_back(it);
            return true;
        }
    }
    pathvis[node]=0;
    // storeDfs.pop_back();
    return false;
}

// }
int main()
{
    int m,n;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> vis(n+1,0);

    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        vector<int> pathvis(n+1,0);
        if(!vis[i]){
            vector<int> storeDfs;
            if(dfs(i,adj,vis,pathvis,storeDfs)){
                cout<<storeDfs.size()<<endl;
                cout<<"Cycle found"<<endl;
                for(auto it: storeDfs){
                    cout<<it<<" ";
                }
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    
}