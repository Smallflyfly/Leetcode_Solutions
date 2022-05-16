/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
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
class Solution {
public:
    int father[27];

    int get(int x) {
        if (x != father[x]) father[x] = get(father[x])
        return father[x];
    }

    bool equationsPossible(vector<string>& equations) {
        for (int i=0; i<26; i++) {
            father[i] = i;
        }
    }
};
// @lc code=end

