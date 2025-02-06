/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// #include<bits/stdc++.h>
// using namespace std;

class Solution {
public:
    void tree_call(TreeNode *cur, map<int, vector<int>> &mp, int depth) {
        if (cur != nullptr) {
            mp[depth].push_back(cur->val);
        } else {
            return;
        }
        tree_call(cur->left, mp, depth + 1);
        tree_call(cur->right, mp, depth + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        map<int, vector<int>> mp;
        tree_call(root, mp, 0);
        int mx = INT_MIN;
        for (auto a : mp) {
            mx = max(mx, a.first);
        }
        int sum = 0;
        for (auto a : mp[mx]) {
            sum += a;
        }
        return sum;
    }
};
// @lc code=end

