#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int H, N;
    cin >> H >> N;

    vector<int> hayvale(N);

    for (int i = 0; i < N; i++) {
        cin >> hayvale[i];
    }

    vector<int> dp(H + 1);

    for (int i = 0; i < N; i++) {
        int weight = hayvale[i];

        for (int j = H; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + weight);
        }
    }

    cout << dp[H];


    return 0;
}
