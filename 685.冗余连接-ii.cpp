/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:

    int father[1001];
    int get(int x) {
        if (x != father[x]) father[x] = get(father[x]);
        return father[x];
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i=1; i<=n; i++) {
            father[i] = i;
        }
        vector<int> ans;
        for (int i=0; i<n; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            a = get(a);
            b = get(b);
            if (a != b) {
                father[b] = a;
            } else {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

/*

[[2,1],[3,1],[4,2],[1,4]]





*/