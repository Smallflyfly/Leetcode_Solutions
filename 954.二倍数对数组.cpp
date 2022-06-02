/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
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
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> numMap;
        for (int a : arr) {
            numMap[a] ++;
        }
        sort(arr.begin(), arr.end());
        for (int a : arr) {
            if (numMap[a] == 0) continue;
            if (numMap[a] > 0) {
                if (a < 0) {
                    if (a % 2 != 0) return false;
                    if (numMap[a/2] == 0) return false;
                    numMap[a] --;
                    numMap[a/2] --;
                } else {
                    if (numMap[a] > 0 && numMap[a*2] == 0) return false;
                    numMap[a] --;
                    numMap[a*2] --;
                }
            }
            
        }
        return true;
    }
};
// @lc code=end

// 1 2 4 8
