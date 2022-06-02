/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>

using namespace std;


// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1;
        int i = 0;
        int ans = 0;
        for (int j=0; j<n; j++) {
            // cout << i << endl;
            prod *= nums[j];
            while(i <= j && prod>=k) {
                prod /= nums[i];
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
};
// @lc code=end

