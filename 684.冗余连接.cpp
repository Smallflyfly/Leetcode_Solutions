/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
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
    int n;
    int father[1001];
    int get(int x) {
        if (x != father[x]) father[x] = get(father[x]);
        return father[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans;
        for (int j=1; j<=n; j++) father[j] = j;
        for (int j=0; j<n; j++) {
            int ea = edges[j][0];
            int eb = edges[j][1];
            int a = get(ea);
            int b = get(eb);
            if (a != b) father[a] = b;
            else {
                ans.push_back(ea);
                ans.push_back(eb);
            }
        }
        return ans;
    }
};
// @lc code=end

