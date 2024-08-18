#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    vector<vector<long long>> dp(N, vector<long long>(N, 0)); // 경로의 개수가 클 수 있으므로 long long 사용

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == 0 || board[i][j] == 0) continue; // 이동할 수 없는 경우
            int jump = board[i][j];
            if (i + jump < N) dp[i + jump][j] += dp[i][j]; // 아래로 점프
            if (j + jump < N) dp[i][j + jump] += dp[i][j]; // 오른쪽으로 점프
        }
    }

    cout << dp[N - 1][N - 1];
    return 0;
}
