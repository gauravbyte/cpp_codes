#include <bits/stdc++.h> 
using namespace std;
int dp[101][1001];

int tnt(int w,int i,int profit,vector<int>&weight, vector<int> &value){
	if(i<0) return profit;
	if(dp[i][w]!=-1) return dp[i][w];
	int take=0,not_take;
	if(weight[i]<=w){
		take=tnt(w-weight[i],i-1,profit+value[i],weight,value);
	}
	not_take = tnt(w,i-1,profit,weight,value);

	return dp[i][w] = max(take,not_take);
	

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	memset(dp,-1,sizeof(dp));
	return tnt(maxWeight,n-1,0,weight,value);
}
/* Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13 */
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>weight(n);
        vector<int>value(n);
        for(int i=0; i<n; i++){
            cin>>weight[i];
        }
        for(int i=0; i<n; i++){
            cin>>value[i];
        }
        int maxWeight;
        cin>>maxWeight;
        cout<<knapsack(weight,value,n,maxWeight)<<endl;
    }
}