#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> vec(M);

    for (int i = 0; i < M; i++) {
        int d, p;
        cin >> d >> p;
        vec[i].first = d;
        vec[i].second = p;
    }

    vector<int> dp(N+1);

    for (int i = 0; i < M; i++) {
        int day = vec[i].first;
        int page = vec[i].second;

        for (int j = N ; j >= day; j--) {
            dp[j] = max(dp[j], dp[j - day] + page);
        }

    }

    cout << dp[N];

    return 0;
}
