/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
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

typedef struct Coin{
    int left;
    int count;
    int index;
}Coin;

public:
    int coinChange(vector<int>& coins, int amount) {
        queue<Coin> que;
        Coin coin;
        coin.count = 0;
        coin.left = amount;
        coin.index = 0;
        sort(coins.begin(), coins.end(), greater<int>());
        que.push(coin);
        while (!que.empty()) {
            Coin c = que.front();
            que.pop();
            int left = c.left;
            int count = c.count;
            int index = c.index;
            if (left == 0) return count;
            if (index >= coins.size()) continue;
            int n = left / coins[index];
            for (int i=n; i>=0; i--) {
                int t_left = left;
                if (t_left >= i*coins[index]) {
                    t_left -= i * coins[index];
                    Coin t;
                    t.left = t_left;
                    t.count = count + i;
                    t.index = index + 1;
                    que.push(t);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

