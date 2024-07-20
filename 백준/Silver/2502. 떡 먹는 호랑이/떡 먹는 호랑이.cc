#include <iostream>
#include <vector>

using namespace std;

int main() {
    int D, K;
    cin >> D >> K;

    vector<int> fib(D + 1, 0);
    fib[1] = 1;
    fib[2] = 1;

    // 피보나치 수열 생성
    for (int i = 3; i <= D; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // a와 b 계산
    int a = fib[D - 2];
    int b = fib[D - 1];

    // A와 B를 찾기
    for (int A = 1; ; ++A) {
        if ((K - a * A) % b == 0) {
            int B = (K - a * A) / b;
            if (A <= B) {
                cout << A << endl;
                cout << B << endl;
                break;
            }
        }
    }

    return 0;
}
