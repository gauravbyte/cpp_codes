#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[100005];
bool visited[100005];
int parent[100005];

bool dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node)) return true;
        }
        else if (neighbor != par) {
            // Found a cycle
            stack<int> cycle;
            cycle.push(node);
            while (node != neighbor) {
                node = parent[node];
                cycle.push(node);
            }
            cout << cycle.size() + 1 << "\n"; // +1 for the starting city
            while (!cycle.empty()) {
                cout << cycle.top() << " ";
                cycle.pop();
            }
            cout << neighbor; // print the starting city again to complete the cycle
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // because it's an undirected graph
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) return 0;
    }

    cout << "IMPOSSIBLE";
    return 0;
}
