/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    static bool compareIntervals(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    bool checkOverlap(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return a[1] > b[0];
        } else if (a[0] > b[0]) {
            return b[1] > a[0];
        } else {
            return false;
        }
    }

    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareIntervals);
        int newEnd = intervals[0][1];
        int count = 0;
        int groups = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < newEnd) {
                count++;
            } else {
                count--;
            }
            groups = max(count, groups);
            newEnd = max(intervals[i][1], newEnd);
        }
        return groups;
    }
};
// @lc code=end