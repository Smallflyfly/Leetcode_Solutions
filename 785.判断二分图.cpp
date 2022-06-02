/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
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
    int g[101][101];
    int visit[101];
    bool isBipartite(vector<vector<int>>& graph) {
        memset(g, 0, sizeof(g));
        int n = graph.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<graph[i].size(); j++) {
                g[i][graph[i][j]] = g[graph[i][j]][i] = 1;
            }
        }
        for (int k=0; k<n; k++) {
            if (visit[k] != 0) continue;
            visit[k] = 1;
            queue<int> que;
            que.push(k);
            while (!que.empty()) {
                int p = que.front();
                que.pop();
                for (int i=0; i<n; i++) {
                    if (i == p) continue;
                    if (g[p][i] == 0) continue;
                    if (visit[i]>0 && visit[i] == visit[p]) return false;
                    if (visit[i] > 0) continue;
                    visit[i] = visit[p] == 1 ? 2 : 1;
                    que.push(i);
                }
            }
        }
        
        // for(int i=0; i<n; i++) {
        //     if (visit[i] == 0) return false;
        // }
        return true;
    }
};
// @lc code=end

/*

[[4],[],[4],[4],[0,2,3]]

0 4 
2 4
3 4


*/