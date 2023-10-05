/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
int lcs(string &s1, string &s2,vector<vector<int>> &dp) {
    int m = s1.length(), n = s2.length();
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1]==s2[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int dfs_count_all_possible_lcs(string &s1,string &s2,int curr,int curc,vector<vector<int>> &dp){
    if(curr==0 || curc==0){
        return 1;
    }
    //go up
    int up=0,left=0,digonal=0;
    if(s1[curr-1]==s2[curc-1]){
         digonal = dfs_count_all_possible_lcs(s1,s2,curr-1,curc-1,dp);
    }
    else
    {
        if(max(dp[curr-1][curc],dp[curr][curc-1])==dp[curr-1][curc]){
            up = dfs_count_all_possible_lcs(s1,s2,curr-1,curc,dp);
        }
        //go left
        if(max(dp[curr-1][curc],dp[curr][curc-1])==dp[curr-1][curc]){
            left= dfs_count_all_possible_lcs(s1,s2,curr,curc-1,dp);
        }
    }
    return up+left+digonal;
    
}
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<=m; i++) {
            dp[i][0] = 1;
        }
        lcs(s, t, dp);
        return dfs_count_all_possible_lcs(s,t,m,n,dp);
    }
};
// @lc code=end
