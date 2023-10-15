/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //prefix sum
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                ans++;
            }
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            //!there might be multiple subarrays with same sum
            mp[sum]++;
        }
        return ans;
    }
};
// @lc code=end

