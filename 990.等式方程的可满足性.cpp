/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>
#include<string>

using namespace std;


// @lc code=start
class Solution {
public:
    int father[27];

    int get(int x) {
        if (x != father[x]) father[x] = get(father[x]);
        return father[x];
    }

    bool equationsPossible(vector<string>& equations) {
        for (int i=0; i<26; i++) {
            father[i] = i;
        }
        int n = equations.size();
        for (int i=0; i<n; i++) {
            string s = equations[i];
            char a = s[0];
            char b = s[s.length()-1];
            char eq = s[1];
            if (eq == '=') {
                int fa = get(a - 'a');
                int fb = get(b - 'a');
                if (fa != fb) father[fa] = fb;
            }
        }
        for (int i=0; i<n; i++) {
            string s = equations[i];
            char a = s[0];
            char b = s[s.length()-1];
            char eq = s[1];
            if (eq == '!') {
                int fa = get(a - 'a');
                int fb = get(b - 'a');
                if (fa == fb) return false;
            }
        }
        return true;
    }
    

};
// @lc code=end

