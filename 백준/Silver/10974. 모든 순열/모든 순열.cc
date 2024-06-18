#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> perm(N);
    for (int i = 1; i <= N; ++i) {
        perm[i - 1] = i;
    }

    do {
        for (int i = 0; i < N; ++i) {
            cout << perm[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(perm.begin(), perm.end()));

    return 0;
}
