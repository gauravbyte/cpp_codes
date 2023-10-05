// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem494.h"

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
int dp_positive[21][2001];
int dp_negative[21][2001];
class Solution {
public:
    int findTargetSumWaysUtil(vector<int>& nums,int index,int target){
        if(index==0){
            // if(target==0)
            //     return 2;
            else if(target == nums[index])
                return 1;
            else if(-target == nums[index])
                return 1;
            else return 0;
        }
        int add=0,sub=0;
        // if(target>=nums[index])
        if(target>=0){
            if(dp_positive[index][target]!=-1) return dp_positive[index][target];
        }
        else{
            if(dp_negative[index][abs(target)]!=-1) return dp_negative[index][-target];
        }
        add = findTargetSumWaysUtil(nums,index-1,target-nums[index]);
        // ! should not come in else condition
        sub = findTargetSumWaysUtil(nums,index-1,target+nums[index]);
        
        if(target>=0){
            return dp_positive[index][target] = add+sub;
        }
        else{
            return dp_negative[index][abs(target)] = add+sub;
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp_positive,-1,sizeof(dp_positive));
        memset(dp_negative,-1,sizeof(dp_negative));
        int n=nums.size();
        return findTargetSumWaysUtil(nums,n-1,target);
    }
};
// @lc code=end

