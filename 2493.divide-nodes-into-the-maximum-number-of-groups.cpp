/*
 * @lc app=leetcode id=2493 lang=cpp
 *
 * [2493] Divide Nodes Into the Maximum Number of Groups
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n+1, 0);

        if(!isBipartitie(graph,visited,0)){
            return -1;
        }
        for(int i=0; i<=n; i++){
            visited[i] = 0;
        }   
        int ans = 0;
        for(int i=0; i<=n; i++){
            if(visited[i]==0){
                ans += dfs(graph, visited, i, -1)-1;
            }
        }
        return ans;


    }

    bool isBipartitie(vector<vector<int>>& graph, vector<int>& visited, int node){
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0; i<graph[curr].size(); i++){
                if(visited[graph[curr][i]]==0){
                    visited[graph[curr][i]] = -visited[curr];
                    q.push(graph[curr][i]);
                }else if(visited[graph[curr][i]]==visited[curr]){
                    return false;
                }
            }
        }
        return true;
    }

    int dfs(vector<vector<int>>& graph, vector<int>& visited, int node, int parent){
        visited[node] = 1;
        int count = 1;
        for(int i=0; i<graph[node].size(); i++){    
            if(visited[graph[node][i]]==0){
                count += dfs(graph, visited, graph[node][i], node);
            }
        }   
        return count;

    }






};
// @lc code=end

