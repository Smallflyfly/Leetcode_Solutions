/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>
#include<string>

using namespace std;


// @lc code=start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    int bin_sear(int left, int right, int target, vector<int> inOrderTree) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (inOrderTree[mid] == target) return mid;
            if (inOrderTree[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    
    int findIndex(int target, vector<int> inOrderTree) {
        for (int i=0; i<inOrderTree.size(); i++) {
            if (target == inOrderTree[i]) return i;
        }
        return -1;
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

    void parse_data(string data, vector<int> &tree) {
        int i=0;
        int num = -1;
        while (i < data.length()) {
            if (data[i] >= '0' && data[i] <= '9') {
                if (num == -1) num = 0;
                num = num * 10 + (data[i] - '0');
            } else {
                tree.push_back(num);
                num = -1;
            }
            i++;
        }
        if (num > -1) tree.push_back(num);
    }

    void preOrder(TreeNode *root, vector<int> &tree) {
        if (root) {
            tree.push_back(root->val);
            preOrder(root->left, tree);
            preOrder(root->right, tree);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string treeSeri = "";
        vector<int> tree;
        preOrder(root, tree);
        for (auto t : tree) {
            if (treeSeri.length() == 0) treeSeri += to_string(t);
            else treeSeri += "," + to_string(t);
        }
        // cout << treeSeri << endl;
        return treeSeri;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *p;
        if (data.length() == 0) return nullptr;
        vector<int> inOrderTree;
        vector<int> preOrderTree;
        parse_data(data, preOrderTree);
        inOrderTree.assign(preOrderTree.begin(), preOrderTree.end());
        sort(inOrderTree.begin(), inOrderTree.end());
        p = build_tree(preOrderTree, inOrderTree);
        return p;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end


/*





*/
