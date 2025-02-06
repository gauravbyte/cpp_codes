class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int max = -1;
        unordered_set<int> numSet(nums.begin(), nums.end());
        vector<int> sortedNums(numSet.begin(), numSet.end());
        
        sort(sortedNums.begin(), sortedNums.end());
        
        for (int num : sortedNums) {
            int curr = num;
            int count = 0;
            
            while (numSet.count(curr)) {
                numSet.erase(curr);
                curr *= curr;
                count++;
            }
            
            max = max(max, count);
        }
        
        return max > 1 ? max : -1;
    }
};