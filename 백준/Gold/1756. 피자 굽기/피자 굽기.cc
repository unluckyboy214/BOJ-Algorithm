#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int D, N;
    cin >> D >> N;

    vector<int> oven(D + 1, 0);
    vector<int> pizza(N + 1, 0);

    for (int i = 1; i <= D; ++i) {
        cin >> oven[i];
    }

    for (int i = 1; i <= N; ++i) {
        cin >> pizza[i];
    }

    for (int i = 2; i <= D; ++i) {
        oven[i] = min(oven[i], oven[i - 1]);
    }

    int pos = D;

    for (int i = 1; i <= N; ++i) {
        while (pos > 0 && oven[pos] < pizza[i]) {
            pos--; 
        }
        if (pos == 0) {
            cout << 0 << '\n';  
            return 0;
        }
        pos--; 
    }

    cout << pos + 1 << '\n'; 

    return 0;
}
