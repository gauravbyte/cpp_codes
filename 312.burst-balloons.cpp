/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution {
public:
    int solve(int left ,int right, vector<int>&nums,vector<vector<int>>&dp){
        int ans=-1;
        //!forgot to write base case
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        //! trick is to start from the bottom
        for(int i=left; i<=right; i++){
            int cost= nums[i]*nums[left-1]*nums[right+1]+ solve(left,i-1,nums)+solve(i+1,right,nums);
            ans=max(ans,cost);
        }
        return dp[left][right]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return solve(1,n,nums);
    }
};
// @lc code=end

