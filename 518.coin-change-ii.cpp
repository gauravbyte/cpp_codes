// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem518.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */
// #include<bits/stdc++.h>
// using namespace std;

// @lc code=start
int dp[301][5000];
class Solution {
public:
    int coin_exchange(int amount, int index, vector<int> &coins){
        if(amount==0) return 1;
        if(index==0){
            if(amount%coins[0]==0){
                return 1;
            }
            else return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        // ! should be <= if(coins[index]>=amount){
        if(coins[index]<=amount){
            take = coin_exchange(amount-coins[index],index,coins);
        }
        not_take = coin_exchange(amount,index-1,coins);
        return dp[index][amount]= take+non_take;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp)
        int n=coins.size();
        return coin_exchange(amount,n-1, coins);

    }
};
// @lc code=end

