
/**
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= 
nums[j]. The width of such a ramp is j - i. 

 Given an integer array nums, return the maximum width of a ramp in nums. If 
there is no ramp in nums, return 0. 

 
 Example 1: 

 
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 
and nums[5] = 5.
 

 Example 2: 

 
Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 
and nums[9] = 1.
 

 
 Constraints: 

 
 2 <= nums.length <= 5 * 10⁴ 
 0 <= nums[i] <= 5 * 10⁴ 
 

 Related Topics Array Two Pointers Stack Monotonic Stack 👍 2649 👎 89

*/
#include<bits/stdc++.h>
using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxWidth = 0;
        vector<int> st;
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.back()]<nums[i]){
                st.pop_back();
            }
            if (!st.empty())
            maxWidth = max(maxWidth, st.back()-i);
            st.push_back(i);
            maxWidth = max(maxWidth, st[0]-st.back());
        }
        return maxWidth;
    }
};
int main(){
 Solution s;
 vector<int> nums = {6,0,8,2,1,5};
 cout<<s.maxWidthRamp(nums);


}
//leetcode submit region end(Prohibit modification and deletion)



