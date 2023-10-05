/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
    class Solution {
    public:
        int is_pred(string &s1, string&s2){
            int l1 = s1.length();
            int l2= s2.length();
            if(l2-l1!=1)  return false;
            int i1=0,i2=0,flag=0;
            while(i1<l1 && i2<l2 && flag<=1){
                if(s1[i1]!=s2[i2]){
                    i2++;
                    flag++;
                }
                i1++;
                i2++;
            }
            if(flag<=1 && i1==l1-1 && i2 ==l2-1)
                return true;
            else 
                return false;

        }
        bool customCompare(const string &a, const string &b ){
            if(a.length()!= b.length()){
                return a.length()< b.length();
            }
            return a<b;
        }
        int longestStrChain(vector<string>& words) {
            vector<int> dp(words.size(),0);
            sort(words.begin(),words.end(),customCompare);
            int max_len=0;
            for(int i=0; i<words.size(); i++){
                for(int j=i; j>=0; j--){
                    if(words[j].length()==words[i].length()-1){
                        if(is_pred(words[j],words[i])){
                            dp[i]=max(dp[i],dp[j]+1);
                        }
                    }
                }
                max_len=max(max_len,dp[i]);
            }
            return max_len;
        }
    };
// @lc code=end

