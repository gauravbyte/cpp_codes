#
# @lc app=leetcode id=1233 lang=python3
#
# [1233] Remove Sub-Folders from the Filesystem
#

# @lc code=start
from typing import List

from typing import List

class Solution:
    def if_subFolder(self, s, j):
        s = s + '/'
        j = j + '/'
    
        if j.startswith(s):
            return s[:-1]
        return None
    
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        result = []
        
        for i in range(len(folder)):
            if not result or not self.if_subFolder(result[-1], folder[i]):
                result.append(folder[i])

        return result

# @lc code=end

