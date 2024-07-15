#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> items(N);

    int W, V;
    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        items[i].first = W; //무게
        items[i].second = V; //가치
    }

    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; i++) {
        int weight = items[i].first;
        int value = items[i].second;

        for (int j = K; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    cout << dp[K];

    return 0;
}
