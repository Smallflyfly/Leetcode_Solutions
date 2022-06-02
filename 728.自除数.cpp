/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
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
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int num=left; num<=right; num++) {
            int t = num;
            int flag = 1;
            while (t) {
                int a = t%10;
                if (a == 0) {
                    flag = 0;
                    break;
                }
                if (num % a != 0) {
                    flag = 0;
                    break;
                }
                t /= 10;
            }
            if (flag) {
                res.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end

