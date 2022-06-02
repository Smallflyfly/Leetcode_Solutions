/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
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

    map<int, int> setMap;
    int get(int x) {
        if (x != setMap[x]) setMap[x] = get(setMap[x]);
        return setMap[x];
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        for (int i=0; i<n; i++) {
            setMap[nums[i]] = nums[i];
        }
        for (int i=0; i<n; i++) {
            int x = nums[i];
            x = get(x);
            if (setMap.find(nums[i]+1) != setMap.end()) {
                int y = setMap[nums[i]+1];
                y = get(y);
                if (x != y) {
                    setMap[x] = y;
                }
            }
        }
        map<int, int> ansMap;
        map<int, int>::iterator it;
        int ans = 0;
        for (it=setMap.begin(); it!=setMap.end(); it++) {
            int key = it->first;
            int val = get(key);
            // cout << key << " " << val << endl;
            if (ansMap.find(val) != ansMap.end()) {
                ansMap[val]++;
            } else {
                ansMap[val] = 1;
            }
            ans = max(ans, ansMap[val]);
        }
        return ans;
    }
};
// @lc code=end

