#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> Study_time(K);

    for (int i = 0; i < K; i++) {
        cin >> Study_time[i].first >> Study_time[i].second;
    }

    vector<int> dp(N + 1);

    for (int i = 0; i < K; i++) {
        int I = Study_time[i].first;
        int time = Study_time[i].second;

        for (int j = N; j >= time; j--) {
            dp[j] = max(dp[j], dp[j - time] + I);
        }
    }

    cout << dp[N];

    return 0;
}
