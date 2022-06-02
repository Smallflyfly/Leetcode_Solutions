/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
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
    int dp[27];
    int findSubstringInWraproundString(string p) {
        memset(dp, 0, sizeof(dp));
        string st = "";
        char a = '\0';
        for (int i=0; i<p.length(); i++) {
            char b = p[i];
            if (st.length() == 0) {
                st += b;
                a = b;
                dp[a-'a'] = dp[a-'a'] > st.length() ? dp[a-'a'] : st.length();
                continue;
            } 
            if (b - a == 1 || (a == 'z' && b == 'a')) {
                    st += b;
                    a = b;
            } else {
                a = b;
                st = "";
                st += a;
            }
            dp[a-'a'] = dp[a-'a'] > st.length() ? dp[a-'a'] : st.length();
        }
        int ans = 0;
        for (int i=0; i<26; i++) {
            ans += dp[i];
        }
        return ans;
    }
};
// @lc code=end

/*
abcd
abcdabcdabcd

abcdefghijklmnopqrstuvwxyza

351 + 25*25 + 


*/