
/**
You are given a network of n nodes, labeled from 1 to n. You are also given 
times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui 
is the source node, vi is the target node, and wi is the time it takes for a 
signal to travel from source to target. 

 We will send a signal from a given node k. Return the minimum time it takes 
for all the n nodes to receive the signal. If it is impossible for all the n nodes 
to receive the signal, return -1. 

 
 Example 1: 
 
 
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
 

 Example 2: 

 
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
 

 Example 3: 

 
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

 
 Constraints: 

 
 1 <= k <= n <= 100 
 1 <= times.length <= 6000 
 times[i].length == 3 
 1 <= ui, vi <= n 
 ui != vi 
 0 <= wi <= 100 
 All the pairs (ui, vi) are unique. (i.e., no multiple edges.) 
 

 Related Topics Depth-First Search Breadth-First Search Graph Heap (Priority 
Queue) Shortest Path 👍 7711 👎 376

*/


#include<bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      vector<vector<pair<int,int>>> adj(n+1);
      for(auto i:times){
        adj[i[0]].push_back({i[1],i[2]});
      }
      vector<int> dist(n+1,-1);
      pq.push({0,k});
      dist[k]=0;
      while(!pq.empty()){
        auto [d,node] = pq.top();
        pq.pop();
        for(auto i:adj[node]){
          if(dist[i.first]==-1 || dist[i.first]>d+i.second){
            dist[i.first]=d+i.second;
            pq.push({dist[i.first],i.first});
            }
        }

      }
      int max_time = -1;
      for(int i=1; i<=n; i++){
        if(dist[i]==-1) return -1;
        max_time = max(max_time,dist[i]);
      }
      return max_time;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    Solution s;
    

}
