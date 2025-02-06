#
# @lc app=leetcode id=2769 lang=python3
#
# [2769] Find the Maximum Achievable Number
#

# @lc code=start
class Solution:
    def theMaximumAchievableX(self, num: int, t: int) -> int:
        if t == 0:
            return num
        if num == 0:
            return 0
        if num < 0:
            return max(num, self.theMaximumAchievableX(num + t, t))
        if num > 0:
            return max(num, self.theMaximumAchievableX(num - t, t))
        
# @lc code=end

