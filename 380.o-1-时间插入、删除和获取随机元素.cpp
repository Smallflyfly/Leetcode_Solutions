/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


// @lc code=start
class RandomizedSet {
public:
    int size;
    int deleteSize = 0;
    map<int, int> numMap;
    vector<int> numList;
    RandomizedSet() {
        size = 0;
        deleteSize = 0;
    }
    
    bool insert(int val) {
        if (numMap.find(val) != numMap.end()) return false;
        numMap[val] = 1;
        if (numList.size() < size) {
            numList[size] = val;
        } else {
            numList.push_back(val);
        }
        size ++;
        return true;
    }
    
    bool remove(int val) {
        if (numMap.find(val) != numMap.end()) {
            numMap.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int index = rand()%size;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

