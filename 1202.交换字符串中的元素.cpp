/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
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
    int father[100001];
    int n;

    int getFather(int x) {
        if (x != father[x]) {
            father[x] = getFather(father[x]);
        }
        return father[x];
    }

    void merge(int a, int b) {
        a = getFather(a);
        b = getFather(b);
        if (a != b) {
            father[a] = b;
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        int m = pairs.size();
         for (int i=0; i<n; i++) {
            father[i] = i;
        }
        for (int i=0; i<m; i++) {
            int a = pairs[i][0];
            int b = pairs[i][1];
            int aa = getFather(a);
            int bb = getFather(b);
            if (aa != bb) {
                father[aa] = bb;
            }
        }
        // for (int i=0; i<n; i++) {
        //     cout << father[i] << endl;
        // }
        // cout << getFather(0) << " " << getFather(1) << endl;
        for (int i=0; i<n; i++) {
            // cout << getFather(i) << endl;
            for (int j=1; j<n-i; j++) {
                if (s[j] < s[j-1] && getFather(j) == getFather(j-1)) {
                    // cout << i << " " << j << endl;
                    // cout << father[i] << " " << father[j] << endl;
                    char c = s[j-1];
                    s[j-1] = s[j];
                    s[j] = c;
                }
            }
        }
        return s;
    }
};
// @lc code=end

/*

"dcab"\n[[0,3],[1,2],[0,2]]

*/