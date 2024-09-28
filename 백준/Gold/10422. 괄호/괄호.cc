#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// 카탈란 수를 계산하는 함수
vector<long long> calculate_catalan(int max_n) {
    vector<long long> catalan(max_n + 1, 0);
    catalan[0] = 1;

    // 카탈란 수를 계산
    for (int n = 1; n <= max_n; ++n) {
        for (int i = 0; i < n; ++i) {
            catalan[n] = (catalan[n] + catalan[i] * catalan[n - 1 - i] % MOD) % MOD;
        }
    }

    return catalan;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    vector<int> lengths(T);
    int max_l = 0;

    // 입력 받기
    for (int i = 0; i < T; ++i) {
        cin >> lengths[i];
        if (lengths[i] > max_l) {
            max_l = lengths[i];
        }
    }

    // 홀수 길이는 올바른 괄호 문자열을 만들 수 없으므로, 최대 짝수 길이만 카탈란 수를 계산
    vector<long long> catalan = calculate_catalan(max_l / 2);

    // 각 테스트 케이스에 대해 답을 출력
    for (int i = 0; i < T; ++i) {
        int L = lengths[i];
        if (L % 2 == 1) {
            cout << 0 << '\n';  // 홀수 길이는 올바른 괄호 문자열이 없음
        }
        else {
            cout << catalan[L / 2] << '\n';  // 짝수 길이에 대해 카탈란 수 출력
        }
    }

    return 0;
}
