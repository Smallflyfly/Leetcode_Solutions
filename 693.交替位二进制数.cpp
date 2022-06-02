/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
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
    bool hasAlternatingBits(int n) {
        int a = -1;
        while (n) {
            int b = n % 2;
            if (b == a) return false;
            n /= 2;
            a = b;
        }
        return true;
    }
};
// @lc code=end

