/*
 * @lc app=leetcode id=2658 lang=cpp
 *
 * [2658] Maximum Number of Fish in a Grid
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || visited[i][j]==1){
            return 0;
        }
        visited[i][j] = 1;
        int up = dfs(grid, visited, i-1, j);
        int down = dfs(grid, visited, i+1, j);
        int left = dfs(grid, visited, i, j-1);
        int right = dfs(grid, visited, i, j+1);
        return 1+up+down+left+right;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxFish = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    maxFish = max(maxFish, dfs(grid, visited, i, j));
                }
            }
        }
        return maxFish;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}};
    cout<<sol.findMaxFish(grid);
    return 0;
}
