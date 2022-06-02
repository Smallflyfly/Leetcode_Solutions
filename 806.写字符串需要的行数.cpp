/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> res;
        int lines = 0;
        int tsum = 0;
        for (auto c : s) {
            tsum += widths[c-'a'];
            if (tsum > 100) {
                tsum = widths[c - 'a'];
                lines++;
            }
        }
        res.push_back(lines+1);
        res.push_back(tsum);
        return res;
    }
};
// @lc code=end

