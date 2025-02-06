/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
    class Solution {
    public:
        char rec(int k, int n) {
            int mirror;
            if(n==1) return '0';
            if (k == 1)
                return '0';
            if (k == 2)
                return '1';
            if ((k & (k - 1)) == 0) return '1';  // Corrected condition for power of 2

            int len = (1 << n);  // Use bit shift to compute 2^n

            if (k < len / 2)  // Changed to k < len / 2 for midpoint comparison
                return rec(k, n - 1);
            else {
                if (rec(len - k, n - 1) == '0')  // Correctly calculate mirrored index
                    return '1';
                else
                    return '0';
            }
        }

        char findKthBit(int n, int k) {
            return rec(k, n);
        }
    };
// @lc code=end

int main() {
    Solution sol;
    cout << sol.findKthBit(3, 1);
    return 0;
}