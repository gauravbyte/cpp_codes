/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
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
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        TreeNode *cur1 = root1;
        TreeNode *cur2 = root2;
        if(cur1==NULL && cur2==NULL)
            return true;
        if(cur1==NULL || cur2==NULL)
            return false;
        if(cur1->val!=cur2->val)
            return false;
        if(flipEquiv(cur1->left,cur2->left) && flipEquiv(cur1->right,cur2->right))
            return true;
        if(flipEquiv(cur1->left,cur2->right) && flipEquiv(cur1->right,cur2->left))  
            return true;
        return false;
        
    }
};
// @lc code=end

