#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l1 = len(nums1)
        l2 = len(nums2)
        if(l1<l2):
            return self.findMedianSortedArrays(nums2,nums1)
        if(l2==0):
            return (nums1[(l1-1)//2]+nums1[l1//2])/2.0
        left =0
        right = l1
        while left<=right:
            mid1=(left+right)//2
            mid2=left-mid1
            L1 = float('-inf') if mid1==0 else nums1[mid1-1]
            L2 = float('-inf') if mid2==0 else nums2[mid2-1]
            R1 = float('inf') if mid1==l1 else nums1[mid1]
            R2 = float('inf') if mid2==l2 else nums2[mid2]
            if L1>R2:
                right = mid1-1
            elif L2>R1:
                left = mid1+1
            else:
                return (max(L1,L2)+min(R1,R2))/2.0
            
        return 0



# @lc code=end

