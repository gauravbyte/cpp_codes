/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // Helper function to recursively pick a pile
    int pickPile(bool isAlice, vector<int>& piles, int start, int end, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }
        if(dp[start][end] != 0){
            return dp[start][end];
        }
        int pickStart = piles[start] - pickPile(!isAlice, piles, start + 1, end, dp);
        int pickEnd = piles[end] - pickPile(!isAlice, piles, start, end - 1, dp);
        dp[start][end] = max(pickStart, pickEnd);
        return dp[start][end];
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        int scoreDifference = pickPile(true, piles, 0, n - 1, dp);

        return scoreDifference > 0; // Alice wins if her score is positive
    }
};
// @lc code=end

