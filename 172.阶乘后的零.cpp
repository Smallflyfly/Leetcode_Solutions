/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;



// @lc code=start
class Solution {
public:
    int dp[10001];

    void record() {
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=10000; i++) {
            if (i%5 == 0) {
                dp[i] = dp[i-1] + 1;
                int t = i / 5;
                while (t % 5 == 0) {
                    t /= 5;
                    dp[i] ++;
                }
            } else {
                dp[i] = dp[i-1];
            }
        }
    }

    int trailingZeroes(int n) {
        this->record();
        return dp[n];
    }
};
// @lc code=end
/**
5 1
10 2
15 3
20 4
25 6
30 7
35 8
40 9
45 10
50 12
55 13
60 14
65 15
70 16
75 18
80 19




*/
