#include<bits/stdc++.h>
using namespace std;
int choose(int player,int i,int j,vector<int> &a,vector<vector<int>> &dp)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j&&player==1){
        return dp[i][j]=a[i];
    }
    if(i+1==j){
        if(player==1)
        return max(a[i],a[j]);
        else
        return min(a[i],a[j]);
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(player==1){
        return dp[i][j]=max(a[i]+choose(2,i+1,j,a,dp),a[j]+choose(2,i,j-1,a,dp));
    }
    else{
        return dp[i][j]=min(choose(1,i+1,j,a,dp),choose(1,i,j-1,a,dp));
    }
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
    cout<<choose(1,i,j,a,dp)<<endl;

    //print dp
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}