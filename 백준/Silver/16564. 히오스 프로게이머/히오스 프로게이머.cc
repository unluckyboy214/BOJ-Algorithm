#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long findMaxTeamLevel(int N, long long K, vector<int>& levels) {
    int left = *min_element(levels.begin(), levels.end());
    int right = left + K;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long required = 0;

        for (int level : levels) {
            if (level < mid) {
                required += (mid - level);
            }
            if (required > K) break;
        }

        if (required <= K) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return right;
}

int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<int> levels(N);
    for (int i = 0; i < N; i++) {
        cin >> levels[i];
    }

    cout << findMaxTeamLevel(N, K, levels) << endl;

    return 0;
}
