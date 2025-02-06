/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=edges.size()-1; i>=0; i--){
            vector<vector<int>> graph(1001);
            vector<int> visited(1001, 0);
            bool cycle = false;
            for(int j=0; j<edges.size(); j++){
                if(j==i) continue;
                graph[edges[j][0]].push_back(edges[j][1]);
                graph[edges[j][1]].push_back(edges[j][0]);
            }
            for(int j=1; j<=1000; j++){
                if(visited[j]==0){
                    if(dfs(graph, visited, j, -1)){
                        cycle = true;
                        break;
                    }
                }
            }
            if(!cycle){
                return edges[i];
            }
        }       
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node, int parent){
        visited[node] = 1;
        for(int i=0; i<graph[node].size(); i++){
            if(visited[graph[node][i]]==0){
                if(dfs(graph, visited, graph[node][i], node)){
                    return true;
                }
            }else if(graph[node][i]!=parent){
                return true;
            }
        }
        return false;
    }   
};
// @lc code=end

