
/**
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait 
after the iᵗʰ day to get a warmer temperature. If there is no future day for which 
this is possible, keep answer[i] == 0 instead. 

 
 Example 1: 
 Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
 
 Example 2: 
 Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
 
 Example 3: 
 Input: temperatures = [30,60,90]
Output: [1,1,0]
 
 
 Constraints: 

 
 1 <= temperatures.length <= 10⁵ 
 30 <= temperatures[i] <= 100 
 

 Related Topics Array Stack Monotonic Stack 👍 13622 👎 342

*/
//leetcode submit region begin(Prohibit modification and deletion)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

      int n = temperatures.size();
      vector<int> result(n);
      stack<pair<int,int>> s;
      for(int i=n-1; i>= 0; i--){
        int count = 0;
        while(!s.empty() && s.top().first <= temperatures[i]){
           s.pop();
        }

        result[i] = s.empty() ? 0 : s.top().second - i;
        s.push(make_pair(temperatures[i],i));
      }
      return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
