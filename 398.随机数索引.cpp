/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>

using namespace std;

// @lc code=start
class Solution {
public:
    map<int, vector<int>> numMap;
    Solution(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            if (numMap.find(nums[i]) != numMap.end()) {
                numMap[nums[i]].push_back(i);
            } else {
                vector<int> t{i};
                numMap[nums[i]] = t;
            }
        }
    }
    
    int pick(int target) {
        vector<int> nums = numMap[target];
        return nums[rand()%nums.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

