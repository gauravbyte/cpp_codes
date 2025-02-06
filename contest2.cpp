
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end()); 
        unordered_map<int, int> freqMap; 
        for (auto num : nums) {
            freqMap[num]++;
        }

        int maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            int upperBound = nums[i] + k;
            int lowerBound = nums[i] - k;
            auto upperIt = upper_bound(nums.begin(), nums.end(), upperBound)-nums.begin();
            auto lowerIt = lower_bound(nums.begin(), nums.end(), lowerBound)-nums.begin();
            int rangeSize = upperIt - lowerIt;
            cout<<upperIt<<endl;
            cout<<lowerIt<<endl;
            int operable = rangeSize - freqMap[nums[i]];
            
            if (operable >= numOperations) {
                int finalFrequency = freqMap[nums[i]] + numOperations;
                maxFreq = max(maxFreq, finalFrequency);
            } else {
                int finalFrequency = freqMap[nums[i]] + operable;
                maxFreq = max(maxFreq, finalFrequency);
            }
        }

        return maxFreq;
    }
};
int main(){
    Solution s;
    vector<int> nums = {88,53};
    int k = 27;
    int numOperations = 2;
    cout<<s.maxFrequency(nums,k,numOperations);
}