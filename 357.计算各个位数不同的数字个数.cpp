/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n==1) return 10;
        int ans = 10;
        while (n-1) {
            int k = 9;
            for(int i=0; i<n-1; i++) {
                k *= 9-i;
            }
            ans += k;
            n--;
        }
        return ans;
    }
};

// @lc code=end

