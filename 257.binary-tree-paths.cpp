/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};
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
    vector<string> res;
    void binaryTreePathsUtil(TreeNode* root, string path, vector<string>& res){
        if(root == NULL) return;
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            res.push_back(path);
            return;
        }
        path += "->";
        binaryTreePathsUtil(root->left, path, res);
        binaryTreePathsUtil(root->right, path, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        binaryTreePathsUtil(root, "", res);
        return res;
    }
};
// @lc code=end

