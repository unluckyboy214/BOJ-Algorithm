#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> sieve_and_color(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> colors(n + 1, 0);
    is_prime[0] = is_prime[1] = false;

    int color = 1;

    colors[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            color++;
            for (int j = i; j <= n; j += i) {
                is_prime[j] = false;
                if (colors[j] == 0) {
                    colors[j] = color;
                }
            }
        }
    }
    return colors;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<int> colors = sieve_and_color(N);

    int max_color = *max_element(colors.begin(), colors.end());

    cout << max_color << endl;
    for (int i = 1; i <= N; ++i) {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}
