/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
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
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        for (int i=0; i<m; i++) {
            char a = strs[0][i];
            for (int j=1; j<n; j++) {
                // cout << j <<  " " << i << endl;
                char b = strs[j][i];
                // cout << b << endl;
                if (a > b) {
                    ans++;
                    break;
                }
                a = b;
            }
        }
        return ans;
    }
};
// @lc code=end
/*

[
    "rrjk",
    "furt",
    "guzm"
]




*/
