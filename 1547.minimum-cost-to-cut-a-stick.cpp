/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    int solve(int l,int r, vector<int>& cuts, vector<vector<int>>& dp){
        //base case
        if(l>r){
            return 0;
        }
        int ans=INT_MAX;
        for(int index=l; index<=r; index++){
            if(dp[l][r]!=-1){
                return dp[l][r];
            }
            int cost = cuts[r+1]-cuts[l-1]+solve(l,index-1,cuts,dp)+solve(index+1,r,cuts,dp);
            ans=min(ans,cost);
        }
        
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        return solve(1, cuts.size()-1, cuts, dp);
    }
};
// @lc code=end

