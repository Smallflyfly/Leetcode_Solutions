/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:

    void inOrder(TreeNode *root, vector<int> &tree) {
        if (root) {
            inOrder(root->left, tree);
            tree.push_back(root->val);
            inOrder(root->right, tree);
        }
    } 

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        inOrder(root1, tree1);
        vector<int> tree2;
        inOrder(root2, tree2);
        int i = 0, j = 0;
        vector<int> ans;
        while (i<tree1.size() && j<tree2.size()) {
            if (tree1[i] <= tree2[j]) {
                ans.push_back(tree1[i++]);
            } else {
                ans.push_back(tree2[j++]);
            }
        }
        while (i<tree1.size()) ans.push_back(tree1[i++]);
        while (j<tree2.size()) ans.push_back(tree2[j++]);
        return ans;
    }
    
};
// @lc code=end

