#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findAllShortestPaths(unordered_map<int, vector<int>> &graph, int source, int target) {
    queue<int> q;
    unordered_map<int, int> distance;
    unordered_map<int, vector<vector<int>>> paths;

    q.push(source);
    distance[source] = 0;
    paths[source].push_back({source}); // Start with the source node

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            // If the neighbor is visited for the first time, update distance and queue
            if (!distance.count(neighbor)) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
                paths[neighbor] = {}; // Initialize paths for this node
            }

            // If the neighbor can be reached with the shortest path, add paths
            if (distance[neighbor] == distance[node] + 1) {
                for (const auto &path : paths[node]) {
                    vector<int> newPath = path;
                    newPath.push_back(neighbor);
                    paths[neighbor].push_back(newPath);
                }
            }
        }
    }

    return paths.count(target) ? paths[target] : vector<vector<int>>{};
}

int main() {
    // Graph representation (Adjacency List)
    unordered_map<int, vector<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {2, 3};
    graph[2] = {3, 4};
    graph[3] = {4};
    graph[4] = {};

    int source = 0, target = 4;
    vector<vector<int>> shortestPaths = findAllShortestPaths(graph, source, target);

    // Output all shortest paths
    cout << "All Shortest Paths from " << source << " to " << target << ":\n";
    for (const auto &path : shortestPaths) {
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}
