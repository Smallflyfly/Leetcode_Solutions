/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start

// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };


#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> que;
        que.push(root);
        que.push(nullptr);
        vector<int> rest;
        while (!que.empty()) {
            Node* p = que.front();
            que.pop();
            if (nullptr == p) {
                res.push_back(rest);
                if (!que.empty()) {
                    que.push(nullptr);
                }
                rest.clear();
            } else {
                rest.push_back(p->val);
                vector<Node*> children = p->children;
                for (auto node : children) {
                    que.push(node);
                }
            }
        }
        return res;
    }
};
// @lc code=end

