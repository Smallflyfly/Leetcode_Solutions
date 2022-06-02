/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:

    int getNum(vector<int> nums) {
        int k = 1;
        int num = 0;
        for (int i=nums.size()-1; i>=0; i--) {
            num += nums[i] * k;
            k *= 2;
        }
        return num;
    }

    int sumRootToLeaf(TreeNode* root) {
        queue<pair<TreeNode*, vector<int>>> que;
        vector<int> temp;
        que.push(make_pair(root, temp));
        vector<vector<int>> allArrs;
        while (!que.empty()) {
            pair<TreeNode*, vector<int>> pr = que.front();
            que.pop();
            TreeNode* p = pr.first;
            vector<int> arrt = pr.second;
            arrt.push_back(p->val);
            if (!p->left && !p->right) allArrs.push_back(arrt); 
            if (p->left) que.push(make_pair(p->left, arrt));
            if (p->right) que.push(make_pair(p->right, arrt));
        }
        int ans = 0;
        for (auto arrs : allArrs) {
            ans += getNum(arrs);
        }
        return ans;
    }
};
// @lc code=end

