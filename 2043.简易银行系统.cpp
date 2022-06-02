/*
 * @lc app=leetcode.cn id=2043 lang=cpp
 *
 * [2043] 简易银行系统
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// @lc code=start
class Bank {
public:
    vector<long long> balance;

    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (this->balance[account1-1] < money) return false;
        this->balance[account1-1] -= money;
        this->balance[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        this->balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (this->balance[account-1] < money) return false;
        this->balance[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end

