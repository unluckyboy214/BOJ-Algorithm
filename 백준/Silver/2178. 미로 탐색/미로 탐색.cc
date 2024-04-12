#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> maze;
vector<vector<bool>> visited;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int bfs() {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    int count = 0;
    while (!q.empty()) {
        int size = q.size();
        count++;
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == m - 1) {
                return count;
            }

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    maze = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            maze[i][j] = row[j] - '0';
        }
    }

    cout << bfs();
    return 0;
}
