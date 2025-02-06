/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue <int,vector<int>,less<int>> pq;
        for(auto n: nums){
            pq.push(n);
        }
        long long score =0;
        for(int i=0; i<k; i++){
            score += pq.top();
            int b = ceil(pq.top()/3.0);
            pq.pop();
            pq.push(b);
        }
        return score;
    }
};
// @lc code=end

