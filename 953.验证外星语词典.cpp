/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
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
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> wordMap;
        for (int i=0; i<order.size(); i++) wordMap[order[i]] = i;
        int n = words.size();
        for (int i=1; i<n; i++) {
            string s1 = words[i-1];
            string s2 = words[i];
            int j = 0;
            for (; j<s1.length() && j < s2.length()) {
                if (s2[j] > s1[j]) break;
                if (s2[j] < s1[j]) return false;
            }
            if (j == s2.length() && j < s1.length()) return false;
        }
        return true;
    }
};
// @lc code=end

