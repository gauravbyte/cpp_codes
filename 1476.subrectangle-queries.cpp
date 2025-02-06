/*
 * @lc app=leetcode id=1476 lang=cpp
 *
 * [1476] Subrectangle Queries
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class SubrectangleQueries {
public: 
    int total_rows, total_cols;
    vector<vector<int>> rectangle;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        total_rows = rectangle.size();
        total_cols = rectangle[0].size();
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1-1;i<row2; i++){
            for(int j=col1-1; j<col2; j++){
                rectangle[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rectangle[row-1][col-1];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// @lc code=end

