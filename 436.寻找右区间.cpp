/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
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

typedef struct Point {
    int x;
    int y;
}Point;


public:

    static bool cmp(Point p1, Point p2) {
        return p1.x < p2.x;
    }

    int binsearch(int left, int right, int target, vector<Point> points) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (points[mid].x == target) return mid;
            if (points[mid].x < target) left = mid + 1;
            else right = mid - 1; 
        }
        return left;
    }



    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        map<int, int> pointIndexMap;
        vector<Point> points;
        for(int i=0; i<intervals.size(); i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            Point p;
            p.x = s;
            p.y = e;
            points.push_back(p);
            pointIndexMap[s] = i;
        }
        sort(points.begin(), points.end(), cmp);
        for (int i=0; i<intervals.size(); i++) {
            int index = binsearch(0, points.size()-1, intervals[i][1], points);
            if (index >= intervals.size() || index < 0) {
                index = -1;
                ans.push_back(index);
            } else {
                ans.push_back(pointIndexMap[points[index].x]);
            }
        }
        
        return ans;
    }
};
// @lc code=end

