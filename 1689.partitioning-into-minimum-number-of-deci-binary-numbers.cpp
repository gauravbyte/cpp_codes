/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPartitions(string n) {
        int mx= INT_MIN;
        for(auto a: n){
            mx=max(mx,a-'0');
        }
        return mx;
    }
};
// @lc code=end

