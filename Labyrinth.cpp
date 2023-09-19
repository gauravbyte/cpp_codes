#include<bits/stdc++.h>
using namespace std;

int m, n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string dir = "URDL"; // Matching the order of dx and dy

int main() {
    cin >> m >> n;
    vector<vector<char>> arr(m, vector<char>(n, '0'));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int startx, starty, endx, endy;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'A') {
                startx = i;
                starty = j;
            }
            if (arr[i][j] == 'B') {
                endx = i;
                endy = j;
            }
        }
    }

    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<vector<int>> previous_step(m, vector<int>(n, -1));
    vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n, {-1, -1}));
    queue<pair<int, int>> q;
    q.push({startx, starty});
    vis[startx][starty] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[nx][ny] != '#' && vis[nx][ny] == 0) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
                parent[nx][ny] = {x, y};
                previous_step[nx][ny] = i;
            }
        }
    }

    if (vis[endx][endy] == 0) {
        cout << "NO";
        return 0;
    } else {
        cout << "YES" << endl;
        string path;
        pair<int, int> current = {endx, endy};
        while (current.first != startx || current.second != starty) {
            int p = previous_step[current.first][current.second];
            path += dir[p];
            current = parent[current.first][current.second];
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    }

    return 0;
}
