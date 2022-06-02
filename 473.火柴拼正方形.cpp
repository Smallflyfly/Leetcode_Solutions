/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
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
class Solution {
public:

    int len;
    int n;
    int edges[5];
    bool DFS(int index, vector<int>& matchsticks) {
        if (index == matchsticks.size()) return true;
        for (int i=0; i<4; i++) {
            edges[i] = edges[i] + matchsticks[index];
            if (edges[i] <= len && DFS(index+1, matchsticks)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        n = matchsticks.size();
        int total = 0;
        for (auto ma : matchsticks) total += ma;
        if (total % 4 != 0) return false;
        len = total / 4;
        // cout << len << endl;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        memset(edges, 0, sizeof(edges));
        return DFS(0, matchsticks);
        // for (int i=0; i<n; i++) {
        //     if (visit[i]) continue;
        //     visit[i] = 1;
        //     if (!DFS(matchsticks[i], matchsticks)) return false;
        // }
        // return true;
    }
};
// @lc code=end

/*
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
1,2,3,4,5,6,9
7,8,15

[13,11,1,8,6,7,8,8,6,7,8,9,8] 



*/