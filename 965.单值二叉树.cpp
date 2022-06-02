/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>

using namespace std;



//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

class Solution {
public:

    int val;

    bool preOrder(TreeNode* root) {
        if (root) {
            int a = root->val;
            bool flag;
            if (a != val) return false;
            flag = preOrder(root->left);
            if (!flag) return false;
            flag = preOrder(root->right);
            if (!flag) return false;
            return true;
        }
        return true;
    }

    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        return preOrder(root);
    }
};
// @lc code=end

