/*
 * @lc app=leetcode id=2661 lang=cpp
 *
 * [2661] First Completely Painted Row or Column
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        //iterate through matrix
        map<int, pair<int, int>, less<int> > mpindextoRowCol;
        vector<int> RowFilled(mat.size(), 0);
        vector<int> ColFilled(mat[0].size(), 0);

        for(int i=0; i<mat.size(); i++){
            int j=0;
            //iterate through row
            for(j=0; j<mat[i].size(); j++){
                //if the row is not completely painted
                mpindextoRowCol[mat[i][j]] = {i, j};
            }
            //if the row is completely painted
        }
        for(int i=0; i<arr.size(); i++){
            int row = mpindextoRowCol[arr[i]].first;
            int col = mpindextoRowCol[arr[i]].second;
            RowFilled[row]++;
            ColFilled[col]++;
            if(RowFilled[row] == mat[row].size() || ColFilled[col] == mat.size()){
                // cout<<"RowFilled["<<row<<"] = "<<RowFilled[row]<<endl;
                // cout<<"ColFilled["<<col<<"] = "<<ColFilled[col]<<endl;
                return i;
            }
        }
        return -1;

    }
};
// @lc code=end

