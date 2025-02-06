// There is a dungeon with n x m rooms arranged as a grid.
// You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
// Return the minimum time to reach the room (n - 1, m - 1).
// Two rooms are adjacent if they share a common wall, either horizontally or vertically.



// Example 1:

// Input: moveTime = [[0,4],[4,4]]

// Output: 6

// Explanation:

// The minimum time required is 6 seconds.

// At time t == 4, move from room (0, 0) to room (1, 0) in one second.
// At time t == 5, move from room (1, 0) to room (1, 1) in one second.
// Example 2:

// Input: moveTime = [[0,0,0],[0,0,0]]

// Output: 3

// Explanation:

// The minimum time required is 3 seconds.

// At time t == 0, move from room (0, 0) to room (1, 0) in one second.
// At time t == 1, move from room (1, 0) to room (1, 1) in one second.
// At time t == 2, move from room (1, 1) to room (1, 2) in one second.
// Example 3:

// Input: moveTime = [[0,1],[1,2]]

// Output: 3

//  

// Constraints:

// 2 <= n == moveTime.length <= 50
// 2 <= m == moveTime[i].length <= 50
// 0 <= moveTime[i][j] <= 109

// Note: Please do not copy the description during the contest to maintain the integrity of your submissions.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // Dijkstra's algorithm
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newTime = max(time, moveTime[nx][ny])+1;
                    if (newTime < dist[nx][ny]) {
                        dist[nx][ny] = newTime;
                        pq.push({newTime, {nx, ny}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};