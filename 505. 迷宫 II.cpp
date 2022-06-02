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

typedef struct Node {
    int xi;
    int xj;
    int step;
}Node;

struct cmp {
	bool operator()(Node p, Node q) {
		return p.step > q.step;
	}
};

public:
    int visit[101][101];
    int diri[4] = {-1, 0, 1, 0};
    int dirj[4] = {0, -1, 0, 1};
    int n, m;

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) { 
        int n = maze.size();
        int m = maze[0].size();
        int si = start[0];
        int sj = start[1];
        int ei = destination[0];
        int ej = destination[1];
        memset(visit, 0, sizeof(visit));
        // queue<Node> que;
        priority_queue<Node, vector<Node>, cmp> que;
        Node sp;
        sp.xi = si;
        sp.xj = sj;
        sp.step = 0;
        que.push(sp);
        int ans = -1;
        visit[si][sj] = 1;
        while (!que.empty()) {
            Node p = que.top();
            que.pop();
            if (p.xi == ei && p.xj == ej) {
                ans = p.step;
                break;
            }
            for (int i=0; i<4; i++) {
                int di = p.xi + diri[i];
                int dj = p.xj + dirj[i];
                if (di>=0 && di<n && dj>=0 && dj<m && maze[di][dj] != 1) {
                    while (di>=0 && di<n && dj>=0 && dj<m && maze[di][dj] != 1) {
                        di = di + diri[i];
                        dj = dj + dirj[i];
                    }
                    di = di - diri[i];
                    dj = dj - dirj[i];
                    if (visit[di][dj]) continue;
                    int step = abs(p.xi - di) + abs(p.xj - dj);
                    Node q;
                    q.xi = di;
                    q.xj = dj;
                    q.step = p.step + step;
                    que.push(q);
                    visit[di][dj] = 1;
                }
            }
        }
        return ans;
    }
};


/*

[
    [0,0,1,1,S],
    [0,0,0,R,0],
    [0,0,0,1,R],
    [1,1,E,1,1],
    [0,0,0,0,0]
]

[0,4]
[3,2]



*/