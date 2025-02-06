
/**
Given a circular integer array nums (i.e., the next element of nums[nums.length
- 1] is nums[0]), return the next greater number for every element in nums.

 The next greater number of a number x is the first greater number to its
traversing-order next in the array, which means you could search circularly to
find its next greater number. If it doesn't exist, return -1 for this number.


 Example 1:


Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.


 Example 2:


Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]



 Constraints:


 1 <= nums.length <= 10⁴
 -10⁹ <= nums[i] <= 10⁹


 Related Topics Array Stack Monotonic Stack 👍 8301 👎 205

*/
#include <bits/stdc++.h>
using namespace std;

// leetce submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> result(nums.size());
    stack<int> s;
    // return the maximum index in vector
    int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
    result[maxIndex] = -1;
    s.push(maxIndex);
    int curIndex = maxIndex;
    curIndex--;
    if (curIndex == -1)
      curIndex = nums.size() - 1;
    while (curIndex != maxIndex) {
      while (!s.empty() && nums[s.top()] <= nums[curIndex]) {
        s.pop();
      }
      result[curIndex] = s.empty() ? -1 : nums[s.top()];
      s.push(curIndex);
      curIndex--;
      if (curIndex == -1)
        curIndex = nums.size() - 1;
    }
    return result;
  }
};

// n() {
//<int> nums = {5,4,3,2,1}; // Example input
// on solution;
//<int> result = solution.nextGreaterElements(nums);
//
// nting the output
// nt num : result) {
//<< num << " ";
//
//< endl;
//
//  0;
//
// leetcode submit region end(Prohibit modification and deletion)
