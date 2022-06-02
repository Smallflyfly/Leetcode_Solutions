/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
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

    int minMutation(string start, string end, vector<string>& bank) {
        int ans = -1;
        map<string, int> bankMap;
        for (auto s : bank) bankMap[s] = 1;
        map<string, int> visitMap;
        queue<pair<string, int>> que;
        que.push(make_pair(start, 0));
        visitMap[start] = 1;
        char dir[4] = {'A', 'C', 'G', 'T'};
        while (!que.empty()) {
            pair<string, int> par = que.front();
            string s = par.first;
            int step = par.second;
            que.pop();
            if (s.compare(end) == 0) {
                ans = step;
                break;
            }
            for(int i=0; i<8; i++) {
                string st = s;
                for (int j=0; j<4; j++) {
                    if (st[i] != dir[j]) st[i] = dir[j];
                    if (visitMap.find(st) != visitMap.end()) continue;
                    if (bankMap.find(st) == bankMap.end()) continue;
                    pair<string, int> p(st, step+1);
                    que.push(p);
                    visitMap[st] = 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end