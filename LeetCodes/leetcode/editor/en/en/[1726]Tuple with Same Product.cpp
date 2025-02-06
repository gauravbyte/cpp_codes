
/**
Given an array nums of distinct positive integers, return the number of tuples (
a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums,
and a != b != c != d.


 Example 1:


Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)


 Example 2:


Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)



 Constraints:


 1 <= nums.length <= 1000
 1 <= nums[i] <= 10⁴
 All elements in nums are distinct.


 Related Topics Array Hash Table Counting 👍 699 👎 28

*/

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int tupleSameProduct(vector<int> &nums) {
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        mp[nums[i] * nums[j]]++;
      }
    }
    int res = 0;
    for (auto i : mp) {
      res += i.second * (i.second - 1) / 2;
    }
    return res * 8;
  }
};
// leetcode submit region end(Prohibit modification and deletion)

int main() {
  Solution s;
  vector<int> nums = {2, 3, 4, 6};  // Example input
  cout << s.tupleSameProduct(nums); // Example output
  return 0;
}
