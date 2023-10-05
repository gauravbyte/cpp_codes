// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem44.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {


public:
     int matcher(int is, int ip,string &s,string &p,vector<vector<int>> &dp){
        int ls = s.length();
        int lp = p.length();
        //current characters

        if(is==ls) return 1;
        char cs=s[is],cp=p[ip];
        if(ip==lp-1){
            if(cp=='*') return 1;
            else if(cp=='?'){
                if(is==ls-1) return 1;
                else return 0;
            }
            else{
                if(is==ls-1 && cs==cp) return 1;
                else return 0;
            }

        }
        // else if(is>=ls) return 0;
        //!did is instead of aip if(p[ip]=='?') return matcher(is+1,ip+1,s,p,dp);
        if(p[ip]=='?') return matcher(is+1,ip+1,s,p,dp);
        else if(p[ip]=='*'){
            if(dp[is][ip]!=-1) return dp[is][ip];
            int take = matcher(is+1,ip,s,p,dp);
            int not_take = matcher(is,ip+1,s,p,dp);
            return dp[is][ip]=take||not_take;
        }
        else{
            if(cs==cp) return matcher(is+1,ip+1,s,p,dp);
            else return 0;
        }
    }
    bool isMatch(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        vector<vector<int>> dp(ls+1,vector<int>(lp+1,-1));
        return matcher(0,0,s,p,dp);
    }
};
// @lc code=end

