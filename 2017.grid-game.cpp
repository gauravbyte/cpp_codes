/*
 * @lc app=leetcode id=2017 lang=cpp
 *
 * [2017] Grid Game
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<long long> prefixSumTop(col, 0);
        vector<long long> suffixSumBottom(col, 0);
        int maxScore1 = 0;
        int prev=0;
        for(int i=0; i<col; i++){
            prefixSumTop[i] = prev + grid[0][i];
            prev = prefixSumTop[i];
        }
        prev = 0;
        for(int j=col; j>=0; j--){
            suffixSumBottom[j] = prev + grid[1][j];
            prev = suffixSumBottom[j];
        }
        int index_break =0;
        for(int i=0; i<col; i++){
            if(prefixSumTop[i]+suffixSumBottom[i] > maxScore1){
                maxScore1 = prefixSumTop[i]+suffixSumBottom[i];
                index_break = i;
            }
        }
        long long maxScore2 = 0;
        //iterate through back first row till index break
        int sum1 = 0;
        for(int i=col-1; i>index_break; i--){

            sum1 += prefixSumTop[i];
        }
        //iterate through second row from index break
        int sum2 = 0;
        for(int i=0; i<index_break; i++){
            sum2 += suffixSumBottom[i];
        }
        return max(sum1, sum2);
        

    }
};

// @lc code=end

int main(){
    Solution sol;
    //[[20,3,20,17,2,12,15,17,4,15],[20,10,13,14,15,5,2,3,14,3]]
    vector<vector<int>> grid = {{20,3,20,17,2,12,15,17,4,15},{20,10,13,14,15,5,2,3,14,3}};
    cout<<sol.gridGame(grid)<<endl;
    return 0;
}