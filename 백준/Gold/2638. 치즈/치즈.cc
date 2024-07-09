#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int paper[103][103];
bool used[103][103];

// 상하좌우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int N, M;

void FindOutsideAir_BFS() {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    // 바깥 공기 찾기
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        used[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int next_y = y + dy[i];
            int next_x = x + dx[i];

            // 범위 밖, 치즈가 있는 경우, 이미 탐색한 경우 패스
            if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M || paper[next_y][next_x] == 1 || used[next_y][next_x]) {
                continue;
            }
            else {
                used[next_y][next_x] = true;
                paper[next_y][next_x] = 2;  // 바깥 공기 표시
                q.push(make_pair(next_y, next_x));
            }
        }
    }
}

bool MeltCheese() {
    vector<pair<int, int>> toMelt;

    // 모든 치즈 셀을 탐색하며 녹을 치즈를 찾음
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (paper[i][j] == 1) {
                int airContact = 0;
                for (int k = 0; k < 4; k++) {
                    int next_y = i + dy[k];
                    int next_x = j + dx[k];
                    if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < M && paper[next_y][next_x] == 2) {
                        airContact++;
                    }
                }
                if (airContact >= 2) {
                    toMelt.push_back(make_pair(i, j));
                }
            }
        }
    }

    // 녹을 치즈가 없으면 false 반환
    if (toMelt.empty()) return false;

    // 녹일 치즈들을 녹임
    for (auto& cell : toMelt) {
        paper[cell.first][cell.second] = 0;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    int time = 0;

    while (true) {
        // 사용 배열 초기화
        fill(&used[0][0], &used[0][0] + sizeof(used) / sizeof(used[0][0]), false);

        // 바깥 공기를 찾음
        FindOutsideAir_BFS();

        // 치즈를 녹임
        if (!MeltCheese()) break;

        time++;
    }

    cout << time << endl;

    return 0;
}
