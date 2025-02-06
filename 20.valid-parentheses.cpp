/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int i;
        for(i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(s[i]==')' && st.top()=='('){
                    st.pop();
                }
                else if(s[i]==']' && st.top() =='['){
                    st.pop();
                }
                else if(s[i]=='}' && st.top() =='{'){
                    st.pop();
                }
                else{
                    return false;
                }

            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
// @lc code=end

