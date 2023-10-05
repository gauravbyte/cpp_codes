/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lcs(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
    int minInsertions(string s) {
        string lefts ="";
        string rights=s;
        int min_insertions = 0;
        for(int i=0; i<s.length(); i++){
            lefts += s[i];
            rights = s.substr(i+1);
            int subsequence_length = lcs(lefts, rights);
            min_insertions = min(min_insertions, ((int)s.length())-subsequence_length);
        }
        return min_insertions;
    }
};
// @lc code=end

