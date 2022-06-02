/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


// @lc code=start
class Solution {
public:
    bool winnerOfGame(string colors) {
        int i = 0;
        int A = 0, B = 0;
        int n = colors.length();
        while (i < n) {
            if (colors[i] == 'A') {
                int t = 1;
                i++;
                while(i < n && colors[i] == 'A') {
                    i++;
                    t++;
                }
                if (t >= 3) A += t-2;
                continue;
            }
            if (colors[i] == 'B') {
                int t = 1;
                i++;
                while(i < n && colors[i] == 'B') {
                    i++;
                    t++;
                }
                if (t >= 3) B += t-2;
            }
        }
        if (A > B) return true;
        else return false;
    }
};
// @lc code=end

