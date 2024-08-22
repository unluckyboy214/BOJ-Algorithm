#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));

    // 입력 처리 및 모순 체크
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        if (arr[s][e] == -1 || arr[e][s] == 1) {
            cout << "-1\n";
            return 0;
        }
        arr[s][e] = 1;
        arr[e][s] = -1;
    }

    // 플로이드 워셜 방식으로 간접 관계 전파
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;

                if (arr[i][k] == 1 && arr[k][j] == 1) {
                    if (arr[i][j] == -1 || arr[j][i] == 1) {
                        cout << "-1\n";
                        return 0;
                    }
                    arr[i][j] = 1;
                    arr[j][i] = -1;
                }

                if (arr[i][k] == -1 && arr[k][j] == -1) {
                    if (arr[i][j] == 1 || arr[j][i] == -1) {
                        cout << "-1\n";
                        return 0;
                    }
                    arr[i][j] = -1;
                    arr[j][i] = 1;
                }
            }
        }
    }

    // 최소, 최대 위치 계산 및 출력
    for (int i = 1; i <= N; i++) {
        int Min_pos = 1, Max_pos = N;

        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 1) {
                Max_pos--;
            }
            else if (arr[i][j] == -1) {
                Min_pos++;
            }
        }

        cout << Min_pos << " " << Max_pos << "\n";
    }

    return 0;
}
