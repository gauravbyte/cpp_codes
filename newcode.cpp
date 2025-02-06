#include<bits/stdc++.h>
using namespace std;
int choose(int i,int j,vector<int> &a,vector<vector<int>> &dp)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j) {
        return a[i];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ll = -1e9, lr = -1e9, rl = -1e9, rr = -1e9;
    ll = a[i] + choose(i+2, j, a, dp);
    lr = a[i] + choose(i+1, j-1, a, dp);
    rl = a[j] + choose(i+1, j-1, a, dp);
    rr = a[j] + choose(i, j-2, a, dp);
    return dp[i][j] = max(min(ll, lr), min(rl, rr));
}
int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        a.push_back(k);
    }
    int i=0,j=n-1;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<choose(i,j,a,dp)<<endl;

    //print dp
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}