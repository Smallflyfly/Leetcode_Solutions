/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

// @lc code=start
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (nullptr == headA || nullptr == headB) return nullptr;
        ListNode *pa = headA, *pb = headB;
        if (pa == pb) return pa;
        pa = pa->next, pb = pb->next;
        while (pa || pb) {
            if (pa == pb) return pa;
            if (nullptr == pa && nullptr == pb) {
                break;
            }
            if (nullptr == pb) {
                pb = headA;
                pa =  pa->next;
            } else if (nullptr == pa) {
                pa = headB;
                pb = pb->next;
            } else {
                pa = pa->next;
                pb = pb->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end

/**
3
[3]
[2,3]
0
1

3 2 3
2 3 3
 




 * 
 */