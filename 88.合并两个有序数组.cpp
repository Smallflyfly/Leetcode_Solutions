/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n - 1;
        int k = m + n - 1;
        while (i>=0 && j>=0) {
            if (nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while (i>=0) nums1[k--] = nums1[i--];
        while (j>=0) nums1[k--] = nums2[j--];
    }
};
// @lc code=end

/**
 * 
 * 
4 5 6
1 2 3

1 2 3 4 5 6      2 5 6

1 2 3 4 5 6

5 6 





 * 
 */
