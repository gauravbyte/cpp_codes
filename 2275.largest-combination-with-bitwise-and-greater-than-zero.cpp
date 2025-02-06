/*
 * @lc app=leetcode id=2275 lang=cpp
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int ans = 0;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int bitpos = 0;
            int num = candidates[i];
            while(num) {
                if(num % 2) {
                    mp[bitpos]++;
                }
                bitpos++;
                num /= 2;
            }
        }
        int mx = 0;
        for(auto a:mp) {
            mx = max(mx, a.second);
        }
        return mx;

    }
};
// @lc code=end

