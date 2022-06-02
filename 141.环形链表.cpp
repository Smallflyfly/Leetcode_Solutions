/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode, int> nodeMap;
        ListNode *p = head;
        while (p) {
            if (nodeMap.find(p) != nodeMap.end()) {
                return true;
            }
            nodeMap[p] = 1;
            p = p->next;
        }
        return false;
    }
};
// @lc code=end

