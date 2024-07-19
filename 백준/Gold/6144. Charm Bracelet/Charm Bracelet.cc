#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> charms(N);

    for (int i = 0; i < N; i++) {
        int W_i, D_i;
        cin >> W_i >> D_i;
        charms[i] = make_pair(W_i, D_i);
    }

    vector<int> dp(M + 1);

    for (int i = 0; i < N; i++) {
        int weight = charms[i].first;
        int desirability = charms[i].second;

        for (int j = M; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + desirability);
        }

    }

    cout << dp[M];


    return 0;
}
