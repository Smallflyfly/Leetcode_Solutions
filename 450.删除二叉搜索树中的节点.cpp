/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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

//  struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& arr) {
        if (root) {
            arr.push_back(root->val);
            preOrder(root->left, arr);
            preOrder(root->right, arr);
        }
    }

    int bin_sear(int left, int right, int target, vector<int> inOrderTree) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (inOrderTree[mid] == target) return mid;
            if (inOrderTree[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    TreeNode* build_tree(vector<int> preOrderTree, vector<int> inOrderTree) {
        if (preOrderTree.size() == 0 && inOrderTree.size() == 0) return nullptr;
        TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));
        root->val = preOrderTree[0];
        // cout << root->val << endl;
        int index = bin_sear(0, inOrderTree.size()-1, root->val, inOrderTree);
        vector<int> inorder_left_node;
        vector<int> inorder_right_node;
        if (index > 0) {
            for (int i=0; i<index; i++) inorder_left_node.push_back(inOrderTree[i]);
        }
        if (index < inOrderTree.size()-1) {
            for (int i=index+1; i<inOrderTree.size(); i++) 
                inorder_right_node.push_back(inOrderTree[i]);
        }
        vector<int> preorder_left_node;
        vector<int> preorder_right_node;
        // cout << inorder_left_node.size() << endl;
        // cout << inorder_right_node.size() << endl;
        if (inorder_left_node.size() > 0) {
            for (int i=1; i<inorder_left_node.size()+1; i++) 
                preorder_left_node.push_back(preOrderTree[i]);
        }
        if (inorder_right_node.size() > 0) {
            for (int i=inorder_left_node.size()+1; i<preOrderTree.size(); i++) 
                preorder_right_node.push_back(preOrderTree[i]);
        }
        root->left = build_tree(preorder_left_node, inorder_left_node);
        root->right = build_tree(preorder_right_node, inorder_right_node);

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        vector<int> preArrs;
        preOrder(root, preArrs);
        for (auto it=preArrs.begin(); it != preArrs.end(); it++) {
            if (*it == key) {
                preArrs.erase(it);
                break;
            }
        }
        vector<int> inArrs;
        inArrs.assign(preArrs.begin(), preArrs.end());
        sort(inArrs.begin(), inArrs.end());
        return build_tree(preArrs, inArrs);
    }
};
// @lc code=end

