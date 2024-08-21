#include <iostream> 
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool all_equal(const vector<int>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] != vec[1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    //초기상태 큐브 입력
    vector<int> Cube(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> Cube[i];
    }

    //스위치 입력
    vector<vector<int>> Switches_Conect(K + 1);

    for (int i = 1; i <= K; i++) {
        int cnt;
        cin >> cnt;
        Switches_Conect[i].resize(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> Switches_Conect[i][j];
        }
    }

    // BFS 큐와 방문 체크 맵
    queue<pair<vector<int>, int>> q;
    map<vector<int>, bool> visited;

    q.push({ Cube, 0 });
    visited[Cube] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        vector<int> current_state = current.first;
        int step_count = current.second;

        // 모든 큐브의 숫자가 동일한지 확인
        if (all_equal(current_state)) {
            cout << step_count << "\n";
            return 0;
        }

        // 각 스위치에 대해 상태를 업데이트
        for (int i = 1; i <= K; i++) {
            vector<int> new_state = current_state;
            for (int cube_index : Switches_Conect[i]) {
                new_state[cube_index] = (new_state[cube_index] + i) % 5;
            }

            // 새 상태가 방문되지 않았다면 큐에 추가
            if (!visited[new_state]) {
                visited[new_state] = true;
                q.push({ new_state, step_count + 1 });
            }
        }
    }

    // 모든 큐브의 숫자가 동일하게 될 수 없는 경우
    cout << "-1\n";
    return 0;
}
