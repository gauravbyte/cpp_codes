/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> result(row, vector<int>(col,-1));
        queue<pair<int,int>> q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(isWater[i][j] == 1){
                    result[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];
                if(x>=0 && x<row && y>=0 && y<col && result[x][y] == -1){
                    result[x][y] = result[curr.first][curr.second] +1;
                    q.push({x,y});
                }
            }
        }
        return result;
        
            
    }
};
// @lc code=end

