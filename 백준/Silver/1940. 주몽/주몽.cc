#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> vec(N,0);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    int start = 0;
    int end = 1;
    int cnt = 0;
    sort(vec.begin(), vec.end());

    while (end < N) {
        if (vec[start] + vec[end] == M) cnt++;

        if (end == N - 1) {
            start++;
            end = start + 1;
        }
        else end++;
    }

    cout << cnt;

    return 0;
}
