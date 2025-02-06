// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem862.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        //including elements finding the minimum length subarray whose sum is atleast k 
        //
        priority_queue  <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0,-1));//for the first element we have to take care of this condititon
        int cur_sum=0;
        int min_range =-1;
        for(int i=0; i<nums.size(); i++){
            cur_sum += nums[i];
            while(!pq.empty()){
                int min_prefix = pq.top().first;
                int min_prefix_index = pq.top().second;
                if(cur_sum-min_prefix >= k){//incorrect variable name
                    min_range = min(min_range,i-min_prefix_index);
                }
                else{
                    break;
                }
            }
            pq.push(make_pair(cur_sum, i));
        }
        return min_range;
    }
};
// @lc code=end

