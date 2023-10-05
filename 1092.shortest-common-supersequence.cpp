/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string lcs(string s1,string s2){
        int m=s1.length(),n=s2.length();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        string ans="";
        int i=m,j=n;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    j--;
                }
                else{
                    i--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        string lc = lcs(str1, str2);
        string ans="";
        int i1=0,i2=0;
        cout<<lc<<endl;
        for(char c:lc){
            while(str1[i1]!=c){
                ans+=str1[i1];
                i1++;
            }
            while(str2[i2]!=c){
                ans+=str2[i2];
                i2++;
            }
            ans+=c;
            i1++;
            i2++;
        }
        while(i1<str1.length()){
            ans+=str1[i1];
            i1++;
        }
        while(i2<str2.length()){
            ans+=str2[i2];
            i2++;
        }
        return ans;
        
        

    }
};
// @lc code=end

