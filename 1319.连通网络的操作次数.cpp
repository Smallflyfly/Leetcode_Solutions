/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
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
    int father[100001];

    int get(int x) {
        if (x != father[x]) father[x] = get(father[x]);
        return father[x];
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int nn = connections.size();
        int lines = 0;
        for (int i=0; i<n; i++) {
            father[i] = i;
        }
        for (int i=0; i<nn; i++) {
            vector<int> conns = connections[i];
            int a = conns[0];
            int b = conns[1];
            int fa = get(a);
            int fb = get(b);
            if (fa != fb) father[fa] = fb;
            else lines ++;
        }
        int nodes = 0;
        for (int i=0; i<n; i++) {
            if (i == father[i]) nodes ++;
        }
        if (lines >= nodes - 1) return nodes - 1;
        else return -1;
    }
};
// @lc code=end

