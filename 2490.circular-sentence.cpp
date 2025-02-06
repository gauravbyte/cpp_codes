/*
 * @lc app=leetcode id=2490 lang=cpp
 *
 * [2490] Circular Sentence
 */

// @lc code=start
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        for (int i = 0; i < n; i++) {
            string s = sentence.substr(i) + sentence.substr(0, i);
            if (s == sentence) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

