/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };



class Solution {
public:
    void InOrder(TreeNode *root, int &sum) {
        if (nullptr != root) {
            if (nullptr == root->left && nullptr == root->right) return;
            if (nullptr == root->left) sum += root->left->val;
            if (nullptr == root->right) sum += root->right->val;
            sum += abs(root->left - root->right);
        }
    }

    int checkSum(TreeNode *root) {
        if (nullptr == root->left && nullptr == root->right) return root->val;
        if (nullptr == root->left) {
            root->val = checkSum(root->right) + root->val;
            return root->val;
        }
        if (nullptr == root->right) {
            root->val = checkSum(root->left) + root->val;
            return root->val;
        }
        root->val = checkSum(root->left) + checkSum(root->right) + root->val;
        return root->val;
    }
    int findTilt(TreeNode* root) {
        checkSum(root);
        // cout << sum << endl;
        int sum = 0;
        InOrder(root, sum);

        return sum;
    }
};
// @lc code=end

