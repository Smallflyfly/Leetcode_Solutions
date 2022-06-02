/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include <ctype.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isAEIOU(char c) {
        c = tolower(c);
        return c=='a' || c =='e' || c=='i' || c=='o' || c=='u';
    }
    vector<string> getStringList(string sentence) {
        vector<string> list;
        int i=0;
        while (i<sentence.length()) {
            if (sentence[i] != ' ') {
                string temp = "";
                int j=i;
                for (; j<sentence.length(); j++) {
                    if (sentence[j] == ' ') break;
                    temp += sentence[j];
                }
                list.push_back(temp);
                i=j;
            }
            i++;
        }
        return list;
    }
    string toGoatLatin(string sentence) {
        vector<string> list = getStringList(sentence);
        string res = "";
        for (int i=0; i<list.size(); i++) {
            string s = list[i];
            if (isAEIOU(s[0])) {
                s += "ma";
            } else {
                s += s[0];
                s += "ma";
                s = s.substr(1, s.length()-1);
            }
            int j=i+1;
            while (j--) s += 'a';
            if (res == "") res = s;
            else res += (" " + s);
        }
        return res;
    }
};
// @lc code=end

