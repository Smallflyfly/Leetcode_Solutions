/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
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
    int father[201];

    int getFather(int x) {
        if (x != father[x]) {
            father[x] = getFather(father[x]);
        }
        return father[x];
    }

    void merge(int a, int b) {
        a = getFather(a);
        b = getFather(b);
        if (a != b) {
            father[a] = b;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i=0; i<n; i++) {
            father[i] = i;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i==j) continue;
                if (isConnected[i][j]) {
                    int a = getFather(i);
                    int b = getFather(j);
                    if (a != b) {
                        father[a] = b;
                    }
                }
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (father[i] == i) ans++;
        }
        return ans;
    }
};
// @lc code=end

/*
[
    [1,1,0,0,0,0,0,1,0,0,0,0,0,0,0],
    [1,1,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,1,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,1,0,1,1,0,0,0,0,0,0,0,0],
    [0,0,0,0,1,0,0,0,0,1,1,0,0,0,0],
    [0,0,0,1,0,1,0,0,0,0,1,0,0,0,0],
    [0,0,0,1,0,0,1,0,1,0,0,0,0,1,0],
    [1,0,0,0,0,0,0,1,1,0,0,0,0,0,0],
    [0,0,0,0,0,0,1,1,1,0,0,0,0,1,0],
    [0,0,0,0,1,0,0,0,0,1,0,1,0,0,1],
    [0,0,0,0,1,1,0,0,0,0,1,1,0,0,0],
    [0,0,0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,1,0,0],
    [0,0,0,0,0,0,1,0,1,0,0,0,0,1,0],
    [0,0,0,0,0,0,0,0,0,1,0,0,0,0,1]
]

    1 2 8
    1 2
    3
    4 6 7
    5 10 11
    4 6 11
    4 7 9 14
    1 8 9
    7 8 9 14
    5 10 12 15
    5 6 11 12
    10 11 12
    13
    7 9 14
    10 15




*/

