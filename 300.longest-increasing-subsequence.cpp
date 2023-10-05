/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
//! use prev as index because it will reduce the dp size

class Solution {
public:
    int dp[2501][2501];
    int lis(int i,int n,int prev,vector<int>& nums){
        if(i==n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int take=INT_MIN,not_take=INT_MIN;
        if(prev!=-1 && nums[i]>nums[prev]) take=1+lis(i+1,n,nums[i],nums);
        not_take=lis(i+1,n,prev,nums);
        return dp[i][prev] = max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp) );
        nums.insert(nums.begin(),INT_MIN);
        return lis(1,nums.size(),0,nums)-1;

    }
};
// @lc code=end

