#include<bits/stdc++.h>
using namespace std;

int32_t  main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<long long int> dist(n+1,1e18);
    //! not requiered for the vgiven array which is  vector<int> vis(n+1,0);
    // vector<int> vis(n+1,0);
    dist[1]=0;
    priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>> pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        int node = pq.top().second;
        long long int  sdist = pq.top().first;
        // vis[node]=1;
        pq.pop();
        //!if sdist is greater than the dist[node] then it means that the node is already visited
        //! so we dont need to visit it again
        //! this condition was giving tle
        if(sdist>dist[node]) continue;
        for(auto k: adj[node]){
            int neighbour = k.first;
            int weight = k.second;
            if(sdist+weight<dist[neighbour]){
                dist[neighbour]=sdist+weight;
                pq.push({dist[neighbour],neighbour});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

}