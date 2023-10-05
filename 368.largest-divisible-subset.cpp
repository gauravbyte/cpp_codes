/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // int dp[1001][1001];
    int divisible_recc(int index,int divider,vector<int> &nums,vector<vector<int>> &dp){
        if(index==nums.size()) return 0;
        if(dp[index][divider]!=-1) return dp[index][divider];
        int take=INT_MIN,not_take=INT_MIN;
        if(nums[index]%nums[divider]==0) {
            // divider = (nums[index]>nums[divider])?index:divider;
        
            take=1+divisible_recc(index+1,index,nums,dp);
        }
        not_take=divisible_recc(index+1,divider,nums,dp);
        return dp[index][divider]=max(take,not_take);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        //print dp
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return nums;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> nums={1,2,3};
    //print nums
    for(auto i:nums) cout<<i<<" ";
    cout<<endl;
    sol.largestDivisibleSubset(nums);
    //print
    return 0;
}
