#include <iostream>
#define Max_size 10000001

typedef long long ll;

using namespace std;

bool arr[Max_size];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 소수 판정 배열 초기화
    fill(arr, arr + Max_size, true);

    // 소수 판정
    for (ll i = 2; i * i < Max_size; i++) {
        if (arr[i]) {
            for (ll j = i * i; j < Max_size; j += i) {
                arr[j] = false;
            }
        }
    }

    ll A, B;
    cin >> A >> B;

    int cnt = 0;

    for (ll i = 2; i < Max_size; i++) {
        if (arr[i]) { // 소수인 경우
            ll power = i * i;
            while (power <= B) {
                if (power >= A) cnt++;
                if (power > B / i) break; // 오버플로우 방지
                power *= i;
            }
        }
    }

    cout << cnt;

    return 0;
}
