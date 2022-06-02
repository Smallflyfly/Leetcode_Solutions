/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
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
    int getNum(string s) {
        int num = 0;
        for (int i=0; i<s.length(); i++) {
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }

    string getString(int num, string s) {
        string ss = "";
        while (num) {
            ss += s;
            num--;
        }
        return ss;
    }

    string decodeString(string s) {
        stack<string> sStack;
        int i = 0;
        int n = s.length();
        while (i < n) {
            // cout << i << endl;
            if (s[i] >= '0' && s[i] <= '9') {
                string sNum = "";
                while (i<n && (s[i] >= '0' && s[i] <= '9')) {
                    sNum += s[i++];
                }
                sStack.push(sNum);
            } else if (s[i] == ']') {
                string ts = "";
                while (!sStack.empty() && sStack.top() != "[") {
                    string t = sStack.top();
                    sStack.pop();
                    ts = t + ts; 
                }
                //12
                sStack.pop();
                string numS = sStack.top();
                sStack.pop();
                int num = getNum(numS);
                string ss = getString(num, ts);
                sStack.push(ss);
                i++;
            } else {
                string ts = "";
                ts += s[i++];
                sStack.push(ts);
            }
        }
        string ans = "";
        while (!sStack.empty()) {
            string ts = sStack.top();
            sStack.pop();
            ans = ts + ans;
        }
        return ans;
    }
};
// @lc code=end

/*

3[a]
3[a

"3[z]2[2[y]pq4[2[jk]e1[f]]]ef"






*/