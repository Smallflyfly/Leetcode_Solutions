/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;


// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        goal = goal + goal;
        int i = 0;
        int j = 0;
        while (i < s.length() && j < goal.length())
        {
            if (s[i] == goal[j]) {
                int k = j;
                while (s[i] == goal[j]) {
                    i++;
                    j++;
                }
                if (i==s.length()) return true;
                i = 0;
                j = k+1;\
                continue;
            } else {
                j++;
            }
            
        }
        return false;
        
    }
};
// @lc code=end

