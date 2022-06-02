/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& nums) {
        if (root) {
            inOrder(root->left, nums);
            nums.push_back(root->val);
            inOrder(root->right, nums);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        this->inOrder(root, nums);
        if(nums.size() == 1) return false;
        map<int, int> numMap;
        for (auto &num : nums) {
            numMap[num] = 1;
        }
        for (auto &num : nums) {
            if (num == k - num) continue;
            if (numMap.find(k-num) != numMap.end()) return true;
        }
        return false;
    }
};
// @lc code=end

