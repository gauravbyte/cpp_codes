#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        map<int, int> indx;
        priority_queue<int, vector<int>, greater<int> > pq;
        vector<int> result(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            indx[nums[i]] = i;
            pq.push(nums[i]);
            result[i] = nums[i];
        }
        
        int curIndx = 0;
        while (!pq.empty() && limit > 0) {
            int curTop = pq.top();
            pq.pop();
            if (curTop != result[curIndx]) {
                swap(result[curIndx], result[indx[curTop]]);
                limit--;
            }
            curIndx++;
        }
        
        return result;
    }
};

int main() {
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;
    Solution sol;
    vector<int> result = sol.lexicographicallySmallestArray(nums, limit);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}