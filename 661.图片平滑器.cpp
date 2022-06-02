/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        int dirx[4] = {0, 1, -1};
        int diry[4] = {0, 1, -1};
        vector<vector<int>> res;
        for(int i=0; i<n; i++) {
            vector<int> temp;
            for (int j=0; j<m; j++) {
                int sum = 0;
                int count = 0;
                for (int x=0; x<3; x++) {
                    for (int y=0; y<3; y++) {
                        int dx = i + dirx[x];
                        int dy = j + diry[y];
                        if (dx >=0 && dx <n && dy>=0 && dy<m) {
                            sum += img[dx][dy];
                            count++;
                        } 
                    }      
                }
                // int t = floor(sum / count);
                // cout << sum << " " << count << " " << t << endl;
                temp.push_back(sum / count);
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

