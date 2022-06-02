/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
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
    int binaryGap(int n) {
        vector<int> nums;
        int ans = 0;
        while (n) {
            int a = n % 2;
            nums.push_back(a);
            n /= 2;
        }
        int left = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 1) {
                if (left == -1) {
                    left = i;
                } else {
                    ans = max(ans, i - left);
                    left = i;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

