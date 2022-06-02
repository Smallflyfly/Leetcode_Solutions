/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
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

typedef struct Node{
    int pi;
    int pj;
    int val;
    int step;
}Node;

public:
    int visit[51][51];
    int diri[4] = {-1, 0, 1, 0};
    int dirj[4] = {0, -1, 0, 1};
    int n, m;

    static bool cmp(Node p1, Node p2) {
        return p1.val < p2.val;
    }

    int BFS(int si, int sj, int ei, int ej, vector<vector<int>>& forest) {
        memset(visit, 0, sizeof(visit));
        queue<Node> que;
        Node p;
        p.pi = si;
        p.pj = sj;
        p.step = 0;
        que.push(p);
        while (!que.empty()) {
            p = que.front();
            que.pop();
            if (p.pi == ei && p.pj == ej) {
                return p.step;
            }
            for (int i=0; i<4; i++) {
                int di = p.pi + diri[i];
                int dj = p.pj + dirj[i];
                if (di>=0 && di<n && dj>=0 && dj<m && !visit[di][dj] && forest[di][dj]>0) {
                    Node q;
                    q.pi = di;
                    q.pj = dj;
                    q.step = p.step + 1;
                    que.push(q);
                    visit[di][dj] = 1;
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        n = forest.size();
        m = forest[0].size();
        vector<Node> nodes;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (forest[i][j] > 1) {
                    Node p;
                    p.pi = i;
                    p.pj = j;
                    p.val = forest[i][j];
                    nodes.push_back(p);
                }
            }
        }
        sort(nodes.begin(), nodes.end(), cmp);
        int ans = 0;
        int si = 0, sj = 0;
        for (int i=0; i<nodes.size(); i++) {
            Node p = nodes[i];
            int step = BFS(si, sj, p.pi, p.pj, forest);
            if (step == -1) return -1;
            ans += step;
            si = p.pi;
            sj = p.pj;
        }
        return ans;
    }
};
// @lc code=end

/*
[
    [1,2,3],
    [0,0,10],
    [7,6,5]
]




*/