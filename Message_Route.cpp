/*Syrjälä's network has n
 computers and m
 connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.

Input

The first input line has two integers n
 and m
: the number of computers and connections. The computers are numbered 1,2,…,n
. Uolevi's computer is 1
 and Maija's computer is n
.

Then, there are m
 lines describing the connections. Each line has two integers a
 and b
: there is a connection between those computers.

Every connection is between two different computers, and there is at most one connection between any two computers.

Output

If it is possible to send a message, first print k
: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.

If there are no routes, print "IMPOSSIBLE".

Constraints
2≤n≤105

1≤m≤2⋅105

1≤a,b≤n

Example

Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<pair<int,int>> q;
    vector<int> parent(n+1,0);
    vector<int> dist(n+1,-1);
    // q.push({1,0}) semicolon missing
    q.push({1,0});
    parent[1]=-1;
    dist[1]=0;
    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        for(auto a: adj[node]){
            if(dist[a]!=-1){
                continue;
            }
            dist[a]=d+1;
            parent[a]=node;
            q.push({a,d+1});
        }
    }
    if(dist[n]==-1)
    {
        cout<<"IMPOSSIBLE";
    }
    else{
        vector<int> ans;
        int p=n;
        cout<<dist[n]+1<<endl;
        while(p!=-1){
            ans.push_back(p);
            p=parent[p];
        }
        //either you can reverse the string or
        //you can print it in reverse order
        for(int i=ans.size()-1; i>=0; i--){
            cout<<ans[i]<<" ";
        }
    }
}