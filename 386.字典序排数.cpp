/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int num = 1;
        for (int i=1; i<=n; i++) {
            res.push_back(num);
            if (num * 10 <= n) {
                num *= 10;
                continue;
            }
            while (num % 10 == 9 || num+1 > n) {
                num /= 10;
            }
            num++;
        }
        return res;
    }
};
// @lc code=end

