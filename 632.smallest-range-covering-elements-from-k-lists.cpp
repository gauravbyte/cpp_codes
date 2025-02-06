// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem632.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<vector<int>> arr = nums;
        int left = INT_MIN;
        int right = INT_MAX;

        while (true) {
            // Find the maximum of the first elements and minimum of the last elements
            for (int i = 0; i < arr.size(); i++) {
                left = max(left, arr[i][0]);
                right = min(right, arr[i].back());
            }
            // Check if the current left and right define the smallest range
                for (int i = 0; i < arr.size(); i++) {
                if (arr[i].size() == 1) {
                    // If any sub-array has only one element left and it matches the bounds
                    if (arr[i][0] == left || arr[i][0] == right) {
                        return {left, right};
                    }
                }
            }
            // Erase elements that are outside the current range
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i][0] < left) {
                    arr[i].erase(arr[i].begin());
                }
                if (arr[i].back() > right) {
                    arr[i].pop_back();
                }
            }
        }
        // Return the final range
        return {left, right};
    }
};

// @lc code=end

