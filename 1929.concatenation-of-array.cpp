/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(2*n);
        for(int i=0; i<n; i++){
            arr[i] = arr[i+n] = nums[i];
        }
        return arr;
    }
};
// @lc code=end

