/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        vector<int> ans;
        int i=0,j=0;
        int dir=0;
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
                dir=1;

            }
            else if(dir==1){
                for(int i=top; i<= bottom; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
                dir=2;
            }
            else if(dir==2){
                for(int i=right;i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir=3;
            }
            else if(dir==3){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                dir=0;
            }
        }
        return ans;
    }
};
// @lc code=end

