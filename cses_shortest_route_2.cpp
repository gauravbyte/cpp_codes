/* There are n cities and m roads between them. Your task is to process q queries
where you have to determine the length of the shortest route between two
given cities.

Input

The first input line has three integers n, m and q: the number of cities, roads,
and queries.

Then, there are m lines describing the roads. Each line has three integers a, b
and c: there is a road between cities a and 6 whose length is c. All roads are
two-way roads.

Finally, there are g lines describing the queries. Each line has two integers a and
b: determine the length of the shortest route between cities a and b.

Output

Print the length of the shortest route for each query. If there is no route, print
-1 instead.

Constraints

• 1 ≤ n ≤ 500
•1≤m≤n°
• 1 ≤ 9 ≤ 105
• 1≤ a, b≤n
• 1 ≤ c≤ 109

Example

Input:
4 3 5
1 2 5
139
2 3 3
12
2 1 13


 */

#include<bits/stdc++.h>

using namespace std;

//apply floyd warshall algorithm

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long int>> dist(n+1, vector<long long int>(n+1, 1e18));
    //distance to itself will be zero necessary condition
    for(int k=0; k<=n; k++){
        dist[k][k]=0;
    }
    for(int i=0; i<m; i++){
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }
    for(int k=1;k<=n; k++){
        for(int u=1; u<=n; u++){
            for(int v=1; v<=n; v++){
                dist[u][v] = min(dist[u][v],dist[u][k]+dist[k][v]);
            }
        }
    }
    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==1e18) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }
}