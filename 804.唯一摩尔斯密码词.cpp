/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string mos[] = {".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.","---",".--.",
        "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<char, string> mosMap;
        for (char i='a'; i<='z'; i++) {
            mosMap[i] = mos[i-'a'];
        }
        map<string, int> ansMap;
        int ans = 0;
        for (auto &s : words) {
            string t = "";
            for (int i=0; i<s.length(); i++) {
                t += mosMap[s[i]];
            }
            if (ansMap.find(t) != ansMap.end()) {
                continue;
            }
            ans ++;
            ansMap[t] = 1;
        }
        return ans;
    }
};
// @lc code=end

