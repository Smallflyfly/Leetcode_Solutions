/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
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
class RecentCounter {
public:
    int num[10001];
    int total;

    int binSearch(int left, int right, int key) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (num[mid] == key) return mid;
            if (num[mid] > key) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    RecentCounter() {
        total = 0;
        memset(num, 0, sizeof(num));
    }
    
    int ping(int t) {
        total ++;
        num[total-1] = t;
        int key = max(1, t-3000);
        int index = binSearch(0, total-1, t-3000);
        return total - index;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

