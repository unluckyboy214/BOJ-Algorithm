#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (true) {
        int n,c;
        double m,p;
        cin >> n >> m;
        if (n == 0 && m == 0.00) break;

        int money = (int)(m * 100 + 0.5);

        vector<pair<int, int>> candys(n);
        vector<int> dp(money + 1, 0);

        for (int i = 0; i < n; i++) {     
            cin >> c >> p;

            int cost = (int)(p * 100 + 0.5);

            for (int j = cost; j <= money; j++) {
                dp[j] = max(dp[j], dp[j - cost] + c);
            }
        }
        cout << dp[money] << "\n";

    }

    return 0;
}
