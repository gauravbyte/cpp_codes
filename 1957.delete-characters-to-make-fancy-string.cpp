/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string makeFancyString(string s) {
        string res="";
        for(int i=0; i<s.size(); i++){
            if(i>1 && s[i]==s[i-1] && s[i]==s[i-2]){
                continue;
            }
            res += s[i];
        }
        return res;
    }
};
// @lc code=end

