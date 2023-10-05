/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int dp[5001][2][2];
    //always keep in bo
    int rec_buy(int index, int cooldown, int baught,vector<int>&price){
        if(index==price.size()){
            return 0;
        }
        if (dp[index][baught][cooldown] != -1) {
            return dp[index][baught][cooldown];
        }
        int profit=0;
        if(baught==0){
            if(cooldown==0)
            profit= max(-price[index]+rec_buy(index+1,0,1,price),rec_buy(index+1,0,0,price));
            if(cooldown==1){
                profit = rec_buy(index+1,0,0,price);
            }
        }
        else{
            profit = max(price[index]+rec_buy(index+1,1,0,price),rec_buy(index+1,0,1,price));
        }
        return dp[index][baught][cooldown]=profit;
        
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec_buy(0,0,0,prices);
    }
};
// @lc code=end

