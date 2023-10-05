// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem494.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
int dp[21][2001];
int dp_negative[21][2001];
class Solution {
public:

    int subset_sum(int index,int target,vector<int>&nums){
        if(index==nums.size()){
            if(target==0) return 1;
            else return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int take=0,not_take=0;
        if(nums[index]<=target){
            take=subset_sum(index+1,target-nums[index],nums);
        }
        not_take=subset_sum(index+1,target,nums);
        return dp[index][target]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        //!handle if target is greater than sum
        if(target>sum) return 0;
        //!handle negative numbers
        if(arget<-sum) return 0;
        //!handle if sum+target is odd
        if((sum+target)%2!=0) return 0;
        int s1=(sum+target)/2;
        memset(dp,-1,sizeof(dp));
        return subset_sum(0,s1,nums);
    }
};
// @lc code=end

