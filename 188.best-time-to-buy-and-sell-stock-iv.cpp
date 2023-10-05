/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int dp[10001][100][2];
int rec_buy(int index, int cap, int buy, vector<int>& prices) {
    if (index == prices.size() || cap == 0) {
        return 0;
    }
    if (dp[index][cap][buy] != -1) {
        return dp[index][cap][buy];
    }
    int ans = 0;
    if (buy == 1) {
        // You have already bought a stock before. You can sell it now.
        ans = max(prices[index] + rec_buy(index+1, cap - 1, 0, prices),
                  rec_buy(index +1, cap, 1, prices));
    } else {
        // You haven't bought a stock. You can buy it now.
        ans = max(-prices[index] + rec_buy(index +1, cap, 1, prices),
                  rec_buy(index +1, cap, 0, prices));
    }
    return dp[index][cap][buy] = ans;
}


    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec_buy(0,k,0,prices);
    }
};
// @lc code=end

