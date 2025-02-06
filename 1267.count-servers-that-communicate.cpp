/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> rowSum(row, 0);
        vector<int> colSum(col, 0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }
        int count = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                
            }
        }
        return count;
        
    }
};
// @lc code=end

