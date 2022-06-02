/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
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
    int diri[4] = {-1, 0, 1, 0};
    int dirj[4] = {0, -1, 0, 1};
    int leftVist[201][201];
    int rightVisit[201][201];
    int n, m;
    int visitr[201][201];
    int visitl[201][201];

    int dfs(int i, int j, const vector<vector<int>>& heights, int visit[201][201], int visited[201][201]) {
        if (visit[i][j]) return 1;
        int flag = 0;
        for (int k=0; k<4; k++) {
            int di = i + diri[k];
            int dj = j + dirj[k];
            if (di>=0 && di<m && dj>=0 && dj<n && heights[i][j] >= heights[di][dj] && !visited[di][dj]) {
                visited[di][dj] = 1;
                flag = dfs(di, dj, heights, visit, visited);
                if (flag) {
                    visit[di][dj] = 1;
                    break;
                }
            }
        }
        return flag;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        memset(visitr, 0, sizeof(visitr));
        memset(visitl, 0, sizeof(visitl));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                leftVist[i][j] = i == 0 || j == 0 ? 1 : 0;
                rightVisit[i][j] = i == m-1 || j == n-1 ? 1 : 0;
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                memset(visitr, 0, sizeof(visitr));
                memset(visitl, 0, sizeof(visitl));
                visitl[i][j] = 1;
                if (dfs(i, j, heights, leftVist, visitl)) leftVist[i][j] = 1;
                visitr[i][j] = 1;
                if (dfs(i, j, heights, rightVisit, visitr)) rightVisit[i][j] = 1;
            }
        }
        
        vector<vector<int>> ans;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (leftVist[i][j] && rightVisit[i][j]) {
                    vector<int> t;
                    t.push_back(i);
                    t.push_back(j);
                    ans.push_back(t);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

/*

[
    [1,2,2,3,5],
    [3,2,3,4,4],
    [2,4,5,3,1],
    [6,7,1,4,5],
    [5,1,1,2,4]
]
[[1,1,1],[1,1,1],[1,1,1]]


.



*/

