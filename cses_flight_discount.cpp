/* Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You
have one discount coupon, using which you can halve the price of any single
flight during the route. However, you can only use the coupon once.
When you use the discount coupon for a flight whose price is a, its price
becomes [a/21 (it is rounded down to an integer).
Input
The first input line has two integers n and m: the number of cities and flight
connections. The cities are numbered 1, 2,...,n. City 1 is Syrjälä, and city n is
Metsälä.
After this there are m lines describing the flights. Each line has three integers a,
b, and c: a flight begins at city a, ends at city 6, and its price is c. Each flight is
unidirectional.
You can assume that it is always possible to get from Syrjälä to Metsälä.
Output
Print one integer: the price of the cheapest route from Syrjälä to Metsälä.
Constraints
• 2 ≤ n ≤ 10°
• 1 ≤ m ≤ 2 • 105
• 1≤a, b≤n
• 1≤ c≤ 10°
Example
Input:
3 4
1 2 3
2 3 1
137
2 1 5
Output:
2
2 */

#include<bits/stdc++.h>
using namespace std;

void min_cost(int from, vector<vector<pair<long long,int>>> &adj, vector<long long > &dist){
    priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,from});
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long > dist(n+1,INT64_MAX);
    vector<long long > revdist(n+1,INT64_MAX);
    vector<vector<pair<long long ,int>>> adj(n+1);
    vector<vector<pair<long long, int>>> revAdj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        revAdj[b].push_back({a,c});
    }
    dist[1]=0;
    revdist[n]=0;
    min_cost(1,adj,dist);
    min_cost(n,revAdj,revdist);
    long long  ans = dist[n];
    for(int city=1; city<=n; city++){
        for(auto [v,w]:adj[city]){
            if(dist[city]==INT64_MAX || revdist[v]==INT64_MAX) continue;
            ans = min(ans,dist[city]+w/2+revdist[v]);
        }
    }
    cout<<ans;
    return 0;


}