/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        int sum=0;
        for(int i=0; i<m; i++){
            sum+=grid[i][0];
            dp[i][0] = sum;
        }   
        sum=0;       
        for(int i=0; i<n; i++){
            sum += grid[0][i];
            dp[0][i] = sum;
        }   
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] += grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
                //!used grid[i][j] instead of dp[i][j]
            }
        }  
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         // dp[i][j] += grid[i][j] + min(grid[i-1][j],grid[j][i-1]);
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }  
        return dp[m-1][n-1];        
    }
};
// @lc code=end

