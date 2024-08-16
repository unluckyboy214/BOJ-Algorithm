#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(k + 1, 0);
    dp[0] = 1;  // 0원을 만드는 방법은 1가지 (동전을 하나도 사용하지 않는 경우)

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k] << endl;

    return 0;
}
