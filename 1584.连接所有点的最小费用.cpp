/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
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
    int grid[1001][1001];
    int dist[1001];
    int visit[1001];
    int n;
    int inf = 0x7fffffff;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        memset(dist, 0, sizeof(dist));
        memset(visit, 0, sizeof(visit));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (i == j) {
                    grid[i][j] = inf;
                }
                int xi = points[i-1][0];
                int yi = points[i-1][1];
                int xj = points[j-1][0];
                int yj = points[j-1][1];
                int dis = abs(xi - xj) + abs(yi - yj);
                grid[i][j] = dis;
            }
        }
        int ans = 0;
		for (int i = 1; i <= n; ++i) {
            dist[i] = grid[i][1];
        }
        int index = 1;
        visit[index] = 1;
        for (int i = 1; i < n; ++i) {
            int min = inf;
            for (int j = 1; j <= n; ++j) {
                if (!visit[j] && min > dist[j]) {
                    min = dist[j];
                    index = j;
                }
            }
            visit[index] = 1;
            ans += min;
            for (int j = 2; j <= n; ++j) {
                if (grid[index][j] < dist[j]) {
                    dist[j] = grid[index][j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

