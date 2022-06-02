/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int binSearch(int left, int right, vector<char>& letters, char target) {
        while (left < right) {
            int mid = (left + right) / 2;
            // cout << left << " " << right << " " << mid << endl; 
            if (letters[mid] <= target) left = mid + 1;
            else {
                if (mid-1>=0 && letters[mid-1] <= target){
                    // cout << mid << endl;
                    return mid;
                }
                right = mid - 1;
            }
            
        }
        return left;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int index = binSearch(0, letters.size()-1, letters, target);
        // cout << index << endl;
        if (index == letters.size()-1 && target>=letters[index]) index = 0;
        return letters[index];
    }
};
// @lc code=end

