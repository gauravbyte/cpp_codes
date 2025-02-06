/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        for (auto pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }
        vector<vector<int>> reachable(numCourses, vector<int>(numCourses, 0));
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            vector<bool> visited(numCourses, false);
            q.push(i);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto ad : graph[cur]){
                    if(!visited[ad]){
                        reachable[i][ad] = 1;
                        visited[ad] = true;
                        q.push(ad);
                    }
                }
            }
        }
        vector<bool> result;
        for(auto query : queries){
            result.push_back(reachable[query[0]][query[1]]);
        }
        return result;



    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<vector<int>> prerequisites = {{1,0},{2,0}};
    vector<vector<int>> queries = {{0,1},{2,0}};
    vector<bool> result = sol.checkIfPrerequisite(3, prerequisites, queries);
    for(auto res : result){
        cout<<res<<" ";
    }
    return 0;
}