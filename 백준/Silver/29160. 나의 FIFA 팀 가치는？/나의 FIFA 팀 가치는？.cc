#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<priority_queue<int>> Line_up(12);

void August() {
    for (int i = 1; i <= 11; i++) {
        if (!Line_up[i].empty()) {
            int temp = Line_up[i].top();
            Line_up[i].pop();
            if (temp > 1) { 
                Line_up[i].push(temp - 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    int P, W;
    int ans = 0;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> P >> W;
        Line_up[P].push(W);
    }

    for (int i = 0; i < K; i++) {
        August();
    }
    for (int i = 1; i <= 11; i++) {
        if (!Line_up[i].empty()) {
            ans += Line_up[i].top();
        }
    }

    cout << ans;

    return 0;
}
