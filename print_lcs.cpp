#include<bits/stdc++.h>
using namespace std;

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			//!else was missing
			else
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int cr=n,cc=m;
	string ans="";
	//should be && instead of ||
	// for(int i=1; i<=n; i++){
	// 	for(int j=1; j<=m; j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
    
	while(cr!=0 && cc!=0 ){
		// !&& s1[cr-1] == s2[cc-1] condition was important

		if(dp[cr-1][cc-1]+1==dp[cr][cc] && s1[cr-1] == s2[cc-1]){
			//!ans+=s1[cr-1]; should append in reverse order instead
			ans=s1[cr-1] + ans;
			cc--;
			cr--;
		}
		else{
			if(dp[cr-1][cc]>=dp[cr][cc-1]){
				cr=cr-1;
			}
			else{
				cc--;
			}
		}
	}
	// cout<<ans;
	return ans;

}