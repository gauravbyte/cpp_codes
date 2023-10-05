/*
 * @lc app=leetcode id=2035 lang=cpp
 *Partition Array Into Two Arrays to Minimize Sum Difference
Category	Difficulty	Likes	Dislikes
algorithms	Hard (19.16%)	2592	144
Tags
Companies
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

 

Example 1:

example-1
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
Example 2:

Input: nums = [-36,36]
Output: 72
Explanation: One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
Example 3:

example-3
Input: nums = [2,-1,0,4,-2,-9]
Output: 0
Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
 

Constraints:

1 <= n <= 15
nums.length == 2 * n
-107 <= nums[i] <= 107
Discussion | Solution
 * [2035] Partition Array Into Two Arrays to Minimize Sum Difference
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    static const int MAX_N = 100;  // Adjust based on problem constraints
    static const int MAX_SUM = 10000;  // Adjust based on problem constraints
    int dp[MAX_N][MAX_SUM+1];

    Solution() {
        memset(dp, -1, sizeof(dp));
    }

int subset_sum(int ind, int target, vector<int>& arr){
    // Base cases
    if(target == 0) return 1;
    if(ind < 0 || target < 0) return 0;
    
    if(dp[ind][target] != -1)
        return dp[ind][target];
        
    bool take = false;
    if(arr[ind] <= target)
        take = subset_sum(ind-1, target-arr[ind], arr);
        
    bool not_take = subset_sum(ind-1, target, arr);
    
    return dp[ind][target] = take || not_take;
}


    int minimumDifference(vector<int>& nums) {
        int totSum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            totSum += nums[i];
        }

        subset_sum(n-1, totSum, nums); // Filling up the dp array

        int mini = 1e9; // use standard library constant for max value
        for(int i = 0; i <= totSum/2; i++){
            if(dp[n-1][i] == true){
                int diff = abs(i - (totSum - i));
                cout<<diff<<endl;
                mini = min(mini, diff);
            }
        }
        
        return mini;
    }
};

// @lc code=end

