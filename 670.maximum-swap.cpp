// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem670.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        int c=num;
        vector<int> digits;
        while(c>0){
            digits.push_back(c%10);
            c/=10;
        }
            reverse(digits.begin(),digits.end());
            priority_queue<pair<int,int>> pq;
            map<int,int> lastindex;
            for(int i=0; i<digits.size(); i++){
                lastindex[digits[i]] = i;
            }
            for(int i=0; i<digits.size(); i++){
                pq.push({digits[i],lastindex[digits[i]]});
            }
            for(int i=0; i<=digits.size(); i++){
                if(!pq.empty() && (digits[i] == pq.top().first || i>= pq.top().second)){
                    pq.pop();
                    continue;
                }
                if(!pq.empty() && digits[i]<pq.top().first ){
                    swap(digits[i],digits[pq.top().second]);
                    break;
                }
            }
                    reverse(digits.begin(),digits.end());

            int ans=0;
            int mul=1;
            for(auto a: digits){
                ans +=a*mul;
                mul*=10;
            }
            return ans;
        }
};
// @lc code=end

