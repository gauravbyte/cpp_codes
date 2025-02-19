#include<bits/stdc++.h>
using namespace std;
/*
Grid Maximum Sum Path
Given a grid with integer values, start from (0,0) and reach the bottom-right index.
Constraints: Cannot pass through negative values (they act as roadblocks).
Objective: Return the maximum sum possible while traversing.
*/
int maxPathSum(vector<vector<int>> &grid){
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));

    if(grid[0][0] < 0) return -1; // Start is blocked

    dp[0][0] = grid[0][0];

    // Fill first row
    for(int j = 1; j < n; j++){
        if(grid[0][j] >= 0 && dp[0][j-1] != INT_MIN)
            dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // Fill first column
    for(int i = 1; i < m; i++){
        if(grid[i][0] >= 0 && dp[i-1][0] != INT_MIN)
            dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // Fill the rest of the grid
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(grid[i][j] >= 0){
                if(dp[i-1][j] != INT_MIN)
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + grid[i][j]);
                if(dp[i][j-1] != INT_MIN)
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
    }

    return dp[m-1][n-1] == INT_MIN ? -1 : dp[m-1][n-1];
}

int main(){
    vector<vector<int>> grid = {{1,2,3},{4, -1 ,6},{7,8,9}};
    int ans = maxPathSum(grid);
    cout << ans << endl;
    return 0;
}
