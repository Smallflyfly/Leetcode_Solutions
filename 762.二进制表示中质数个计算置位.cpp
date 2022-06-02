/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
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
    int primes[1000001];
    Solution(){
        int visit[1000001];
        memset(primes, 0, sizeof(primes));
        memset(visit, 0, sizeof(visit));
        int n = 1000000;
        for (int i=2; i<=n; i++) {
            if (!visit[i]) primes[i]=1;
            for (auto j : primes) {
                cout << j << endl;
                if (i*j > n) break;
                visit[i*j] = 1;
                if (i % j == 0) break;
            }
        }
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int num=left; num<=right; num++) {
            int temp = num;
            int sum = 0;
            while (temp) {
                int t = temp % 2;
                sum += t;
                temp /= 2;
            }
            if (primes[sum]) {
                ans ++;
            }
        }
        return ans;
    }
};
// @lc code=end

