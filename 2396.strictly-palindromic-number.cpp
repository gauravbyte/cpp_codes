/*
 * @lc app=leetcode id=2396 lang=cpp
 *
 * [2396] Strictly Palindromic Number
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(int number,int base){
        vector<int> remainders;
        int num = number;
        while(num){
            int remainder =  num%base;
            num = num/base;
            remainders.push_back(remainder);
        }
        int left=0;
        int right=remainders.size()-1;
        while(left<=right){
            if(remainders[left]!=remainders[right]){
                return false;
            }
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2; i<=n-2; i++ ){
            if(!isPalindrome(n,i)){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

