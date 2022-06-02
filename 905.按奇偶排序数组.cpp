/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        while (i < j) {
            while (i < n && nums[i] % 2 == 0) i++;
            while (j >= 0 && nums[j] % 2 == 1) j--;
            // cout << i << " " << j << endl;
            if (i < j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        return nums;
    }
};
// @lc code=end

