#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int H, W;
    int ans = 0;

    cin >> H >> W;
    vector<int> v(W);

    for (int i = 0; i < W; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < W - 1; i++) {
        int left_max = 0;
        int right_max = 0;

        for (int j = 0; j < i; j++) {
            left_max = max(left_max, v[j]);
        }

        for (int j = i + 1; j < W; j++) {
            right_max = max(right_max, v[j]);
        }

        int height = min(left_max, right_max);
        if (height > v[i]) {
            ans += height - v[i];
        }
    }

    cout << ans;

    return 0;
}
