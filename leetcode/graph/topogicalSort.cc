#include<vector>
#include<queue>
/*
* build an adjcent matrix to search
* with BFS, we traverse the nodes and put nodes with zero-degree into the queue
*/

using namespace std;
class Solution {
    vector<int> findOrder(int courseNum, vector<vector<int>>& prerequests) {
        vector<vector<int>> graph(courseNum, vector<int>);
        vector<int> indegree(courseNum, 0), res;
        for (const auto & pre : prerequests) {
            graph[pre[1]].push_back(pre[0]);
            ++indegree[pre[0]];
        }
        queue<int> q;
        for (int i=0; i< courseNum; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            res.push_back(u);
            q.pop();
            for (auto v : graph[u]) {
                --indegree[v];
                if (!indegree[v]) {
                    q.push(v);
                }
            }
        }
        for (int i =0 ; i < indegree.size(); i++) {
            if (indegree[i]) {
                return vector<int>();
            }
        }
        return res;
    }
};