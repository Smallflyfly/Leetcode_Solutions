/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
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
    string a;
    string b;
    double val;
}Node;

public:
    map<string, int> wordsMap;
    map<int, double> numMap;
    int father[21];
    int n;
    int visit[21];

    int get(int x) {
        if (x != father[x]) father[x] = get(father[x]);
        return father[x];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int index = 0;
        for (auto eqs : equations) {
            string a = eqs[0];
            string b = eqs[1];
            if (wordsMap.find(a) == wordsMap.end()) wordsMap[a] = index++;
            if (wordsMap.find(b) == wordsMap.end()) wordsMap[b] = index++;
        }
        n = index;
        memset(father, 0, sizeof(father));
        memset(visit, 0, sizeof(visit));
        for (int i=0; i<n; i++) father[i] = i;
        for (int i=0; i<equations.size(); i++) {
            auto eqs = equations[i];
            string a = eqs[0];
            string b = eqs[1];
            int n1 = wordsMap[a];
            int n2 = wordsMap[b];
            int f1 = get(n1);
            int f2 = get(n2);
            if (f1 != f2) {
                father[f1] = f2;
            }
        }
        queue<Node> que;
        Node p;
        p.a = queries[0][1];
        p.b = queries[0][0];
        p.val = values[0];
        que.push(p);
        visit[0] = 1;
        while (!que.empty()) {
            Node pr = que.front();
            que.pop();
            int n1 = wordsMap[pr.a];
            int n2 = wordsMap[pr.b];
            if (numMap.find(n1) != numMap.end()) {
                numMap[n2] = numMap[n1] / pr.val;
            } else if (numMap.find(n2) != numMap.end()) {
                numMap[n1] = numMap[n2] * pr.val;
            } else {
                numMap[n1] = 1.0;
                numMap[n2] = 1.0 / pr.val;
            }
            for (int i=0; i<equations.size(); i++) {
                if (visit[i]) continue;
                string aa = equations[i][0];
                string bb = equations[i][1];
                if (p.a.compare(aa) == 0 || p.a.compare(bb) == 0 
                    || p.b.compare(aa) == 0 || p.b.compare(bb) == 0) {
                    Node q;
                    q.a = aa;
                    q.b = bb;
                    q.val = values[i];
                    que.push(q);
                    visit[i] = 1;
                }
            }
        }
        vector<double> ans;
        for (auto quers : queries) {
            string a = quers[0];
            string b = quers[1];
            if (wordsMap.find(a) == wordsMap.end() 
            || wordsMap.find(b) == wordsMap.end()) {
                ans.push_back(-1.0);
                continue;
            }
            int n1 = wordsMap[a];
            int n2 = wordsMap[b];
            cout << n1 << " " << n2 << endl;
            int f1 = get(n1);
            int f2 = get(n2);
            cout << f1 << " " << f2 << endl;
            if (f1 != f2) ans.push_back(-1.0);
            else ans.push_back(numMap[n1] / numMap[n2]);
        }
        return ans;
    }
};
// @lc code=end

/*
[["a","b"],["c","b"],["d","b"],["w","x"],["y","x"],["z","x"],["w","d"]]

[2.0,3.0,4.0,5.0,6.0,7.0,8.0]
a = 1.0
b = 0.5
c = 1.5
d = 2.0



*/