/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> numsMap;
        for(int i=0; i<n; i++) {
            if (numsMap.find(target - nums[i]) != numsMap.end()) return vector<int>{i, numsMap[target - nums[i]]};
            numsMap[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

