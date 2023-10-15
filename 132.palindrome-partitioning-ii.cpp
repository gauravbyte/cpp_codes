/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */
#include<bits/stdc++.h>
using namespace std;


// @lc code=start
            class Solution {
                int dp[2001][2001];
            public:
                //! &s did not work here
                bool is_palindrome(string s){
                    int l=0,r=s.size()-1;
                    while (l<r)
                    {
                        if(s[l]!=s[r])return false;
                        l++;
                        r--;
                    }
                    return true;
                }
                int solve(int l,int r,string &s){
                    if(l>=r) return 0;
                    if(dp[l][r]!=-1)return dp[l][r];
                    if(is_palindrome(s.substr(l,r-l+1)))return dp[l][r]=0;
                    
                    int ret=INT_MAX;
                    for(int i=l;i<r;i++){
                        if(is_palindrome(s.substr(l,i-l+1)))
                            ret=min(ret,1+solve(l,i,s)+solve(i+1,r,s));
                    }
                    return ret;
                }
                int minCut(string &s) {
                    memset(dp,-1,sizeof(dp));
                    return solve(0,s.size()-1,s);
                }   
            };
// @lc code=end

