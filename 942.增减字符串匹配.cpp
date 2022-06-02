/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
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
    vector<int> diStringMatch(string s) {
        int a = 0, b = s.length();
        vector<int> ans;
        for (int i=0; i<s.length(); i++) {
            ans.push_back(s[i] == 'D' ? b-- : a++);
        }
        return ans;
    }
};
// @lc code=end

/*
DIDIDID
7


*/