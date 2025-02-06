//count  the number of nodes in subtree for each node
#include<bits/stdc++.h>
using namespace std;

int count_nodes(int u, int p, vector<int> adj[], vector<int> &count){
    int ans = 1;
    for(int v: adj[u]){
        if(v == p) continue;
        ans += count_nodes(v, u, adj, count);
    }
    count[u] = ans;
    return ans;
}
int soln(int A[], int B[], int n){
    vector<int> adj[n+1];
    vector<int> count(n,0);
    for(int i=0; i<n-1; i++){
        adj[A[i]].push_back(B[i]);
        // adj[B[i]].push_back(A[i]);
    }
    int sum  =0;
    for(int i=0; i<n; i++){
        count_nodes(i, -1, adj, count);
        sum += count[i];
    }
    return sum;
}
int main(){
    int n;
    int A[] = {5, 8, 4, 7, 3, 1, 2 };
    int B[] = { 6, 6, 6, 6, 7, 5 , 1};
    n = sizeof(A)/sizeof(A[0]);
    cout<<soln(A, B, n)<<endl;


}