/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> st;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i])==st.end()){
                nums[count]=nums[i];
                count++;
            }
            st.insert(nums[i]);
        }
        return st.size();
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> nums = {1,1,2};
    cout<<sol.removeDuplicates(nums);
    return 0;
}
