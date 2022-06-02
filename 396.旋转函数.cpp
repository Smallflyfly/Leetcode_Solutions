/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(2*n, 0);
        preSum[0] = nums[0];
        vector<int> allNums;
        for (int i=0, k=1; i<n && k<=2; i++) {
            allNums.push_back(nums[i]);
            if (i==n-1) {
                i=-1;
                k++;
            }
        }
        for (int i=1; i<=2*n-1; i++) preSum[i] = allNums[i] + preSum[i-1];
        int maxVal = 0, sumA=0;
        for (int i=n; i<=2*n-1; i++) {
            sumA += (i-n)*allNums[i];
        }
        maxVal = sumA;
        int i=n-1, j=2*n-2;
        while (i>=1) {
            // cout << j << " " << i << endl;
            // cout << preSum[j] << " " << preSum[i] << endl;
            int tempSum = preSum[j]-preSum[i];
            // cout << "tempSum: " << tempSum <<endl;
            sumA = sumA+tempSum-(n-1)*allNums[j+1];
            // cout << "sumA: " << sumA << endl;
            // cout << "allNums[j+1]: " << allNums[j+1] << endl;
            maxVal = max(maxVal, sumA);
            // cout << "maxVal: " << maxVal << endl;
            i--;
            j--;
        }
        return maxVal;

    }
};
// @lc code=end

/*

j=3 i=0
4,3,2,6,4,3,2,6

4 3 2 6 25
6 4 3 2 
25 + 9 - 6*3 = 34 - 18 = 16

16 + 13 - 3*2

4 3 2 6
3 2 6 4
2 6 4 3

4 7 9 15 19 22 24 30

[0, 1, 2, 3, 4]
*/