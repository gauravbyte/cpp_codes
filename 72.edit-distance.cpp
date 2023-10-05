/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public: 
    int rec_
    int minDistance(string word1, string word2) {
        int l1=word1.length();
        int l2=word2.length();
        int lcs_length=lcs(word1,word2);
        cout<<"l1"<<l1<<" l2"<<l2<<" lcs_length"<<lcs_length<<endl;
        return (max(l1,l2)-min(l1,l2))+l2-lcs_length;
    }
};
// @lc code=end

