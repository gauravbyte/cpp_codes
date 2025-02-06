#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        queue<int> q;

        // Terminal nodes outdegree = 0
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 0) {
                q.push(i);
            }
        }

        vector<vector<int>> reverseGraph = reverseGraphFun(graph);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto ad : reverseGraph[cur]) {
                if (!visited[ad]) {
                    visited[ad] = 1;
                    q.push(ad);
                }
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }

    vector<vector<int>> reverseGraphFun(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                reverseGraph[graph[i][j]].push_back(i);
            }
        }
        return reverseGraph;
    }
};