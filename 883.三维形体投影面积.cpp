/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
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
    int projectionArea(vector<vector<int>>& grid) {
        int top = 0;
        int row = 0;
        int col = 0;
        int n = grid.size();
        for (int i=0; i<n; i++) {
            int maxRow = -1;
            for (int j=0; j<n; j++) {
                maxRow = max(maxRow, grid[i][j]);
                top += grid[i][j] > 0 ? 1 : 0;
            }
            row += maxRow;
        }

        for (int j=0; j<n; j++) {
            int maxCol = -1;
            for (int i=0; i<n; i++) {
                maxCol = max(maxCol, grid[i][j]);
            }
            col += maxCol;
        }
        return top + row + col;

    }
};
// @lc code=end

