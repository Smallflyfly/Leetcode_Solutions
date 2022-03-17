/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


// @lc code=start
class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        map<string, int> wordMap;
        for(auto &s : words) {
            wordMap[s] = 1;
        }
        sort(words.begin(), words.end());
        int ans_length = 0;
        for(auto &s : words) {
            if (s.length() == 1) {
                wordMap[s]=1;
                continue;
            }
            string temp = s.substr(0, s.length()-1);
            if (wordMap.find(temp) != wordMap.end()) {
                wordMap[s] = wordMap[temp] + 1;
            }
        }
        for(auto &s : words) {
            if (s.length() > ans_length && wordMap[s] == s.length()) {
                ans = s;
                ans_length = ans.length();
            };
        }
        return ans;
    }
};
// @lc code=end
// ["yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"]

